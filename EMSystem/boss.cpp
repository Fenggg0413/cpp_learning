#include"boss.h"
boss::boss(int uid, std::string name, int uDeptid)
{
    this->m_id = uid;
    this->m_name = name;
    this->m_Deptid = uDeptid;
}  
boss::~boss()   //析构函数
{

}
void boss::showInfo()
{
    std::cout<<"员工编号："<<this->m_id<<"\t"
             <<"员工姓名："<<this->m_name<<"\t"
             <<"员工岗位："<<this->getDeptName()<<"\t"
             <<"岗位职责：管理公司所有事物"<<std::endl;
}

std::string boss::getDeptName()
{
    return "公司总裁";
}