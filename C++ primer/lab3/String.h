#pragma once
#include<memory>
#include<utility>

class String
{
private:
    char *beg;
    char *first_free;
    char *cap;
    std::allocator<char> alloca;
    void realloca();
    void chk_cap();
    std::pair<char *, char *> copy_String(const char *, const char *);
    void move_String(std::size_t sz);

public:
    String():beg(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *ps);
    String(const String &s);    //拷贝构造函数
    String(String &&s) noexcept;         //移动构造函数
    String &operator=(const String &s);   //拷贝赋值运算符
    String &operator=(String &&s) noexcept;        //移动赋值运算符
    ~String();
    void free();
    char *begin(){
        return beg;
    }
    char *end(){
        return first_free;
    }
    std::size_t size(){
        return first_free - beg;
    }
    std::size_t capacity(){
        return cap - beg;
    }
    void print() const;
    void range_initializer(const char *first, const char *last);
};