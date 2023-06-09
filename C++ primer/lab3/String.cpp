#include"String.h"
#include<memory>
#include<iostream>

String::String(const char *ps)
{
    char *s1 = const_cast<char *>(ps);
    while(*s1)
        ++s1;
    range_initializer(ps, s1);
}

void String::range_initializer(const char *first, const char *last)
{
    auto newstr = copy_String(first, last);
    beg = newstr.first;
    first_free = newstr.second;
    cap = newstr.second;
}

String::~String()
{
    free();
}

void String::free()
{
    if(beg)
    {
        while(first_free != beg)
        {
            alloca.destroy(--first_free);
        }
        alloca.deallocate(beg, capacity());
    }
}

inline void String::move_String(std::size_t sz)
{
    auto data = alloca.allocate(sz);
    auto dest = data;  //存放新的first_free
    auto elem = beg;
    while(elem != first_free)
    {
        alloca.construct(dest++, *(elem++));
    }
    free();
    beg = data;
    first_free = dest;
    cap = data + sz;
}

inline void String::realloca()
{
    auto newCapacity = size() ? size() * 2 : 1;
    move_String(newCapacity);
}

inline void String::chk_cap()
{
    if(size() == capacity())
        realloca();
}

std::pair<char *, char *> String::copy_String(const char *beg, const char *end)
{
    auto data = alloca.allocate(end - beg);
    return {data, std::uninitialized_copy(beg, end, data)};
}

String::String(const String &s)
{
    range_initializer(s.beg, s.first_free);
    std::cout << "copy" << std::endl;
}

String::String(String &&s) noexcept
: beg(s.beg), first_free(s.first_free), cap(s.cap)
{
    std::cout << "move" << std::endl;
    s.beg = s.first_free = s.cap = nullptr;
}

String &String::operator=(const String &s) 
{
    auto pa = copy_String(s.beg, s.first_free);
    free();
    beg = pa.first;
    first_free = pa.second;
    cap = pa.second;
    std::cout << "copy =" << std::endl;
    return *this;
}

String &String::operator=(String &&s) noexcept
{
    if(this != &s) //检擦是否是自我赋值
    {
        free();   //释放掉等号左边的元素
        beg = s.beg;
        first_free = s.first_free;
        cap = s.cap;
        s.beg = s.first_free = s.cap = nullptr;
    }
    std::cout << "move =" << std::endl;
    return *this;
}

void String::print() const
{
    for (auto i = beg; i != first_free; ++i)
    {
        std::cout << *i;
    }
}
