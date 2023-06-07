#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Course
{
private:
    string name;
    int number;

public:
    friend ostream &operator<<(ostream &out, const Course &p);
    friend istream &operator>>(istream &in, Course &p);
};

istream &operator>>(istream &in, Course &p)
{
    in >> p.name;
    in >> p.number;
    return in;
}

ostream &operator<<(ostream &out, const Course &p)
{
    out << p.name << " " << p.number;
    return out;
}

int main()
{
    int i;
    ifstream ifs;
    Course courses[3];
    ifs.open("course.txt", ios::in);
    while(!ifs.eof())
    {
        ifs >> courses[i++];
    }
    for (i = 0; i < 3; i++)
    {
        cout << courses[i] << endl;
    }
    ifs.close();
    return 0;
}
