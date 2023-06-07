#include<iostream>
#include<vector>

void test01()
{
    std::cout << "2\t\115\n";
}

void test02()
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    const auto f = ci;
    auto &g = ci;
    std::cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d << " e=" << e << " f=" << f << " g=" << g << std::endl;
    a = 42;
    b = 42;
    c = 42;
    std::cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d << " e=" << e << " f=" << f << " g=" << g << std::endl;
}

using std::string;
using std::vector;

//练习3.17
void test03()
{
    string str;
    vector<string> v;
    while(std::cin>>str)
    {
        if(str == "0")
            break;
        v.push_back(str);
    }
    for (auto &i : v)
        for(auto &c : i)
            c = toupper(c);
    for(auto &i : v)
        std::cout << i << std::endl;
}

//练习3.19
void test04()
{
    vector<int> v1(10, 42);
    vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> v3;
    for (int i = 0; i < 10; ++i)
    {
        v3.push_back(42);
    }
    //明显第一种方式定义10个元素值都为42的vector对象更好
}

//练习3.20
void test05()
{
    vector<int> v;
    int temp;
    while(std::cin>>temp)
    {
        v.push_back(temp);
    }
    // for (int i = 1; i < v.size(); ++i)
    // {
    //     int sum = v[i] + v[i-1];
    //     std::cout << sum << std::endl;
    // }
    for (int begin = 0, end = v.size() - 1; begin <= end; begin++, end--)
    {
        auto sum = v[begin] + v[end];
        std::cout << sum << std::endl;
    }
}

//练习3.22
void test06()
{
    string str;
    vector<string> text;
    while(std::cin>>str)
    {
        text.push_back(str);
    }
    for (auto it = text.begin(); it != text.end(); ++it)
    {
        if(it == text.begin())
        {
            for(auto &c : *it)
                c = toupper(c);
        }
        std::cout << *it << std::endl;
    }
}

//练习3.23
void test07()
{
    vector<int> v(10, 10);
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        (*it) *= 2;
    }
    for (auto it : v)
    {
        std::cout << it << std::endl;
    }
}


//练习3.25
void test08()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while(std::cin>>grade)
    {
        if(grade<=100)
            ++*(scores.begin() + (grade / 10));
    }
    for(auto it : scores)
        std::cout << it << std::endl;
}

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
//练习3.41
void test09()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v(begin(arr), end(arr));
    for(auto i : v)
        cout << i << " ";
    cout << endl;
}

//练习3.42
void test10()
{
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr[10];
    for (int i = 0; i != v.size(); ++i)
    {
        arr[i] = v[i];
    }
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
}

//练习3.43
void test11()
{
    int arr[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
    //使用范围for循环遍历
    for (const int (&row)[4]: arr)
        for(int col : row)
            cout << col << " ";
    cout << endl;
    //使用普通for循环遍历
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 4; ++j)
            cout << arr[i][j] << " ";
    cout << endl;
    //使用指针for遍历
    // int(*row)[4] = arr;
    // for (row = arr; row != arr + 3; ++row)
    //     for (int *col = *row; col != *row + 4; ++col) //p的解引用*p是一个包含4个int类型的数组
    //         cout << *col << " ";
    // cout << endl;
    for (int(*row)[4] = arr; row != arr + 3; ++row)
        for (int *col = *row; col != *row + 4; ++col)
            cout << *col << " ";
    cout << endl;
}

//练习3.44
void test12()
{
    using int_array = int[4]; // 程序将类型“4个整数组成的数组”命名为int_array
    int arr[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    //range for
    for(const int_array &row : arr)
        for(int col : row)
            cout << col << " ";
    cout << endl;
    //index for loop
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 4; ++j)
            cout << arr[i][j] << " ";
    cout << endl;
    //pointer for loop
    for (int_array *row = arr; row != arr + 3; ++row)
        for (int *col = *row; col != *row + 4; ++col)
            cout << *col<<" ";
    cout << endl;
}

//练习3.45
void test13()
{
    int arr[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    //range for
    for(auto &row : arr)
        for(auto col : row)
            cout << col << " ";
    cout << endl;
    //index for loop
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 4; ++j)
            cout << arr[i][j] << " ";
    cout << endl;
    //pointer fo loop
    for (auto row = arr; row != end(arr); ++row)
        for (auto col = *row; col != end(*row); ++col)
            cout << *col << " ";
    cout << endl;
}

//异常处理
#include<stdexcept> /*runtime_error*/
using std::runtime_error;
void test14()
{   
    //要求输入两个数，其中a必须大于b，异常处理try语句的基本流程如下
    int a, b;
    while(cin>>a>>b)
    {
        try{
            if(a<=b){
                throw runtime_error("a must greater b!");
            }else{
                cout << "a - b > 0" << endl;
            }
        }catch(runtime_error err){
            //提示用户输入的a小于或等于b,询问是否重新输入
            cout<<err.what()<<endl;
            cout << "Try Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if(!cin||c=='n')
                break;  //如果输入了n，则跳出while循环
        }
    }
}

