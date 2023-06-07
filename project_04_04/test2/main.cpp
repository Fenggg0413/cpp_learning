#include<iostream>
#include<cstring>
using namespace std;
class Book
{
private:
    string bookname;
    double price;
    int number;
public:
    void display() const;
    void borrow();
    void restore();
    Book(string b, double p, int n);
    Book();
    ~Book(){    };
};
Book::Book(string b, double p, int n)
{
    bookname = b;
    price = p;
    number = n;
}

Book::Book()
{

}

void Book::display() const
{
    cout << bookname << " " << price << " " << number << endl;
}

void Book::borrow()
{
    number--;
}

void Book::restore()
{
    number++;
}
int main()
{
    char name[20] = "C++";
    Book book1(name, 23.5, 3);
    strcpy(name, "Data Structure");
    Book book2(name, 28.8, 7);
    book1.borrow();
    book1.display();
    book2.restore();
    book2.display();
    return 0;
}