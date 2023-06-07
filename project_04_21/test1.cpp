#include<iostream>
using namespace std;
class Point
{
public:
    double m_x;
    double m_y;
    friend Point operator+(Point &p1, Point &p2); // 友元声明重载+
    friend Point operator+(Point &p, double num);
    friend ostream &operator<<(ostream &out, Point &p);
    Point(double x = 0.0, double y = 0.0)
    {
        this->m_x = x;
        this->m_y = y;
    }
    Point &operator++() // 重载前置++
    {
        this->m_x++;
        this->m_y++;
        return *this;
    }
    Point &operator-(Point &p) // 重载-
    {
        this->m_x = this->m_x - p.m_x;
        this->m_y = this->m_y - p.m_y;
        return *this;
    }
};
Point operator+(Point &p1, Point &p2)
{
    Point p;
    p.m_x = p1.m_x + p2.m_x;
    p.m_y = p1.m_y + p2.m_y;
    return p;
}

Point operator+(Point &p, double num)
{
    Point P;
    P.m_x = p.m_x + num;
    P.m_y = p.m_y + num;
    return P;
}

ostream &operator<<(ostream &out, Point &p) 
{
    out << "(" << p.m_x << "," << p.m_y << ")" << endl;
    return out;
}

int main()
{
    Point pt1(10.5, 20.8), pt2(-5.3, 18.4), pt3;
    cout << "original pt1,pt2,pt3 are:\n";
    cout << pt1 << pt2 << pt3;
    pt3 = pt1 + 100.8;
    cout << "after pt3=pt1+100.8, pt3 is:" << pt3;
    pt3 = pt1 + pt2;
    cout << "after pt3=pt1+pt2, pt3 is:" << pt3;
    pt3 = ++pt1;
    ++pt2;
    cout << "after ++ pt1,pt2,pt3 are:\n";
    cout << pt1 << pt2 << pt3;
    pt3 = pt1 - pt2;
    cout << "after pt3=pt1-pt2, pt3 is:" << pt3;
    return 0;
}

