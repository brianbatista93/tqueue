#pragma once

#include <atomic>

namespace internal {
class spinlock
{
public:
  void lock()
  {
    while (!try_lock()) {
    }
  }
  bool try_lock() { return !lck.test_and_set(std::memory_order_acquire); }

  void unlock() { lck.clear(std::memory_order_release); }

private:
  std::atomic_flag lck = ATOMIC_FLAG_INIT;
};
}

template<class T, unsigned CAPACITY>
class ring_queue
{
public:
  ring_queue()
    : m_head(0)
    , m_tail(0)
  {}

  bool push_back(const T& val)
  {
    bool result = false;
    lock.lock();
    size_t next = (m_head + 1) % CAPACITY;
    if (next != m_tail) {
      m_data[m_head] = val;
      m_head = next;
      result = true;
    }
    lock.unlock();
    return result;
  }

  bool pop_front(T& val)
  {
    bool result = false;
    lock.lock();
    if (m_tail != m_head) {
      val = m_data[m_tail];
      m_tail = (m_tail + 1) % CAPACITY;
      result = true;
    }
    lock.unlock();
    return result;
  }

  bool is_empty() const { return m_head == m_tail; }

  size_t size() const { return m_head - m_tail; }

private:
  T m_data[CAPACITY];
  size_t m_head;
  size_t m_tail;
  internal::spinlock lock;
};