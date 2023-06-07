#pragma once
#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class MyArray
{
private:
    int m_size;     // 数组大小
    int m_capacity; // 数组容量
    T *address;     // 指向数组的指针

public:
    // 构造函数
    MyArray(int capacity)
    {
        //cout << "构造函数已被调用" << endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->address = new T[capacity]; // 在堆区创建新数组使指针指向该数组
    }
    // 拷贝构造函数
    MyArray(const MyArray &p)
    {
        //cout << "拷贝构造函数已被调用" << endl;
        this->m_capacity = p.m_capacity;
        this->m_size = p.m_size;
        // this->address = p.address;  //错误！该赋值会造成浅拷贝问题，即堆区内存重复释放
        this->address = new T[p.m_capacity]; // 深拷贝操作
        // 将p数组中的元素都拷贝过来
        for (int i = 0; i < p.m_capacity; i++)
        {
            this->address[i] = p.address[i];
        }
    }
    // 重载“=”
    MyArray &operator=(const MyArray &p)
    {
        if (this->address != NULL)
        {
            delete[] address;
            address = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }
        //cout << "重载的=已被调用" << endl;
        this->m_capacity = p.m_capacity;
        this->m_size = p.m_size;
        this->address = new T[p.m_capacity];
        for (int i = 0; i < p.m_size; i++)
        {
            this->address[i] = p.address[i];
        }
        return *this;
    }
    // 析构函数
    ~MyArray()
    {
        if (this->address != NULL)
        {
            //cout << "析构函数已被调用" << endl;
            delete[] this->address; // 析构时释放堆区数据
            this->address = NULL;
        }
    }
    // 尾插
    void pushBack(const T &val)
    {
        if (this->m_capacity == this->m_size)
        {
            cout << "数组容量达到最大，无法再新添加元素" << endl;
            return;
        }
        this->address[this->m_size++] = val;
    }
    // 尾删
    void popBack()
    {
        if (this->m_size == 0)
        {
            cout << "删除失败" << endl;
            return;
        }
        this->m_size--;
    }
    // 通过下标读取数组内容
    T &operator[](int index)    //返回引用可以作为左值调用
    {
        if (index > this->m_size)
        {
            cout << "读取失败！请勿越界访问" << endl;
            system("pause");
            exit(0);
        }
        return this->address[index];
    }

    int getSize()
    {
        return this->m_size;
    }

    int getCapacity()
    {
        return this->m_capacity;
    }

    void setCapacity(int capacity)
    {
        this->m_capacity = capacity;
    }

    void showArray()
    {
        cout << "[";
        for (int i = 0; i < this->m_size;i++)
        {
            cout << this->address[i];
            if(i<this->m_size-1)
            {
                cout << " ";
            }
        }
        cout << "]"<<endl;
    }
};