//5.6.3练习
void test15()
{
    int a, b;
    while(cin>>a>>b)
    {
        try
        {
            if (b == 0)
            {
                throw runtime_error("b can not equal to zero!");
            }
            else
            {
                cout << a / b << endl;
            }
        }
        catch (runtime_error err)
        {
            cout << err.what()
                 << "\nTry Again? Entry y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
}

//6.21练习
int return_greater(const int a,const int *b)
{
    if(a > *b)
    {
        return a;
    }
    return *b;
}
void test16()
{
    int a = 6;
    cout << return_greater(7, &a);
}

//6.22练习
void swap_Intpointer(int* &a, int* &b)  //绑定指针的引用
{
    int *temp = a;
    a = b;
    b = temp;
}
void test17()
{
    int a = 5, b = 6;
    int *p1 = &a, *p2 = &b;
    cout << p1 << '\n'
         << p2 << endl;
    swap_Intpointer(p1, p2);
    cout << p1 << "\n"
         << p2 << endl;
}

//6.27练习
#include<initializer_list>
using std::initializer_list;
int calcSum(initializer_list<int> il)
{
    int sum = 0;
    for(const auto &i : il)
    {
        sum += i;
    }
    return sum;
}
void test18()
{
    cout << calcSum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10})<< endl;
}

//练习6.44
inline bool is_shorter(const string &lft, const string &rht)
{
    return lft.size() < rht.size();
}

//练习6.54-6.56
int func(int, int);
int add_func(int a, int b)
{
    return a + b;
}
int sub_func(int a, int b)
{
    return a - b;
}
int mult_func(int a, int b)
{
    return a * b;
}
int dev_func(int a, int b)
{
    return b != 0 ?a / b : 0;
}
void test19()
{
    vector<decltype(func)*> v;
    v.push_back(add_func);
    v.push_back(sub_func);
    v.push_back(mult_func);
    v.push_back(dev_func);
    for(auto i : v)
    {
        cout << i(2, 2) << endl;
    }
}

//练习8.1
using std::istream;
using std::ostream;
istream& IO_read_1(istream& is)
{
    char c;
    while(!is.eof())
    {
        is >> c;
        cout << c;
    }
    is.clear();
    return is;
}
void test20()
{
    IO_read_1(cin);
}

//练习8.9
#include<sstream>
using std::istringstream;
using std::ostringstream;
istream &IO_read_2(istream &is)
{
    string str;
    while (getline(cin,str))
    {
        istringstream record(str);
        string word;
        while(record >> word)
            cout << word<< endl;
    }
    is.clear();
    return is;
}
void test21()
{
    IO_read_2(cin);
}

//练习8.10
#include<fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;
void test22()
{
    vector<string> v;
    ifstream ifs("test.txt");
    string str;
    while(ifs >> str)
        v.push_back(str);
    for(const auto i : v)
    {
        istringstream record(i);
        char c;
        while(record >> c)
            cout << " " << c;
        cout << endl;
    }
}

//练习9.2
#include<deque>
#include<list>
using std::deque;
using std::list;
void test23()
{
    list<deque<int>> ls;
}

//练习9.4
bool is_find(vector<int>::iterator begin, vector<int>::iterator end, int val)
{
    while(begin!=end)
    {
        if(*begin == val)
            return true;
        ++begin;
    }
    return false;
}

//练习9.5
vector<int>::iterator new_is_find(vector<int>::iterator begin, vector<int>::iterator end, int val)
{
    while(begin!=end)
    {
        if(*begin==val)
            return begin;
        ++begin;
    }
    cout << "do not find the val" << endl;
    return end;
}

//练习9.13
void test24()
{
    list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> v1(l.begin(), l.end());
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> v2(v.begin(),v.end());
}

