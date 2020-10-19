# tqueue

[![Build status](https://ci.appveyor.com/api/projects/status/4w7hmmm22xarmj7f/branch/main?svg=true)](https://ci.appveyor.com/project/brianbatista93/tqueue/branch/main)
[![Build Status](https://travis-ci.org/brianbatista93/tqueue.svg?branch=main)](https://travis-ci.org/brianbatista93/tqueue)


Simple C++ single header thread-safe queues implementation

## Usage

Just insert `#include "tqueue.h"` in your code and be happy.

## Ring Queue

As the name implies it is a circular queue with a head and tail.

```cpp
ring_queue<int, 32> rqueue;

// Pushing values
rqueue.push_back(29);
rqueue.push_back(7);
rqueue.push_back(1993);

// Looping through values
int value;
while (rqueue.pop_front(value)) {
printf("Value[%d]: %d\n", (rqueue.tail() - 1), value);
}
```