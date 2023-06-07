#include<iostream>
using namespace std;
class Person
{
    public:
        int a;
        Person& operator--()        //前缀--
        {
            a--;
            return *this;
        }
        Person operator--(int)      //后--
        {
            Person temp = *this;
            a--;
            return temp;
        }
};
ostream& operator<<(ostream& out, Person p)//<<重载
{
    out<<p.a;
    return out;
}
void test()
{
    Person p;
    p.a=10;
    cout<<p--<<endl;
    cout<<--p;
}
int main()
{
    test();
    return 0;
}