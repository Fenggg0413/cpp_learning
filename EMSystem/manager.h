#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

class manager : public Worker
{
    public:
        manager(int uid=0, string name = "unnamed", int uDeptid=0);
        ~manager();
        void showInfo();
        string getDeptName();
};