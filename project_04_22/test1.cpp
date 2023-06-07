#include<list>
#include<string>
#include<iostream>
#include<set>
using namespace std;

void test1()
{
    list<int> l;
    l.sort();
}

void test2()
{
    set<int> s;     
    //insert插入会返回bool值，如果插入成功则返回true，否则返回false
    s.insert(10);
    s.insert(10);   //set容器不允许存在相同的元素，该操作插入失败，但是编译器不会报错
    s.insert(30);
    s.insert(40);
    s.insert(20);
    cout<<s.size()<< endl;
}

int main()
{
    test2();
    return 0;
}