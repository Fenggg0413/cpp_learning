#include <iostream>

#include "large_number.h"

LargeNumber &LargeNumber::operator+(const LargeNumber &lagernumber)
{
}
LargeNumber &LargeNumber::operator+(int num)
{
}

std::ostream &operator<<(std::ostream &out, const LargeNumber &largenumber)
{
    for (int i = largenumber.value.size() - 1; i >= 0; --i)
    {
        out << largenumber.value[i];
    }
    return out;
}

int main()
{
    LargeNumber num("27436902727524587245");
    std::cout << num << std::endl;
}