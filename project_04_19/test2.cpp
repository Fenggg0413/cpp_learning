#include<iostream>
#include<string>
using namespace std;

void test1()
{
    string str = "0123456";
    string str2 = str.replace(1, 3, "hhhh");    //返回的是被替换后的字符串
    cout << str << "\n"
         << str2 << endl;
}

void test2()
{
    string str = "0123456";
    string substr = str.substr(1, 3);   //返回被截取的子串
    cout << substr << endl;
}
int main()
{
    //test1();
    test2();
    return 0;
}