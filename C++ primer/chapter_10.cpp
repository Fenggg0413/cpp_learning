#include<iostream>
#include <iterator>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

// 练习10.1
void test1()
{
    vector<int> v = {0, 1, 2, 6, 4, 5, 6, 6, 8, 9};
    auto i = count(v.begin(), v.end(), 6);
    cout << i << endl;
}

// 10.2
void test2()
{
    list<string> l = {"hello", "2", "2"};
    auto i = count(l.begin(), l.end(), "2");
    cout << i << endl;
}

//10.6
void test3()
{
    vector<int> v(10, 100);
    fill_n(v.begin(), v.size(), 0);
}

//10.7
void test4()
{
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);
    auto iter = back_inserter(vec);
    copy(lst.cbegin(), lst.cend(), iter);
    for (auto a : vec)
        cout << a << " ";
    cout << endl;
}

//10.9
bool check_size(const string s1, const string s2)
{
    return s1.size() < s2.size();
}
void elimDups(vector<string> &v)
{
    //对给定的向量中的字符串进行按字符串大小排序，并删除重复的内容
    sort(v.begin(), v.end());
    auto end_iter = unique(v.begin(), v.end());
    v.erase(end_iter, v.end());
    stable_sort(v.begin(), v.end(), check_size);
}
void test5()
{
    vector<string> v = {"abc", "abc", "username", "hello", "world", "syntax"};
    elimDups(v);
}

//10.13
bool isGreaterFive(const string &s)
{
    return s.size() >= 5;
}
void test6()
{
    vector<string> v = {"abc", "abc", "username", "hello", "world", "syntax"};
    auto end_iter = partition(v.begin(), v.end(), isGreaterFive);
    for(auto beg = v.begin(); beg != end_iter; ++beg)
        cout << *beg << endl;
}

//10.14
void test7()
{
    auto f = [](int a, int b)
    { return a + b; };
    cout << f(2,2) << endl;
}

//10.15
void test8()
{
    int a = 0;
    cin >> a;
    auto f = [a](int b)
    { return a + b; };
    cout << f(5) << endl;
}

//10.16
void biggies(vector<string> v, int sz)
{
    //找到并打印所有长度大于给定sz的字符串
    elimDups(v);
    auto end_iter = find_if(v.begin(), v.end(),
                            [sz](const string &s)
                            {
                                return s.size() >= sz;
                            });
    while(end_iter != v.end())
    {
        cout << *end_iter << endl;
        ++end_iter;
    }
}
void test9()
{
    vector<string> v = {"abc", "abc", "username", "hello", "world", "syntax"};
    biggies(v, 4);
}

//10.18
void override_biggies(vector<string> v, int sz)
{
    auto iter = partition(v.begin(), v.end(),
                [sz](const string &s)
                { return s.size() >= sz; });
    for (auto beg = v.begin(); beg != iter; ++beg)
    {
        cout << *beg << endl;
    }
}
void test10()
{
    vector<string> v = {"abc", "abc", "username", "hello", "world", "syntax"};
    override_biggies(v, 5);
}

//10.22
#include<functional>
using namespace placeholders;
bool check_size_override(const string &s, int sz)
{
    return s.size() >= sz;
}
void find_override(vector<string> v, int sz)
{
    elimDups(v);
    auto iter = find_if(v.begin(), v.end(), bind(check_size_override, _1, sz));
    while(iter != v.end())
    {
        cout << *iter << endl;
        ++iter;
    }
}
void test11()
{
    vector<string> v = {"abc", "abc", "username", "hello", "world", "syntax"};
    find_override(v, 5);
}
void f(int a, int b, int c, int d)
{
    cout << "a: " << a << '\n'
         << "b: " << b << '\n'
         << "c: " << c << '\n'
         << "d: " << d << endl;
}
auto test12() -> void
{
    int a = 1, b = 2, c = 3, d = 4;
    auto g = bind(f, a, _2, c, _1);
    g(b,d);
}

