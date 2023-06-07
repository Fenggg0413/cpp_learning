#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void func(int val);
void test()
{
    vector<int> v; //创建一个容器v

    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin();//指向容器第一个数据
    vector<int>::iterator itEnd = v.end();//指向容器最后一个数据的下一个

    //第一种遍历方式
    while(itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }

    //第二种遍历方式
    for (vector<int>::iterator its = v.begin(); its != v.end();its++)
    {
        cout << *its << endl;
    }

    //第三种遍历方式(需要包含算法头文件algorithm)
    for_each(v.begin(), v.end(), func);
    //for_each算法参数列表为：开始位置，结束位置，执行的函数名
}
void func(int val)
{
    cout << val << endl;
}