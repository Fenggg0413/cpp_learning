#include"WorkerManager.h"
#include"Worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<iostream>
#include<fstream>
using namespace std;

WorkerManager::WorkerManager()  //构造函数，在构造函数中向文件读取数据
{
    // this->m_EmpNum = 0;         //初始化员工人数
    // this->m_EmpArray = NULL;    //初始化员工指针数组
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //第一种情况，文件未创建
    if(!ifs.is_open())
    {
        cout << "员工文件未被创建!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();    //关闭文件
        return;
    }

    //第二种情况，文件已创建但是没有数据(文件为空)
    char ch;
    ifs >> ch;
    //代码打开了一个文件并读取了一个字符。如果文件中没有内容，即文件已经到达了文件结尾(eof)
    if(ifs.eof())
    {
        cout << "员工文件为空!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    //第三种情况，文件存在并且写有数据
    int num;
    num = this->getNum();
    this->m_EmpNum = num;                            // 初始化员工人数
    // cout << this->m_EmpNum <<" "<<num<< endl;   //用于测试
    this->m_EmpArray = new Worker *[this->m_EmpNum]; //初始化指针数组长度
    this->init_Emp();   //初始化对象
    // for (int i = 0; i < m_EmpNum; i++)  //用于测试
    // {
    //     cout << "职工号：" << this->m_EmpArray[i]->m_id
    //          << "  职工姓名：" << this->m_EmpArray[i]->m_name
    //          << "  部门编号：" << this->m_EmpArray[i]->m_Deptid 
    //          << "  员工职位：" << this->m_EmpArray[i]->getDeptName()<<endl;
    // }
    // system("pause");
    // system("cls");
    ifs.close();
}

WorkerManager::~WorkerManager() //析构函数
{
    //释放堆区数据
    if(this->m_EmpArray!=NULL)  
    {
        delete this->m_EmpArray;
    }
}
void WorkerManager::showMeun()  //界面菜单功能
{
    cout<<"******************************"<<endl;
    cout<<"******欢迎使用员工管理系统****"<<endl;
    cout<<"******* 0.退出管理系统 *******"<<endl;
    cout<<"******* 1.增加员工信息 *******"<<endl;
    cout<<"******* 2.显示员工信息 *******"<<endl;
    cout<<"******* 3.删除员工信息 *******"<<endl;
    cout<<"******* 4.修改员工信息 *******"<<endl;
    cout<<"******* 5.查找员工信息 *******"<<endl;
    cout<<"******* 6.按照编号排序 *******"<<endl;
    cout<<"******* 7.清空所有文档 *******"<<endl;
    cout<<"******************************"<<endl;
    cout<<endl;
}
void WorkerManager::exitWM()     //退出功能
{
    system("cls");
    cout<<"欢迎您下次继续使用"<<endl;
    system("pause");
    exit(0);
}   

void WorkerManager::addEmpNum()
{
    cout << "请输入要增加的员工人数" << endl;

    int addNum = 0;
    cin >> addNum;  //输入新增人数
    if(addNum>0)
    {
        int newNum = this->m_EmpNum + addNum;   //计算新的数组长度
        Worker **newspace = new Worker*[newNum];    //开辟新空间
        //将原空间放到新空间下
        if(this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newspace[i] = this->m_EmpArray[i];
            }
        }
        //输入新信息
        for (int i = 0; i < addNum;i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第" << i + 1 << "名员工编号" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "名员工姓名" << endl;
            cin >> name;
            do
            {
                cout << "请选择该员工的职位：" << endl;
                cout << "1.普通员工"
                     << "\n"
                     << "2.公司经理"
                     << "\n"
                     << "3.公司老板"
                     << "\n";
                cin >> dSelect; // 输入职位编号选择
            } while (dSelect < 1 || dSelect > 3);

            Worker *worker = NULL;
            switch(dSelect)     //根据职位编号不同创建新的职位对象
            {
                case 1:
                    worker = new employee(id, name, 1);
                    break;
                case 2:
                    worker = new manager(id, name, 2);
                    break;
                case 3:
                    worker = new boss(id, name, 3);
                    break;
            }
            newspace[this->m_EmpNum + i] = worker;  //将新创建的职位对象地址赋值给指针对象数组
        }
        // 释放原来的指针对象数组
        delete this->m_EmpArray;
        // 使指针指向新的指针数组空间
        this->m_EmpArray = newspace;
        // 更新员工人数
        this->m_EmpNum = newNum;
        // 提示输入成功
        cout << "成功添加" << addNum << "名员工" << endl;
    }
    else
    {
        cout << "输入有误" << endl;
    }
    this->m_FileIsEmpty = false;
    system("pause");
    system("cls");  //清屏
}

