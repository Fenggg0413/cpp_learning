/*#include<iostream>
using namespace std;
#define Pi 3.14159
int main()
{
    double area,radius,circumference;
    cin>>radius;
    area=Pi*radius*radius;
    circumference=2*Pi*radius;
     if(radius<=0)
    {
        cout<<"error input!"<<endl;
    }
    else
    {
        cout<<area<<" "<<circumference<<endl;
    }
    system("pause");
    return 0;
}*/


#include<iostream> //申请动态内存定义数组
using namespace std;
int main()
{
    int n, i, number = 0;
    double ave;
    cin >> n;
    int* p = new int[n];
    for (i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int sum = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        if (p[i] > 0)
        {
            sum += p[i];
            j++;
        }
        if (p[i] < 0)
        {
            number++;
        }
    }
    if (j > 0)
    {
        ave = (double)sum / j;
    }
    else
    {
        ave = 0;
    }
    cout << "ave=" <<ave<<"  number="<<number<<endl;
    delete[] p;
    system("pause");
    return 0;
}