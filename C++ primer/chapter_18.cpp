#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>

using namespace std;

void test1()
{
    try
    {
        /* code */
    }
    catch(overflow_error &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch(underflow_error &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch(range_error &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch(domain_error &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch(length_error &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch(bad_cast &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch(bad_alloc &e)
    {
        cout << e.what() << endl;
        abort();
    }
}

void test2()
{
    random_device seed;
    mt19937 gen(seed());
    uniform_int_distribution<unsigned> dis(0, 9);
    cout << dis(gen) << endl;
}

// 命名空间别名
namespace sd = std;
int main()
{
    test2();
    return 0;
}