void WorkerManager::save()  //将数据写入文件
{
    ofstream ofs;   //创建文件流
    ofs.open(FILENAME, ios::out);   //打开FILENAME文件

    for (int i = 0; i < this->m_EmpNum; i++) //通过for循环将数据写入文件
    {
        ofs << this->m_EmpArray[i]->m_id << " "
            << this->m_EmpArray[i]->m_name << " "
            << this->m_EmpArray[i]->m_Deptid << " "
            << this->m_EmpArray[i]->getDeptName() << endl;
    }
    cout << "已成功保存入文件" << endl;
    ofs.close();    //关闭文件
}

int WorkerManager::getNum() //从文件中读取员工人数
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int pid;
    string dname;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs>>pid &&ifs >> dname)
    {
        // 记录人数
        num++;
    }
    ifs.close();
    //cout << num << endl;  //用于测试
    return num;
}

void WorkerManager::init_Emp()  //初始化员工系统
{
    int id;
    string name;
    string dname;
    int pid;
    ifstream ifs(FILENAME, ios::in);    //创建文件流并打开FILENAME文件
    int index = 0;  //在循环外定义并初始化索引
    while (ifs >> id && ifs >> name && ifs>>pid && ifs >> dname)
    {
        Worker *worker = NULL;
        switch (pid)
        {   
            case 1:
                worker = new employee(id, name, 1);
                break;
            case 2:
                worker = new manager(id, name, 2);
                break;
            case 3:
                worker = new boss(id, name, 3);
                break;
        }
        this->m_EmpArray[index++] = worker;
    }
    ifs.close();
}

void WorkerManager::showEM()    //显示员工信息
{
    if(this->m_FileIsEmpty)
    {
        cout << "系统中目前没有员工信息，请添加员工信息后再查询！" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < m_EmpNum; i++)  //用于测试
    {
        //调用多态进行输出信息
        this->m_EmpArray[i]->showInfo();
    }
    system("pause");
    system("cls");
}

void WorkerManager::deleteEM()  //删除员工信息
{
    int uid;
    cout << "请输入要删除的员工id: " << endl;
    cin >> uid;
    if(this->IsUidExist(uid))
    {
        int index = this->UidExist(uid);
        cout << "要删除的员工存在,其信息如下：" << endl;
        this->m_EmpArray[index]->showInfo();
        cout << "是否删除该员工？" << endl;
        cout << "1.是"
             << "\n"
             << "2.否" << endl;
        int select = 2;   //定义并初始化选择信息
        do
        {
            cin >> select;
        } while (select<1||select>2);
        switch(select)
        {
            case 1:
                for (int i = index; i < this->m_EmpNum - 1; i++)
                {
                    this->m_EmpArray[i] = this->m_EmpArray[i + 1];
                }
                cout << "删除成功！" << endl;
                this->m_EmpNum--;
                break;
            case 2:
                cout << "已取消删除！" << endl;
                break;
        }
        system("pause");
        system("cls");
        return;
    }
    else
    {
        cout << "该员工不存在，请按任意键返回系统" << endl;
        system("pause");
        system("cls");
        return;
    }
}

int WorkerManager::UidExist(int uid)  //查询员工id是否存在并返回索引
{
    int index = 0;
    for(int i = 0; i < this->m_EmpNum; i++)
    {
        if(uid == this->m_EmpArray[i]->m_id)
        {
            index = i; // 如果id=uid则返回索引
            break;
        }
    }
    return index;
}

