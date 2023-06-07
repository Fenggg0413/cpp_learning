#include<iostream>
#include<string>
using namespace std;
class BookCard
{
    private:
        string id;          //借书证学生的学号
        string stuName;    //借书证学生的姓名
        int number; 
    public:
        BookCard(string uid="B19010250", string ustuName="雪峰", int num=3)
        {
            id=uid;
            stuName=ustuName;
            number=num;
        }
        void display()
        {
            cout<<id<<" "<<stuName<<" "<<number<<endl;
        }
        bool borrow()
        {
            if(number<10)
            {
                number++;
                return true;
            }
            else
            {
                return false;
            }
        }

};
void f(BookCard &bk)
{
    if (!bk.borrow())   //如果为false
    {
        bk.display();
        cout<<"you have borrowed 10 books,can not borrow any more!"<<endl;
    }
    else
        bk.display();
}

int main()
{
    BookCard bk1("B20190620","东平",10),bk2;
    f(bk1);
    f(bk2);
    return 0;
}
