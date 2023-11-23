#include <iostream>

struct MyStruct
{
    MyStruct()
    {
        std::cout << "constructor!" << std::endl;
    }
    MyStruct(MyStruct &)
    {
        std::cout << "copy!" << std::endl;
    }
    MyStruct(MyStruct &&)
    {
        std::cout << "move!" << std::endl;
    }
    /* data */
};

MyStruct foo()
{
    MyStruct ms;
    return ms;
}

void foo(MyStruct ms)
{
    std::cout << "--------------" << std::endl;
}

int main()
{
    auto ms = foo();
    //foo(ms);
    foo({});
    // foo();
    return 0;
}
