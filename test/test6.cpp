#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    std::cout << fixed;
    float f1 = 1.0f;
    std::cout << "f1 = " << f1 << endl;
    float a = 0.1f;
    float f2 = a + a + a + a + a + a + a + a + a + a;
    std::cout << "f2 = " << f2 << endl;
    std::cout << fixed << std::setprecision(15) << f1 << '\n';
    std::cout << fixed << std::setprecision(15) << f2 << '\n';
    if (f1 == f2)
        cout << "f1 = f2" << endl;
    else
        cout << "f1 != f2" << endl;
    return 0;
}