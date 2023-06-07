#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

class boss : public Worker
{
    public:
        boss(int uid=0, string name = "unnamed", int uDeptid=0);
        ~boss();
        void showInfo();
        string getDeptName();
};