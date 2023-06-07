#include"WorkerManager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "Worker.h"

#include<iostream>
using namespace std;

int main()
{
    WorkerManager wm;
    //test();
    while (true)
    {
        wm.showMeun(); // 创建一个对象并展示菜单
        int choice = 0;
        cout << "请输入你的选择: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            wm.exitWM(); // 退出系统
            break;
        case 1: // 增加员工
            system("cls");
            wm.addEmpNum();
            wm.save();
            break;
        case 2: // 显示员工
            system("cls");
            wm.showEM();
            break;
        case 3: // 删除员工
            system("cls");
            wm.deleteEM();
            wm.save();  //删除后需要保存文件
            break;
        case 4: // 修改员工
            system("cls");
            wm.Mod_Emp();
            wm.save();  //修改后需要保存文件
            break;
        case 5: // 查找员工
            system("cls");
            wm.LookFor();
            break;
        case 6: // 编号排序
            system("cls");
            wm.sortEmp();
            wm.save();
            break;
        case 7: // 清空所有文档
            system("cls");
            wm.deleteAll();
            break;
        default:
            system("cls"); // 清屏
            break;
        }
    }
    return 0;
}