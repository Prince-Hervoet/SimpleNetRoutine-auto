#include <iostream>
#include "simple_routine.hpp"

void test(void *args)
{
    std::cout << "asdf" << std::endl;
}

int main()
{
    simple_start(test, nullptr);
}