#include <iostream>
using std::cin;
using std::cout;
using std::endl;

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

int main()
{
    int tmp = myRandomInt(time(0), 0, 100);
    cout << tmp << endl;
    return 0;
}