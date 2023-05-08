#ifndef __CONTEXTPOOL_H__
#define __CONTEXTPOOL_H__

#include <mutex>
#include <queue>
#include <vector>
#include "soroutine.hpp"
#include "single_list_queue.hpp"

#define DEFAULT_CAPACILITY 512
#define MAX_CAPACITY 16384

class BufferPool
{
private:
    int capacity = DEFAULT_CAPACILITY; // the capacity of pool
    int remainSize = DEFAULT_CAPACILITY;
    std::queue<Soroutine *> qu;
    std::mutex mu;

public:
    BufferPool(int size);
    BufferPool();
    ~BufferPool();
    Soroutine *getRoutine();
    bool giveback(Soroutine *back);
    bool changeCapacity(int num);

    inline int getRemainSize()
    {
        return remainSize;
    }

    inline bool poolIsEmpty()
    {
        return !(remainSize > 0);
    }

    inline bool poolIsFull()
    {
        return remainSize == capacity;
    }
};

#endif