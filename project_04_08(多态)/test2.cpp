#include<iostream>
using namespace std;
class Parent				//抽象类
{
  public:
  	virtual void func() = 0;  //纯虚函数
};
class Child : public Parent
{
    public:
    	virtual void func()		//重写抽象类中的纯虚函数
        {
            cout<<"Hello Feng!"<<endl;
		}
};
class Child_2 : public Parent
{
    public:
        virtual void func()
        {
            cout<<"Hello World!"<<endl;
        }
};
int main()
{
    //Parent p;//禁止！，因为无法示例化抽象类的对象
    Parent *p = new Child; //创建一个父类的指针指向某个子类对象
    p->func();
    delete p;	//释放该空间
    p = new Child_2;
    p->func();
    delete p;
    return 0;
}