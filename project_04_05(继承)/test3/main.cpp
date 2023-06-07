#include<iostream>
using namespace std;
//三个构造函数
class Date
{
    private:
        int year;
        int month;
        int day;
    public:
        Date(int y=2000, int m=1, int d=1):year(y),month(m),day(d){

        }
        int Getyear()
        {
        return year;
        }
        int Getmonth()
        {
            return month;
        }
        int Getday()
        {
            return day;
        }
        void Setyear(int y)
        {
            year=y;
        }
        void Setmonth(int m)
        {
            month=m;
        }
        void Setday(int d)
        {
            day=d;
        }
};
class Product : public Date
{
    private:
       string name;
       double price;
       Date deptime;
       string factory;
       bool easy_break;
       Date valtime; 
       string color;
       double high;
    public:
        Product(string nm);//通过指定产品名创建
        Product(string nm, double pr);// 通过指定产品名和产品价格创建
        Product(string nm, double pr, int y, int m, int d);//通过指定产品名、产品价格、出厂日期（对象成员）创建
        void SetProduct( string nm, double pr,
                         int dy, int dm, int dd,
                         string fc, bool eb,
                         int vy, int vm, int vd,
                         string cl, double hg)
        {
            name=nm;
            price=pr;
            deptime.Setyear(dy);
            deptime.Setmonth(dm);
            deptime.Setday(dd);
            factory=fc;
            easy_break=eb;
            valtime.Setyear(vy);
            valtime.Setmonth(vm);
            valtime.Setday(vd);
            color=cl;
            high=hg;
        }
        void output (  ); 
}; 
Product::Product(string nm):name(nm)
{
    cout<<"Constrcting One...."<<endl;
    factory="unnamed";//对工厂和易碎程度初始化
    easy_break=0;
}
Product::Product(string nm, double pr):name(nm),price(pr)
{
    cout<<"Constrcting Two...."<<endl;
    factory="unnamed";//对工厂和易碎程度初始化
    easy_break=0;
}
Product::Product(string nm, double pr, int y, int m, int d):name(nm),price(pr)
{
    cout<<"Constrcting Three...."<<endl;
    factory="unnamed";//对工厂和易碎程度初始化
    easy_break=0;
    deptime.Setyear(y);
    deptime.Setmonth(m);
    deptime.Setday(d);
}
void Product::output (  )
{
       cout<<name<<" "<<price<<endl;
       cout<<deptime.Getyear()<<"-"<<deptime.Getmonth()<<"-"<<deptime.Getday()<<endl;
       cout<<factory<<" "<<easy_break<<endl;
       cout<<valtime.Getyear()<<"-"<<valtime.Getmonth()<<"-"<<valtime.Getday()<<endl;
}
int main()
{
       string  s;
       cin>>s;
       Product p1("car");
       Product p2("glass",3.00);
       Product p3("pen",5.00,2009,3,14);
       p1.SetProduct("car",100000.0,2009,3,14,"nanjing",0,2010,10,14,"red",1.5);
       p1.output();
       p2.output();
       p3.output();
       return 0;
}