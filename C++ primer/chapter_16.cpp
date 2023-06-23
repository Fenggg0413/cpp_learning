#include<vector>
#include<list>
#include<string>
#include<iostream>

template<typename T>
int compare(const T &a, const T &b)
{
    if(a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

template<typename Iterator, typename Value>
Iterator myFind(Iterator beg, Iterator end, const Value &val)
{
    while(beg != end)
    {
        if(*beg == val)
            return beg;
        ++beg;
    }
    return end;
}

void test1()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::list<std::string> ls{"abc", "a", "bc"};
    auto temp = myFind(v.begin(), v.end(), 3);
    auto temp2 = myFind(v.begin(), v.end(), 10);
    std::cout << *temp << '\n'
              << *temp2;
}


int main()
{
    test1();
    return 0;
}