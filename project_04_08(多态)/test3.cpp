#include<iostream>
using namespace std;
class Animal
{
	public:
    	Animal()	//Animal的构造函数
        {
            cout<<"Animal's constructor"<<endl;
        }
		virtual void Print() = 0; //纯虚函数
    	virtual ~Animal() = 0;	  //纯虚析构函数的声明
};
Animal::~Animal()	//纯虚析构函数的定义，函数体内可以不写内容
{
    cout<<"Animal's destructor"<<endl;
}
class Cat : public Animal
{
  	public:
    	string *m_name;
    	Cat(string name)	//在堆区中开辟新空间的构造函数
        {
            m_name = new string(name);
            cout<<"Cat's constructor"<<endl;
        }
    	virtual void Print()	//纯虚函数在子类的重写
        {
            cout<<*m_name<<"在说话"<<endl;
        }
    	~Cat()	//Cat的析构函数
        {
            cout<<"Cat's destructor"<<endl;
            if(this->m_name != NULL)//释放构造函数在堆区开辟的新内存
            {
                delete m_name;
                m_name = NULL;
			}
		}
};

int main()
{
    Animal *p = new Cat("Tom");	//创建一个父类的指针指向子类对象
    p->Print();
    delete p;
    return 0;
}