#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<functional>

using namespace std::placeholders;

//14.34
class if_then_else
{
public:
    int operator()(bool a, const int &b, const int &c)
    {
        if(a)
            return b;
        else
            return c;
    }
};

//14.35
class PrintString
{
private:
    std::istream &is;

public:
    PrintString(std::istream &input = std::cin) : is(input) {}
    std::string operator()()
    {
        std::string str;
        std::getline(is, str);
        if(is)
        {
            return str;
        }
        return std::string();
    }
};

void test1()
{
    PrintString ps;
    std::vector<std::string> v;
    v.push_back(ps());
    v.push_back(ps());
    v.push_back(ps());
    v.push_back(ps());
    v.push_back(ps());
    for(auto i : v)
    {
        std::cout << i << '\n';
    }
    std::cout << std::endl;
}

class if_equal
{
private:
    int val;

public:
    if_equal(int v):val(v) {}
    bool operator() (int a)
    {
        return a == val;
    }
};

void test2()
{
    std::vector<int> v{3, 2, 1, 5, 3, 6, 3, 4, 8};
    for(auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    std::replace_if(v.begin(), v.end(), if_equal(3), 5);
    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

class if_size_equal
{
private:
    std::size_t i;

public:
    if_size_equal(std::size_t val): i(val) {}
    bool operator() (const std::string &s)
    {
        return s.size() == i;
    }
};

void test3()
{
    std::ifstream ifs("test.txt");
    if(!ifs.is_open())
    {
        std::cout << "Open file failed!" << std::endl;
        exit(-1);
    }
    std::string s;
    std::vector<std::string> v;
    while(ifs >> s)
        v.push_back(s);
    ifs.close();
}

bool check_size(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}
void elimDups(std::vector<std::string> &v)
{
    // 对给定的向量中的字符串进行按字符串大小排序，并删除重复的内容
    sort(v.begin(), v.end());
    auto end_iter = unique(v.begin(), v.end());
    v.erase(end_iter, v.end());
    stable_sort(v.begin(), v.end(), check_size);
}
class if_greater
{
private:
    int sz;

public:
    if_greater(int val = 0):sz(val) {}
    bool operator() (const std::string &s)
    {
        return s.size() > sz;
    }
};
void biggies(std::vector<std::string> &v, int sz)
{
    // 找到并打印所有长度大于给定sz的字符串
    elimDups(v);
    auto end_iter = find_if(v.begin(), v.end(), if_greater(sz));
    while (end_iter != v.end())
    {
        std::cout << *end_iter << std::endl;
        ++end_iter;
    }
}

//14.42
void test4()
{
    std::vector<int> v;
    std::srand(std::time(nullptr));
    for (int i = 0; i < 100; ++i)
        v.push_back(std::rand());
    std::cout << std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), _1, 1024)) << '\n';
}

int main()
{
    test4();
    return 0;
}