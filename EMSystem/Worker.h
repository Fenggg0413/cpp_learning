#pragma once
#include<string>
#include<iostream>
using namespace std;
class Worker    //员工抽象类
{
    public:
        int m_id;   //员工编号
        string m_name; //员工姓名
        int m_Deptid;   //所在部门编号
        virtual void showInfo() = 0;
        virtual string getDeptName() = 0;    
};