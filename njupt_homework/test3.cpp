#include<iostream>

template<typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


template <class T1, class T2>
void sum(T1 x, T2 y)
{
    std::cout << sizeof(x + y);
}
int main()
{
    int a = 10;
    double b = 100;
    char c = '1';
    sum('1', 99.0);
    return 0;
}