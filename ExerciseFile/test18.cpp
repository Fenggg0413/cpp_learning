#include<iostream>
template<typename... T>
auto ave(T... t)
{
    return (t + ...) / sizeof...(t);
}

template <typename... Ts>
void magic(Ts... args)
{
    std::cout << sizeof...(args) << std::endl;
}

int main()
{
    magic(1);
    magic(" ", 2.3, 5);
}