//10.25
void bind_biggies(vector<string> v, int sz)
{
    auto eiter = partition(v.begin(), v.end(), bind(check_size_override, _1, sz));
    auto beg = v.begin();
    while (beg != eiter)
    {
        cout << *beg << endl;
        ++beg;
    }
    cout << endl;
    while(eiter != v.end())
    {
        cout << *eiter << endl;
        ++eiter;
    }
}
void test13()
{
    vector<string> v = {"abc", "abc", "username", "hello", "world", "syntax"};
    bind_biggies(v, 5);
}

//10.27
void test14()
{
    vector<string> v = {"abc", "abc", "username", "hello", "world", "syntax"};
    list<string> l;
    auto it = back_inserter(l);
    unique_copy(v.begin(), v.end(), it);
    for(auto i : l)
        cout << i << ' ';
    cout << endl;
}

//10.28
void test15()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lt1;
    list<int> lt2;
    list<int> lt3;
    auto iter1 = back_inserter(lt1);
    auto iter2 = front_inserter(lt2);
    auto iter3 = inserter(lt3,lt3.begin());
    copy(v.begin(), v.end(), iter1);
    copy(v.begin(), v.end(), iter2);
    copy(v.begin(), v.end(), iter3);
    for(auto i : lt1)   //123456789
        cout << i << ' ';
    cout << endl;
    for (auto i : lt2)  //987654321
        cout << i << ' ';
    cout << endl;
    for (auto i : lt3)  //123456789
        cout << i << ' ';
    cout << endl;
}

//10.29
#include<fstream>
void test16()
{
    ifstream ifs("test.txt");
    istream_iterator<string> in_iter(ifs), eof;
    vector<string> v;
    while(in_iter != eof)
    {
        v.push_back(*in_iter);
        ++in_iter;
    }
    for(auto i : v)
        cout << i << " ";
    cout << endl;
    ifs.close();
}

//10.30
void test17()
{
    istream_iterator<int> in_iter(cin),eof;
    ostream_iterator<int> out_iter(cout," ");
    vector<int> v(in_iter, eof);
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), out_iter);
}

//10.31
void test18()
{
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> v(in_iter, eof);
    sort(v.begin(), v.end());
    unique_copy(v.begin(), v.end(), out_iter);
}

//10.33
void operaFile(const string &ipFile, const string &opFile1, const string &opFile2)
{
    ifstream ifs(ipFile);
    if(!ifs.is_open())
    {
        cout << "error!" << endl;
        exit(-1);
    }
    istream_iterator<int> in_iter(ifs), eof;
    vector<int> v(in_iter, eof);
    ofstream ofs_odd(opFile1);
    ofstream ofs_even(opFile2);
    if(!ofs_odd.is_open() || !ofs_even.is_open())
    {
        cout << "error!" << endl;
        exit(-1);
    }
    ostream_iterator<int> outOdd_iter(ofs_odd, " ");
    ostream_iterator<int> outEven_iter(ofs_even, "\n");
    for(auto i : v)
    {
        if(i % 2) //odd
            outOdd_iter = i;
        else
            outEven_iter = i;
    }
    ifs.close();
    ofs_even.close();
    ofs_odd.close();
}
void createRandomInt(const string &s, size_t sz) //生成一个随机数文件
{
    ofstream ofs(s);
    if(!ofs.is_open())
        exit(-1);
    srand(time(nullptr));
    for (auto i = 0; i < sz; ++i)
    {
        ofs << rand() << " ";
    }
    ofs.close();
}
void test19()
{
    string s;
    size_t sz;
    cin >> s >> sz;
    createRandomInt(s, sz);
    operaFile(s, "testOdd.txt", "testEven.txt");
}

//10.34 and 10.35
void test20()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto rbeg = v.rbegin(); rbeg != v.rend(); ++rbeg) //reverse_iterator
    {
        cout << *rbeg << " ";
    }
    cout << endl;
    for (auto beg = v.end() - 1; beg != v.begin()-1; --beg) //普通iterator逆序打印
    {
        cout << *beg << " ";
    }
}

//10.37
void test21()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l;
    copy(v.crbegin() + 3, v.crend() - 3, back_inserter(l));
    for(auto i : l)
        cout << i << " ";
}
int main()
{
    test21();
    return 0;
}