#include"manager.h"
manager::manager(int uid, string name, int uDeptid)
{
    this->m_id = uid;
    this->m_name = name;
    this->m_Deptid = uDeptid;
}  
manager::~manager()   //析构函数
{

}
void manager::showInfo()
{
    cout<<"员工编号："<<this->m_id<<"\t"
        <<"员工姓名："<<this->m_name<<"\t"
        <<"员工岗位："<<this->getDeptName()<<"\t"
        <<"岗位职责：完成老板交代的任务"<<endl;
}

string manager::getDeptName()
{
    return "公司经理";
}