#include <thread>
#include <iostream>

void func()
{
    std::cout << "hello thread" << std::endl;
    std::cout << "hello thread" << std::endl;
    std::cout << "hello thread" << std::endl;
    std::cout << "hello thread" << std::endl;
    std::cout << "hello thread" << std::endl;
    std::cout << "hello thread" << std::endl;
}

int main()
{
    std::thread my_thread{func};
    std::cout << "hello world" << std::endl;
    std::cout << "hello world" << std::endl;
    std::cout << "hello world" << std::endl;
    std::cout << "hello world" << std::endl;
    std::cout << "hello world" << std::endl;
    std::cout << "hello world" << std::endl;
    my_thread.join();
    return 0;
}