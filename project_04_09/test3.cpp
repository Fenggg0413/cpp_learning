#include <iostream>
#include <string>
using namespace std;

class Boy;
class Girl {
private:
    string name;
    int age;
public:
    Girl(string n, int a) : name(n), age(a) {}
    ~Girl() {}
    friend void VisitBoyGirl(Boy &b, Girl &g);
    friend Boy;
    void printInfo() {
        cout << "Girl's name is " << name << " and she is " << age << " years old." << endl;
    }
    // void VisitBoy(Boy& b);
};

class Boy {
private:
    string name;
    int age;
public:
    friend Girl;
    friend void VisitBoyGirl(Boy &b, Girl &g);
    Boy(string n, int a) : name(n), age(a) {}
    ~Boy() {}
    void printInfo() {
        cout << "Boy's name is " << name << " and he is " << age << " years old." << endl;
    }
    // void VisitGirl(Girl &g);
};
// void Girl::VisitBoy(Boy &b) {
//     cout << "Girl visits boy named " << b.name << " and he is " << b.age << " years old." << endl;
// }
// void Boy::VisitGirl(Girl &g)
// {
//     cout << "Girl visits girl named " << g.name << " and she is " << g.age << " years old." << endl;
// }
void VisitBoyGirl(Boy &b, Girl &g) 
{
    cout << "Boy visits girl named " << g.name << " and she is " << g.age << " years old." << endl;
    cout << "Girl visits boy named " << b.name << " and he is " << b.age << " years old." << endl;
}
int main() {
    Girl g("Lucy", 18);
    Boy b("Tom", 20);
    // g.VisitBoy(b);
    // b.VisitGirl(g);
    VisitBoyGirl(b,g);
    return 0;
}
