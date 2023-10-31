#include"swap.h"
#include<iostream>
using namespace std;

int main()
{
    int a = 3, b = 4;
    cout << "before swap: " << a << " " << b << endl;
    swap(a, b);
    cout << "after swap: " << a << " " << b << endl;
    return 0;
}