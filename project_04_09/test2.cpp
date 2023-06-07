#include<iostream>
using namespace std;
class Time
{
    private:
        int Hour;
        int Minute;
        int Second;
    public:
        Time(int h=0, int m=0, int s=0)
        {
            Hour=h;
            Minute=m;
            Second=s;
            cout<<"构造函数已被调用"<<endl;
        }
        Time(const Time &tm)
        {
            this->Hour=tm.Hour;
            this->Minute=tm.Minute;
            this->Second=tm.Second;
            cout<<"拷贝构造函数已被调用"<<endl;
        }
        ~Time()
        { 
            cout<<"析构函数已被调用"<<endl;
        }
        void SetTime(int hour, int minute, int second)
        {
            Hour = hour;
            Minute = minute;
            Second = second;
        }

        void GetTime(int& hour, int& minute, int& second) const 
        {
            hour = Hour;
            minute = Minute;
        second = Second;
        }
        void PrintTime()
        {
            cout<<"当前时间为 "<<Hour<<":"<<Minute<<":"<<Second<<endl;
        }
        void IncreaceOneSecond()
        {
            Second++;
            if(Second==60)
            {
                Second=0;
                Minute++;
                if(Minute==60)
                {
                    Minute=0;
                    Hour++;
                    if(Hour==24)
                    {
                        Hour=0;
                    }
                }
            }
            PrintTime();
        }
};

// void f(Time t)
// {    
//     t.PrintTime( );
// }
void f(Time &t)
{
    t.PrintTime();
}
void f(Time *t)
{
    t->PrintTime();
}
int main()
{
    Time t1(16,26,32);
    Time t2;
    // Time t2(t1);
    f(&t1);  
    // cout<<t1.Hour<<":"<<t1.Minute<<":"<<t1.Second<<endl;
    //f(&t2);
    return 0;
}