#include <iostream>

using namespace std;

class shape
{
public:
    const double PI = 3.1415;

    virtual double volume() = 0;
};

class cylinder : public shape
{
private:
    double r, h;

public:
    cylinder(double r, double h) : r(r), h(h){};

    virtual double volume()
    {
        return PI * r * r * h;
    }
};

class sphere : public shape
{
private:
    double r;

public:
    sphere(double r) : r(r){};

    virtual double volume()
    {
        return r * r * r * 4 / 3 * PI;
    }
};

int main()
{
    shape *p;
    double r, h;
    cout << "input r & h：" << endl;
    cin >> r >> h;
    cylinder cy(r, h);
    sphere sp(r);
    p = &cy;
    cout << p->volume() << endl;
    p = &sp;
    cout << p->volume() << endl;
    return 0;
}