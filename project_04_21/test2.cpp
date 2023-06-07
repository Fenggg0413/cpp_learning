#include <iostream>
using namespace std;

class Container
{
protected:
    double radius;

public:
    Container(double r)
    {
        radius = r;
    }
    virtual double area() = 0;    // 求表面积的纯虚函数
    virtual double volume() = 0;  // 求体积的纯虚函数
    virtual void print() = 0; // 输出函数的纯虚函数
};

class Cube : public Container
{
public:
    Cube(double side): Container(side) {}
    double area()
    {
        return radius * radius * 6;
    }
    double volume()
    {
        return radius * radius * radius;
    }
    void print()
    {
        cout << "正方体的边长为：" << radius << "\n"
             << "正方体的表面积为：" << this->area() << "\n"
             << "正方体的体积为：" << this->volume() << endl;
    }
};

class Sphere : public Container
{
public:
    Sphere(double r) : Container (r) {}
    double area()
    {
        return 4 * 3.1416 * radius * radius;
    }
    double volume()
    {
        return (4 / 3) * 3.1416 * radius * radius * radius;
    }
    void print()
    {
        cout << "球体的半径为：" << radius << "\n"
             << "球体的表面积为：" << this->area() << "\n"
             << "球体的体积为：" << this->volume() << endl;
    }
};

class Cylinder : public Container
{
private:
    double m_high;

public:
    Cylinder(double r, double h) : Container(radius), m_high(h) {}
    double area()
    {
        return 2 * 3.1416 * radius * m_high + 2 * 3.1416 * radius * radius;
    }
    double volume()
    {
        return 2 * 3.1416 * radius * radius * m_high;
    }
    void print()
    {
        cout << "圆柱体的半径为：" << radius << "\n"
             << "圆柱体的高为：" << m_high << "\n"
             << "圆柱体的表面积为：" << this->area() << "\n"
             << "圆柱体的体积为：" << this->volume() << endl;
    }
};

void TopPrint(Container &r)
{
    r.print();
}

int main()
{
    Cube cube(3);
    Sphere sphere(2.4);
    Cylinder cylinder(3.1, 5);
    TopPrint(cube);
    TopPrint(sphere);
    TopPrint(cylinder);
    return 0;
}


