#include <iostream>
#include <new>
#include <cstdlib> /*malloc free*/
#include <stdexcept>

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

int main()
{
    test1();
    return 0;
}