bool WorkerManager::IsUidExist(int uid)  //查询员工id是否存在
{
    int flag = false;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (uid == this->m_EmpArray[i]->m_id)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

void WorkerManager::LookFor()   //通过id或姓名查找员工
{
    int select = 1; //默认通过id查询
    cout << "请输入要查询的方式: "
         << "\n"
         << "1.通过id查询"
         << "\n"
         << "2.通过姓名查询" << endl;
    do
    {
        cin >> select;
    } while (select < 1 || select > 2);
    switch(select)
    {
        case 1:
            int uid;
            cout << "请输入要查询的员工id：";
            cin >> uid;
            if (this->IsUidExist(uid))
            {
                int index = this->UidExist(uid);
                cout << "id为"<<uid<<"的员工存在,其信息如下：" << endl;
                this->m_EmpArray[index]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
            break;
        case 2:
            string name;
            bool flag = false;
            cout << "请输入要查询的员工名字：" << endl;
            cin >> name;
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if(name==this->m_EmpArray[i]->m_name)   //将重名的员工也打印出来
                {
                    cout << "姓名为" << name << "的员工存在,其信息如下：" << endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if(flag==false)
            {
                cout << "查找失败，查无此人" << endl;
            }
            break;
    }
    system("pause");
    system("cls");
}    

void WorkerManager::deleteAll() //清空文件
{
    cout << "请确认是否清空文件"
         << "\n"
         << "1.确定"
         << "\n"
         << "2.取消" << endl;
    int select = 2;
    cin >> select;
    if(select==1)
    {
        ofstream ofs;
        ofs.open(FILENAME, ios::trunc);
        ofs.close();
        if (this->m_EmpArray != NULL)
		{
            for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
        cout << "已清空文件！" << endl;
    }
    else if(select==2)
    {
        cout << "已取消清空操作，请按任意键返回系统" << endl;
    }
    else
    {
        cout << "输入有误，请按任意键返回系统" << endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::Mod_Emp()   //修改员工信息
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或者为空！" << endl;
    }
    else
    {
        cout << "请输入您要修改的员工编号：" << endl;
        int uid;
        cin >> uid;
        if(this->IsUidExist(uid))
        {
            int index = this->UidExist(uid);
            cout << "该员工编号存在,其信息如下：" << endl;
            this->m_EmpArray[index]->showInfo();
            int newid;
            string newname;
            int newpid;
            cout << "请输入新的员工编号：" << endl;
            cin >> newid;
            cout << "请输入新的员工姓名：" << endl;
            cin >> newname;
            cout << "请输入新的员工职位编号："<<"\n"
                 << "1.普通员工"<<"\n"
                 << "2.公司经理"<<"\n"
                 << "2.公司老板"<< endl;
            cin >> newpid;
            Worker *worker = NULL;
            switch(newpid)
            {
                case 1:
                    worker = new employee(newid, newname, newpid);
                    break;
                case 2:
                    worker = new manager(newid, newname, newpid);
                    break;
                case 3:
                    worker = new boss(newid, newname, newpid);
                    break;
                default:
                    break;
            }
            if(worker != NULL)
            {
                this->m_EmpArray[index] = worker;
                cout << "修改成功" << endl;
            }
            else
            {
                cout << "修改失败！请按任意键返回系统" << endl;
            }
        }
        else
        {
            cout << "该员工编号不存在！请按任意键返回系统" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::sortEmp()   //对员工编号进行排序
{
    cout << "请选择排序方式："
         << "\n"
         << "1.升序排序"    //从小到大
         << "\n"
         << "2.降序排序" << endl;   //从大到小
    int select = 1;
    cin >> select;
    if(select==1)   //升序
    {
        int minIndex = 0;
        for (int i = 0; i < this->m_EmpNum - 1; i++)
        {
            minIndex = i;
            for (int j = i+1; j < this->m_EmpNum; j++)
            {
                if(this->m_EmpArray[minIndex]->m_id > this->m_EmpArray[j]->m_id)
                {
                    minIndex = j;
                }
            }
            if(minIndex != i)
            {
                Worker *worker = this->m_EmpArray[minIndex];
                this->m_EmpArray[minIndex] = this->m_EmpArray[i];
                this->m_EmpArray[i] = worker;
            }
        }
    }
    else if(select==2)  //降序
    {
        int maxIndex = 0;
        for (int i = 0; i < this->m_EmpNum - 1; i++)
        {
            maxIndex = i;
            for (int j = i + 1; j < this->m_EmpNum; j++)
            {
                if (this->m_EmpArray[maxIndex]->m_id < this->m_EmpArray[j]->m_id)
                {
                    maxIndex = j;
                }
            }
            if (maxIndex != i)
            {
                Worker *worker = this->m_EmpArray[maxIndex];
                this->m_EmpArray[maxIndex] = this->m_EmpArray[i];
                this->m_EmpArray[i] = worker;
            }
        }
    }
    else
    {
        cout << "排序失败！请选择正确的排序方式" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "排序成功！以下是排序后的信息：" << endl;
    this->showEM();
    system("pause");
    system("cls");
}