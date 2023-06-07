#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<fstream>
#include<cctype>
#include<string>
#include<utility>
#include<vector>
#include<list>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//11.3
void test1()
{
    map<string, size_t> words_count;
    string word;
    size_t count;
    ifstream ifs("test.txt");
    if(!ifs.is_open())
        exit(-1);
    while(ifs>>word)
    {
        ++words_count[word];
    }
    for(auto &i : words_count)
    {
        cout << i.first << " occurs " << i.second
             << ((i.second > 1) ? " times" : " time") << endl;
    }
    ifs.close();
}

//11.4
void test2()
{
    map<string, size_t> words_count;
    string word;
    size_t count;
    ifstream ifs("test.txt");
    if (!ifs.is_open())
        exit(-1);
    while (ifs >> word)
    {
        for(auto &c : word) //将所有大写转变为小写
        {
            c = tolower(c);
        }
        // remove_if移除使ispunct为真的情况，即移除所有字符，但并非真正的移除，remove_if会将符合条件的元素移到容器靠后的位置，然后返回指向该位置第一个元素的迭代器
        //因此remove_if通常伴随使用erase来删除符合条件的字符
        word.erase(remove_if(word.begin(), word.end(), ::ispunct),word.end());  //::表明ispunct是属于c语言的命名空间的
        ++words_count[word];
    }
    for(const auto &i : words_count)
    {
        cout << i.first << "\toccurs " << i.second
             << ((i.second > 1) ? " times" : " time") << endl;
    }
    ifs.close();
}

//11.7
void ftest3()
{
    map<string, vector<string>> m;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
            m[ln].push_back(cn);
}

//11.9
void test3()
{
    list<int> li;
    map<string, list<int>> wordLine;
}

//11.12
void test4()
{
    pair<string, int> p;
    int a;
    string s;
    vector<decltype(p)> v;
    while(cin >> s >> a)
    {
        p.first = s;
        p.second = a;
        v.push_back(p);
    }
    for(auto i : v)
    {
        cout << i.first << " " << i.second << '\n';
    }
    cout << endl;
}

//11.13
void test5()
{
    int a;
    string s;
    vector<pair<string,int>> v;
    while (cin >> s >> a)
    {
        pair<string, int> p(s, a);
        v.push_back(p);
    }
    for (auto i : v)
    {
        cout << i.first << " " << i.second << '\n';
    }
    cout << endl;
}
void test6()
{
    int a;
    string s;
    vector<pair<string, int>> v;
    while (cin >> s >> a)
    {
        v.push_back({s,a}); //1
        v.push_back(make_pair(s, a)); //2
        v.push_back(pair<string, int>(s, a)); //3
    }
    for (auto i : v)
    {
        cout << i.first << " " << i.second << '\n';
    }
    cout << endl;
}

//11.14
void test7()
{
    vector<pair<string, string>> v;
    map<string, decltype(v)> m;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "eof";)
    {
        string name, d;
        while (cin >> name >> d)
        {
            if(name == "eof" && d == "eof")
                break;
            m[ln].push_back({name, d});
        }
    }
    for(auto i : m)
    {
        cout << "Last name: " << i.first << '\n';
        for(auto j : i.second)
            cout << "Children's name: " << j.first << "\t"
                 << "Children's birthday: " << j.second << '\n';
    }
    cout << endl;
}

//11.15
void test8()
{
    map<string, int> m{{"hello", 1}, {"world", 2}};
    for (auto beg = m.begin(); beg != m.end(); ++beg)
    {
        cout << "value: " << '\n';
        cin >> beg ->second;
    }
    cout << endl;
    for(auto i : m)
    {
        cout << i.first << " " << i.second << '\n';
    }
    cout << endl;
}

//11.20
void test9()
{
    map<string, size_t> words_count;
    string word;
    size_t count;
    ifstream ifs("test.txt");
    if (!ifs.is_open())
        exit(-1);
    while (ifs >> word)
    {
        for (auto &c : word) 
        {
            c = tolower(c);
        }
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        auto ret = words_count.insert({word, 1});
        if(!ret.second)
            ++ret.first->second;
    }
    for (const auto &i : words_count)
    {
        cout << i.first << "\toccurs " << i.second
             << ((i.second > 1) ? " times" : " time") << endl;
    }
    ifs.close();
}

//11.23
void test10()
{
    multimap<string, vector<string>> m;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
    {
        string name;
        vector<string> v;
        while(cin >> name && name != "@q")
        {
            v.push_back(name);
        }
        m.insert({ln, v});
    }
    for (auto i : m)
    {
        cout << "Last name: " << i.first << '\n';
        for (auto j : i.second)
            cout << "Children's name: " << j << '\n';
    }
    cout << endl;
}

//11.28
void test11()
{
    map<string, vector<int>> m{{"hello",{10,20,30}}};
    map<string,vector<int>>::iterator iter = m.find("hello");
    iter->second.push_back(500);
    for(auto i : m)
    {
        for(auto j : i.second)
            cout << j << " ";
    }
    cout << endl;
}

//11.31
void test12()
{
    multimap<string, string> multim;
    multim.insert({"abc", "book1"});
    multim.insert({"abc", "book2"});
    multim.insert({"abc", "book3"});
    multim.insert({"abc", "book4"});
    multim.insert({"abc", "book5"});
    multim.insert({"aaa", "book1"});
    multim.insert({"adc", "book1"});
    // multim.erase(multim.lower_bound("abc"),multim.upper_bound("abc"));
    auto bpair = multim.equal_range("abc");
    multim.erase(bpair.first, bpair.second);
    for (auto i : multim)
        cout << i.first << " " << i.second << '\n';
    cout << endl;
}

//11.33
void get_rule(ifstream &rule, map<string,string> &ruleMap) 
{
    string line;
    string word;
    while(rule >> word && getline(rule, line))
    {
        if(line.size() > 1)
            ruleMap[word] = line.substr(1);
        else
            cout << "no rule for " << word << '\n';
    }
}   
void word_transform(ifstream &rule, ifstream &input)
{
    map<string, string> ruleMap;
    get_rule(rule, ruleMap); //建立起转换map
    string word;
    string line;
    while(getline(input, line))
    {
        istringstream temp(line);
        while(temp >> word)
        {
            if(ruleMap.find(word) != ruleMap.end())
            {
                cout << ruleMap[word] << " ";
            }
            else
                cout << word << " ";
        }
        cout << endl;
    }
}
void test13()
{
    ifstream rule("rule.txt");
    ifstream input("input.txt");
    if(!rule.is_open() || !input.is_open())
    {
        cout << "file opened fail!" << endl;
        system("pause");
        exit(-1);
    }
    word_transform(rule, input);
    rule.close();
    input.close();
}

//11.38
void test14()
{
    unordered_map<string, size_t> words_count;
    string word;
    size_t count;
    ifstream ifs("test.txt");
    if (!ifs.is_open())
        exit(-1);
    while (ifs >> word)
    {
        for (auto &c : word)
        {
            c = tolower(c);
        }
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        auto ret = words_count.insert({word, 1});
        if (!ret.second) //单词已经存在
            ++ret.first->second;
    }
    for(auto i : words_count)
    {
        cout << i.first << " occurs " << i.second
             << ((i.second > 1)
            ? " times"
            : " time") << '\n';
    }
    cout << endl;
}
int main()
{
    test9();
    test14();
    return 0;
}