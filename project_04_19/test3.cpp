#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test()
{
    vector<int> v1; //默认构造
    for (int i = 0; i < 10;i++)
    {
        v1.push_back(i);    //利用尾插法将每次循环的i插入到vector中
    }
    print(v1);

    //利用区间来构造
    vector<int>v2 (v1.begin(), v1.end());
    print(v2);

    //n个num构造
    vector<int> v3(10, 100);
    print(v3);

    //拷贝构造
    vector<int> v4(v3);
    print(v4);
}

int main()
{
    test();
    return 0;
}