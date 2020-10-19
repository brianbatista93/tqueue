#include "utest.h"

#include "../tqueue.h"

UTEST(tqueue, push)
{
  tqueue<int, 32> queue;

  ASSERT_TRUE(queue.is_empty());

  ASSERT_TRUE(queue.push_back(29));

  ASSERT_FALSE(queue.is_empty());
  ASSERT_EQ(queue.size(), 1);

  ASSERT_TRUE(queue.push_back(7));
  ASSERT_EQ(queue.size(), 2);

  ASSERT_TRUE(queue.push_back(1993));
  ASSERT_EQ(queue.size(), 3);
}