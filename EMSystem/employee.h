#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

class employee : public Worker
{
    public:
        employee(int uid=0, string name = "unnamed", int uDeptid=0);
        ~employee();
        void showInfo();
        string getDeptName();
};