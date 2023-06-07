#include<iostream>
using namespace std;
class Cube
{
    private:
        int length,width,high;
    public:
        Cube(int l=3,int w=2,int h=1);
        int Compute()
        {
            return length*width*high;
        }
};

Cube::Cube(int l,int w,int h)
{
    length=l;
    width=w;
    high=h;
}
int main()
{
	int l,w,h;
	cout<<"输入立方体的长宽高："<<endl;
	cin>>l>>w>>h;
	Cube A(l,w,h);
    Cube B;
	cout<<A.Compute()<<endl;
	cout<<B.Compute()<<endl;
}
