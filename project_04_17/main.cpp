#include "MyArray.hpp"
#include <iostream>
#include <string.h>
using namespace std;

void test()
{
    MyArray<int> p1(5);
    for (int i = 0; i < p1.getCapacity(); i++)
    {
        p1.pushBack(i);
    }
    p1.showArray();
    p1.popBack();
    p1.showArray();
}

int main()
{
    test();
    return 0;
}