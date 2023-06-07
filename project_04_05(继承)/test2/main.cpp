#include<iostream>
using namespace std;
class Station
{
    protected:
        string from;
        string to;
    public:
        Station(string fr="unnamed", string t="nunamed"):from(fr),to(t){

        }
        void disp(){
            cout<<from<<" "<<to<<" ";
        }
};
class Mile
{
    protected:
        double mile;
    public:
        Mile(double ml=0):mile(ml){

        }
        void disp(){
            cout<<mile<<" ";
        }
};
class Price:public Station, public Mile
{
    private:
        double price;
    public:
        Price(string fr="unnamed", string t="nunamed", double ml=0):Station(fr,t),Mile(ml){
            price=0;
        }
        void disp()
        {
            if(mile<=3)//小于3公里8块钱
            {
                price=8;
            }
            else//计算大于3公里的情况
            {
                const int count=8;
                double halfmile=(mile-3)*2;
                double tf=halfmile-(int)halfmile;
                if(tf>0&&tf<1)
                {
                    halfmile=halfmile-tf+1;
                }
                price=count+halfmile*0.7;
            }
            Station::disp();
            Mile::disp();
            cout<<price<<endl;
        }
        void Setfrom(string fr)
        {
            from=fr;
        }
        void Setto(string t)
        {
            to=t;
        }
        void Setmile(double ml)
        {
            mile=ml;
        }
};
int main()
{
    Price pr;
    string fr;
    string t;
    double ml;
    cin>>fr>>t>>ml;
    pr.Setfrom(fr);
    pr.Setmile(ml);
    pr.Setto(t);
    pr.disp();
    return 0;
}