#ifdef WIN32
#include <Windows.h>
#endif // WIN32
#include "utest.h"

#include "../tqueue.h"

static ring_queue<int, 4> queue;

UTEST(ring_queue, push)
{

  ASSERT_TRUE(queue.is_empty());

  ASSERT_TRUE(queue.push_back(29));

  ASSERT_FALSE(queue.is_empty());
  ASSERT_EQ(1, queue.size());

  ASSERT_TRUE(queue.push_back(7));
  ASSERT_EQ(2, queue.size());

  ASSERT_TRUE(queue.push_back(1993));
  ASSERT_EQ(3, queue.size());

  ASSERT_FALSE(queue.push_back(404));
}

UTEST(ring_queue, pop)
{
  ASSERT_FALSE(queue.is_empty());

  int result;
  ASSERT_TRUE(queue.pop_front(result));
  ASSERT_EQ(29, result);
  ASSERT_EQ(2, queue.size());

  ASSERT_TRUE(queue.pop_front(result));
  ASSERT_EQ(7, result);
  ASSERT_EQ(1, queue.size());

  ASSERT_TRUE(queue.pop_front(result));
  ASSERT_EQ(1993, result);
  ASSERT_TRUE(queue.is_empty());
}