#pragma once

#include <vector>
#include <iostream>
#include <string>

class LargeNumber
{
public:
  LargeNumber() = default;
  LargeNumber(const std::string &val)
  {
    for (int i = val.size() - 1; i >= 0; --i)
    {
      auto ch = val[i];
      value.push_back(ch - '0');
    }
    std::cout << std::endl;
  }
  LargeNumber(const LargeNumber &largenumber) = default;
  ~LargeNumber() = default;
  LargeNumber &operator+(const LargeNumber &largenumber);
  LargeNumber &operator+(int num);
  LargeNumber &operator-(const LargeNumber &largenumber);
  LargeNumber &operator-(int num);
  LargeNumber &operator*(const LargeNumber &largenumber);
  LargeNumber &operator*(int num);
  LargeNumber &operator/(const LargeNumber &largenumber);
  LargeNumber &operator/(int num);
  LargeNumber &operator=(const LargeNumber &largenumber)
  {
    this->value = largenumber.value;
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &out, const LargeNumber &largenumber);

private:
  std::vector<int> value;
};

std::ostream &operator<<(std::ostream &out, const LargeNumber &largenumber);