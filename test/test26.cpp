#include<iomanip>
#include<iostream>

using namespace std;

int main()
{
    cout << "precision: " << cout.precision() << ", value: " << sqrt(2.0);
    cout.precision(4);
    cout << "\nprecision: " << cout.precision() << ", value: " << sqrt(2.0);
    cout << setprecision(9);
    cout << "\nprecision: " << cout.precision() << ", value: " << sqrt(2.0);
    cout << "\n--------------------------------" << endl;
    cout << "default: " << 100 * sqrt(2.0);
    cout << "\nscientific: " << scientific << 100 * sqrt(2.0);
    cout << "\nfixed: " << fixed << 100 * sqrt(2.0);
    cout << "\nhexadecimal: " << hexfloat << 100 * sqrt(2.0) << defaultfloat;
    cout << "\n--------------------------------" << endl;
    cout << "after boolalpha: print bool " << boolalpha << true << false << endl;
    cout << "normal print bool " << noboolalpha << true << false << endl;
    cout << "after showbase: " << showbase << hex << 100 << endl << noshowbase;
    cout << "after showpoint: " << showpoint << 2.0 << endl
         << noshowpoint;
    cout << "normal: " << 2.0 << endl;
    cout << "after showpos: " << showpos << 20 << endl;
    cout << "normal: " << noshowpos << 20 << endl;
    cout << "--------------------------------" << endl;
    cout << setw(16) << sqrt(2.0) << endl;
    cout << left << setw(16) << sqrt(2.0) << endl;
    cout << right << setw(16) << sqrt(2.0) << endl;
    cout << internal << setw(16) << -sqrt(2.0) << endl;
    cout << setfill('#') << setw(16) << -sqrt(2.0) << setfill(' ') << endl;
    cout << "--------------------------------" << endl;
    cout << "hexadecimal: " << hexfloat << uppercase << sqrt(2.0) << defaultfloat << endl;
    cout << "hexadecimal: " << hexfloat << nouppercase << sqrt(2.0) << defaultfloat << endl;
    cout << "--------------------------------" << endl;
    cin >> noskipws;
    char ch;
    while(cin >> ch)
        cout << ch;
}