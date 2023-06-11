
#include <map>
#include <string>
#include <functional>
#include <iostream>

void cala(const std::string &s, int a, int b)
{
    std::map<std::string, std::function<int(int, int)>> calcMap;
    calcMap.insert({"+", std::plus<int>()});
    calcMap.insert({"-", std::minus<int>()});
    calcMap.insert({"*", std::multiplies<int>()});
    calcMap.insert({"/", std::divides<int>()});
    if (s == "/" && b == 0)
    {
        std::cerr << "The divisor cannot be zero!" << std::endl;
    }
    else
        std::cout << calcMap[s](a, b) << std::endl;
}

void input()
{
    std::string calac;
    int a, b;
    while (true)
    {
        std::cin >> a >> calac >> b;
        if (calac == "+" || calac == "-" || calac == "*" || calac == "/")
            cala(calac, a, b);
        else
            std::cout << "Undefined calac" << std::endl;
    }
}

int main()
{
    input();
    return 0;
}