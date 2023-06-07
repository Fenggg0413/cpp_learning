/*#include<iostream>
using namespace std;
int main()
{
    int num,i,positive=0,negative=0;
    cin>>num;
    if(num<1||num>20)
    {
        cout<<"number error.\n"<<endl;
    }
    else
    {
        int *ps=new int[num];
        for(i=0;i<num;i++)
        {
             cin>>ps[i];
        }
        for(i=0;i<num;i++)
        {
            if(ps[i]>0)
            {
                positive++;
            }
            if(ps[i]<0)
            {
                negative++;
            }
        }
        cout<<"There are "<<num<<" figures,"<<endl; 
        cout<<positive<<" of them are positive numbers,"<<endl; 
        cout<<negative<<" of them are negatives."<<endl;
        delete ps;
    }
    return 0;
}*/

#include<iostream>
#define Pi 3.14159
using namespace std;
int main()
{
    double s,c,r;
    cin>>r;
    s=Pi*r*r;
    c=2*r*Pi;
    cout<<"s="<<s<<",c="<<c<<endl;
    return 0;
}