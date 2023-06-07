#include"employee.h"
//构造函数
employee::employee(int uid, string name, int uDeptid)
{
    this->m_id = uid;
    this->m_name = name;
    this->m_Deptid = uDeptid;
}  
employee::~employee()   //析构函数
{

}
void employee::showInfo()
{
    cout<<"员工编号："<<this->m_id<<"\t"
        <<"员工姓名："<<this->m_name<<"\t"
        <<"员工岗位："<<this->getDeptName()<<"\t"
        <<"岗位职责：完成经理交代的任务"<<endl;
}

string employee::getDeptName()
{
    return "普通员工";
}