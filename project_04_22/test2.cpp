#include<iostream>
using namespace std;

void move(char *a, size_t n, size_t val)
{
    for (int i = 0; i < n; ++i)
    {
        int temp = a[0];
        for (int j = 1; j < val; ++j)
        {
            a[j - 1] = a[j];
        }
        a[val - 1] = temp;
    }
}

int main()
{
    char a[5] = {'c', 'h', 'i', 'n', 'a'};
    for(auto i : a)
        std::cout << i << " ";
    std::cout << '\n';
    move(a, 3, 5);
    for (auto i : a)
        std::cout << i << " ";
    std::cout << '\n';
    return 0;
}