//练习9.18
void test25()
{
    deque<string> dq;
    string str;
    while(cin>>str)
        dq.push_back(str);
    for (auto beg = dq.begin(); beg != dq.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

//练习9.20
void test26()
{
    list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> d1;
    deque<int> d2;
    for(auto i : l)
    {
        if(i % 2)   //odd
        {
            d2.push_back(i);
        }
        else    //even
        {
            d1.push_back(i);
        }
    }
    for(auto i : d1)
    {
        cout << i << " ";
    }
    cout << endl;
    for(auto i : d2)
    {
        cout << i << " ";
    }
    cout << endl;
}

//练习9.24
void test27()
{
    vector<int> v(10, 1);
    int a = *v.begin();
    int b = v.at(0);
    int c = v[0];
    int d = v.front();
    vector<int> vi;
    vi.push_back(a);
    vi.push_back(b);
    vi.push_back(c);
    vi.push_back(d);
    for(auto i : vi)
    {
        cout << i << " ";
    }
    cout << endl;
}

//练习9.26
void test28()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v;
    list<int> l;
    for(auto i : ia)
    {
        v.push_back(i);
        l.push_back(i);
    }
    auto vbeg = v.begin();
    auto lbeg = l.begin();
    while(vbeg!=v.end())
    {
        if(!((*vbeg)%2))
        {
            vbeg = v.erase(vbeg);
        }
        else
            ++vbeg;
    }
    while(lbeg!=l.end())
    {
        if(*lbeg%2)
        {
            lbeg = l.erase(lbeg);
        }
        else
            ++lbeg;
    }
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    for(auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}

//练习9.27
#include<forward_list>
using std::forward_list;
void test29()
{
    forward_list<int> fl = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto befor_beg = fl.before_begin();
    auto beg = fl.begin();
    while(beg!=fl.end())
    {
        if(*beg % 2)
        {
            beg = fl.erase_after(befor_beg);
        }
        else
        {
            befor_beg = beg;
            ++beg;
        }
    }
    for(auto i : fl)
    {
        cout << i << " ";
    }
    cout << endl;
}

//练习9.28
void push_list(forward_list<string> &li, const string &target_str, const string &push_str)
{
    auto before_beg = li.before_begin();
    auto beg = li.begin();
    while(beg != li.end())
    {
        if(*beg == target_str)
        {
            beg = li.insert_after(beg, push_str);
            return;
        }
        else
        {
            before_beg = beg;
            ++beg;
        }
    }
    li.insert_after(before_beg, push_str);
}
void test30()
{
    forward_list<string> fl = {"abc", "hello", "world"};
    push_list(fl, "hello", "c++");
    for(auto i : fl)
        cout << i << " ";
    cout << endl;
}

//练习9.41
void test31()
{
    vector<char> v = {'a', 'b', 'c', 'd'};
    string s(v.begin(),v.end());
}

//练习9.42
void test32()
{
    string s;
    s.reserve(100);
    //用reserve预先分配100个容量，避免在读取的时候进行扩容操作，即可提升性能
}

//练习9.47
void test33()
{
    string s("ab2c3d7R4E6");
    string number = "0123456789";
    string::size_type pos = 0;
    while((pos = s.find_first_of(number,pos)) != string::npos)
    {
        cout << "the number is " << s[pos] << endl;
        ++pos;
    }
    cout << endl;
    pos = 0;
    while((pos = s.find_first_not_of(number,pos)) != string::npos)
    {
        cout << "the char is " << s[pos] << endl;
        ++pos;
    }
    cout << endl;
}

//练习9.49
void test34()
{
    string descender = "qypdgj"; //下出头
    string ascender = "tdfhklb"; //上出头
    ifstream ifs("test.txt");
    if(!ifs.is_open())
    {
        cout << "error!" << endl;
        exit(-1);
    }
    string temp;
    vector<string> v;
    while(ifs >> temp)
    {
        v.push_back(temp);
    }
    ifs.close();    //将文件中的单词都读出后，关闭该文件
    for(auto &i : v) //将大写转为小写
    {
        for(auto &j : i)
        {
            if(j >= 'A' && j <= 'Z')
            {
                j = tolower(j);
            }
        }
    }
    vector<string> vt;
    for(auto i : v)
    {
        if((i.find_first_of(ascender) == string::npos) && (i.find_first_of(descender) == string::npos))
            vt.push_back(i);
    }
    string maxsize_word(vt[0]);
    for(auto i : vt)
    {
        if(maxsize_word.size() < i.size())
            maxsize_word.assign(i);
    }
    cout << maxsize_word << endl;
}

//练习9.50
using std::stoi;
using std::stod;
void test35()
{
    vector<string> vint = {"1","2","3","4","5"};
    vector<string> vdouble = {"1.1","2.4","3.1","4.5","5.79"};
    int int_sum = 0;
    double double_sum = 0;
    for(auto i : vint)
    {
        int temp = stoi(i);
        int_sum += temp;
    }
    cout << int_sum << endl;
    for(auto i : vdouble)
    {
        double temp = stod(i);
        double_sum += temp;
    }
    cout << double_sum << endl;
}

//练习9.51
//TODO:写完这题
void test36()
{
    class Date
    {
        private:
            int year;
            int month;
            int day;
        public:
            Date() = default;
            Date(const string &s)
            {
                string::size_type pos = 0;
                string::size_type ppos = 0;
                string num = "123456789";
                pos = s.find_first_not_of(num);
                ppos = s.find_first_of(num);
            }
    };
}

//TODO:9.52
int main()
{
    //test01();
    //test03();
    // test11();
    // test12();
    // test13();
    // test17();
    test36();
    return 0;
}
