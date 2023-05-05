#include <ucontext.h>
#include "util.hpp"

class Executor;
class Soroutine
{
private:
    char *myStack;
    int size = 0;
    int alreadySize = 0;
    TaskFunc task;
    void *args;
    ucontext_t context;
    int status = ROUTINE_INIT;

public:
    Soroutine()
    {
    }

    Soroutine(TaskFunc task, void *args);

    Soroutine(TaskFunc task, void *args, int stackSize);

    ~Soroutine()
    {
        if (myStack)
        {
            delete[] myStack;
        }
    }

    void setStatus(int status)
    {
        this->status = status;
    }

    void setTask(TaskFunc task, void *args)
    {
        this->task = task;
        this->args = args;
    }

    void setStack(int newSize)
    {
        if (this->myStack && alreadySize > 0 && newSize == 0)
        {
            delete[] myStack;
            this->size = 0;
            alreadySize = 0;
        }
        else if (this->myStack && alreadySize > 0 && alreadySize != newSize)
        {
            delete[] myStack;
            myStack = new char[newSize];
            alreadySize = newSize;
            this->size = 0;
        }
    }

    int getSize()
    {
        return size;
    }

    int getStackSize()
    {
        return alreadySize;
    }

    TaskFunc getTask()
    {
        return task;
    }

    void *getArgs()
    {
        return args;
    }

    ucontext_t &getContext()
    {
        return context;
    }
};