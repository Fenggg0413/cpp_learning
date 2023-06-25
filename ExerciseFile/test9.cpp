#include <iostream> 
using namespace std;
int main()
{
    int n, fa, b;
    cout << "n=" << n << " fa=" << fa << " b=" << b << '\n';
    do
    {
        fa *= n;
        n++;
    } while (n <= 10);
    cout << "fa = " << fa << endl;
    return 0;
}