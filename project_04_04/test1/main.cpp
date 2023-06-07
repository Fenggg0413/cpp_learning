#include<iostream>
using namespace std;
class Student
{
private:
    int age;
    string name;
public:
    static int count;
    Student(int m, string n) :age(m), name(n) { count++; }
    Student();
    ~Student() { count--; }
    void Print() const;
};

void Student::Print() const  //常成员函数的定义
{
    cout << "count=" << count << endl;
    cout << name << "  " << age << endl;
}

Student::Student()
{
    age = 0;
    name = "unnamed";
    count++;
}
int Student::count = 0;     //静态数据成员的初始化

int main()
{
    cout << "count=" << Student::count << endl;
    string stuname = "ZhangHong";
    Student s1, * p = new Student(23, stuname);
    s1.Print();
    p->Print();
    delete p;
    s1.Print();
    Student Stu[4];
    cout << "count=" << Student::count << endl;
    return 0;
}
