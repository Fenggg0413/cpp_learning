#include<iostream>

bool fun(int val) //isPrime
{   
    if(val == 1)
        return false;
    for (int i = 2; i <= val / 2; ++i)
    {
        if(val % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int count{0};
    for (int i = 1; i <= 100; ++i)
    {
        if(fun(i))
        {
            std::cout << i << " ";
            ++count;
            if(count%5 == 0)
            {
                std::cout << '\n';
            }
        }
    }
    return 0;
}