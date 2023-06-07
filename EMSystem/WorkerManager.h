#pragma once
#include<fstream>
#include"Worker.h"
#define FILENAME "emsystem.txt" //设置文件名称 
class WorkerManager //功能控制类
{
    public:
        int m_EmpNum;   //员工人数
        Worker **m_EmpArray;    //员工数组的指针
        bool m_FileIsEmpty;  //描述文件是否为空
        WorkerManager();
        ~WorkerManager();
        void showMeun();    //功能菜单
        void exitWM();      //退出系统
        void addEmpNum();   //添加员工
        void save();    //保存文件
        int getNum();   //从文件中获取员工人数
        void init_Emp();    //初始化员工数组指针
        void showEM();  //显示员工信息
        void deleteEM();    //删除员工信息
        int UidExist(int uid);   //查询uid的数组下标
        bool IsUidExist(int uid);   //查询uid是否在系统中
        void LookFor();             // 通过id或姓名查找员工
        void deleteAll();   //删除系统库
        void Mod_Emp(); //修改员工信息
        void sortEmp(); //员工编号排序
};