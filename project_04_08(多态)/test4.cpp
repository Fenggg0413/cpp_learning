#include<iostream>
using namespace std;
class cpu
{
    public:
        virtual void calculate() = 0;
};
class videocard
{
    public:
        virtual void display() = 0;
};
class memory
{
    public:
        virtual void memoring() = 0;
};

//Inter
class InterCPU : public cpu
{
    public:
        virtual void calculate()
        {
            cout<<"Inter的CPU正在工作"<<endl;
        }
};
class InterVC : public videocard
{
    public:
        virtual void display()
        {
            cout<<"Inter的显卡正在工作"<<endl;
        }
};
class InterMEM : public memory
{
    public:
        virtual void memoring()
        {
            cout<<"Inter的内存正在工作"<<endl;
        }
};

//Nvidia
class NvidiaCPU : public cpu
{
    public:
        virtual void calculate()
        {
            cout<<"Nvidia的CPU正在工作"<<endl;
        }
};
class NvidiaVC : public videocard
{
    public:
        virtual void display()
        {
            cout<<"Nvidia的显卡正在工作"<<endl;
        }
};
class NvidiaMEM : public memory
{
    public:
        virtual void memoring()
        {
            cout<<"Nvidia的内存正在工作"<<endl;
        }
};

class Computer
{
    private:
        cpu *m_cpu;
        videocard *m_vc;
        memory *m_mem;
    public:
        Computer(cpu *cpu, videocard *vc, memory *mem)
        {
            m_cpu=cpu;
            m_vc=vc;
            m_mem=mem;
        }
        void dowork()
        {
            m_cpu->calculate();
            m_vc->display();
            m_mem->memoring();
        }
        ~Computer()     //将main用new创建的内存空间释放
        {
            delete m_cpu;
            delete m_vc;
            delete m_mem;
            cout<<"111"<<endl;
        }
};

int main()
{
    cpu *ptr1 = new InterCPU;
    videocard *ptr2 = new NvidiaVC;
    memory *ptr3 = new InterMEM;
    Computer *ptr = new Computer(ptr1, ptr2, ptr3);
    ptr->dowork();
    delete ptr;
    ptr=new Computer(new NvidiaCPU,new InterVC,new NvidiaMEM);
    ptr->dowork();
    delete ptr;
    return 0;
}