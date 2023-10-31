#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
#include <string>
using std::string;

#include <regex>
using std::regex;
using std::regex_error;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

void test1()
{
    // for ex17.14
    // error_brack
    try
    {
        regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
    }
    catch (regex_error e)
    {
        cout << e.what() << " code: " << e.code() << endl;
    }
}

void test2()
{
    // for ex17.15
    regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);
    string s;
    cout << "Please input a word! Input 'q' to quit!" << endl;
    while (cin >> s && s != "q")
    {
        if (std::regex_match(s, r))
            cout << "Input word " << s << " is okay!" << endl;
        else
            cout << "Input word " << s << " is not okay!" << endl;

        cout << "Please input a word! Input 'q' to quit!" << endl;
    }
}

unsigned int myRandomInt(int s, size_t min, size_t max)
{
    default_random_engine e;
    e.seed(s);
    uniform_int_distribution<unsigned int> u(min, max);
    return u(e);
}

void test3()
{
    std::ifstream ifs("temp.txt");
    if (ifs)
        cout << 1 << endl;
    char sink[30];
    while (ifs.getline(sink, 30))
        cout << sink << endl;
    ifs.close();
}

void test4()
{
    // 以可读写方式打开文件并已开始就定位到文件尾
    std::fstream fs("temp", std::fstream::in | std::fstream::out | std::fstream::ate);
    if (!fs)
    {
        cout << "open file failed" << endl;
        return;
    }
    // 记录原本文件尾的位置
    auto end_mark = fs.tellg();
    // 将流重定位到文件开头
    fs.seekg(0, std::fstream::beg);
    string line;
    int count = 0;
    bool flag = true;
    while (fs && fs.tellg() != end_mark && getline(fs, line))
    {
        count += line.size() + 1; // 记得加上换行符
        auto mark = fs.tellg();
        fs.seekp(0, std::fstream::end);
        if(flag)
        {
            fs << endl;
            flag = false;
        }
        fs << count;
        if(mark != end_mark)
            fs << " ";
        fs.seekg(mark);
    }
    fs.seekp(0, std::fstream::end);
    fs << endl;
    fs.close();
}

int main()
{
    test4();
    return 0;
}