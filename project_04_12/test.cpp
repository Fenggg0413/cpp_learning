#include<iostream>
#include<string>
using namespace std;
class Axis
{
    private:
        double m_x;
        double m_y;
        double m_z;
    public:
        Axis(double x, double y, double z):m_x(x), m_y(y), m_z(z){}
        friend ostream& operator<<(ostream& os, Axis a);
        friend bool operator>(Axis &a ,Axis &b);
};
ostream& operator<<(ostream& os, Axis a) 
{
    os<<"("<<a.m_x<<","<<a.m_y<<","<<a.m_z<<")";
    return os;
}
bool operator>(Axis &a ,Axis &b)
{
    double temp1,temp2;
    temp1=a.m_x*a.m_x+a.m_y*a.m_y+a.m_z*a.m_z;
    temp2=b.m_x*b.m_x+b.m_y*b.m_y+b.m_z*b.m_z;
    if(temp1>temp2){
        return true;
    }
    else{
        return false;
    }
}
void test()
{
    Axis a(10,2,3);
    Axis b(10,20,1);
    cout<<a<<endl;
    cout<<b<<endl;
    if(a>b)
    {
        cout<<"a>b"<<endl;
    }else{
        cout<<"a!>b"<<endl;
    }
}
int main()
{
    test();
    return 0;
}
