#include "simple_routine.hpp"
#include "scheduler.hpp"
#include "util.hpp"
static Scheduler &getScheduler()
{
    static Scheduler sc;
    return sc;
}

void simple_start(TaskFunc task)
{
    Scheduler &sc = getScheduler();
    sc.addTask(task);
}
