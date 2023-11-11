#include <iostream>
#include <new>
#include <cstdlib> /*malloc free*/
#include <stdexcept>
#include <typeinfo>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void *operator new(size_t size)
{
    //malloc分配失败会返回0
    if(void *mem = malloc(size))
        return mem;
    else
        throw std::bad_alloc();
}

void operator delete(void* mem)
{
    free(mem);
}

void test1()
{
    int *i = new int(5);
    cout << *i << endl;
}

class Base{
public:
    int x;
};

class Derived : public Base
{
public:
    int y;
};

void test2()
{
    int arr[10];
    Derived d;
    Base *p = &d;

    std::cout << typeid(42).name() << " "
              << typeid(42.0).name() << " "
              << typeid(arr).name() << " "
              << typeid(std::string).name() << " "
              << typeid(d).name() << " "
              << typeid(p).name() << " "
              << typeid(*p).name() << endl;
}

int main()
{
    test2();
    return 0;
}