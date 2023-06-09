#include"String.h"

#include<iostream>
#include<vector>

int main()
{
    char *ps = "hello world!";
    String s1(ps);
    std::vector<String> v;
    //扩展内存的时候调用移动构造函数
    v.push_back(s1);
    std::cout << v.capacity() << std::endl;
    v.push_back(s1);
    std::cout << v.capacity() << std::endl;
    v.push_back(s1);
    std::cout << v.capacity() << std::endl;
    v.push_back("hello world!");  //调用移动构造函数
    v.push_back(s1);
    return 0;
}