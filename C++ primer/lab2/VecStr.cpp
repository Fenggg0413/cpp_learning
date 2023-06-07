#include"VecStr.h"
#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>

StrVec::StrVec(std::initializer_list<std::string> list)
    : element(nullptr), first_free(nullptr), cap(nullptr)
{
    for (auto beg = list.begin(); beg != list.end(); ++beg)
    {
        push_back(*beg);
    }
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *beg, const std::string *end)
{
    auto data = alloc.allocate(end - beg);
    return {data, std::uninitialized_copy(beg, end, data)};
}

StrVec::StrVec(const StrVec &sv)
{
    auto p = alloc_n_copy(sv.element, sv.first_free);
    element = p.first;
    first_free = p.second;
    cap = p.second;
}

StrVec &StrVec::operator=(const StrVec &sv)
{
    auto p = alloc_n_copy(sv.element, sv.first_free);
    free();
    element = p.first;
    first_free = p.second;
    cap = p.second;
    return *this;
}

void StrVec::push_back(const std::string &str)
{
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

void StrVec::free()
{
    if (element)
    {
        for (auto beg = first_free; beg != element;)
        {
            alloc.destroy(--beg); // 先对每个对象调用destroy析构掉
        }
        alloc.deallocate(element, capacity());
    }
}

StrVec::~StrVec()
{
    free();
}

void StrVec::reallocate()
{
    auto newCapacity = size() ? 2 * capacity() : 1;
    auto newdata = alloc.allocate(newCapacity); // newdata是新内存的位置
    auto dest = newdata;                        // dest指向每一个新内存的位置
    auto elem = element;                        // elem指向每一个旧内存的位置
    for (std::size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++)); // 用move可以避免再次拷贝，优化性能
    }
    free(); // 移动完元素后就要释放旧内存
    element = newdata;
    first_free = dest;
    cap = element + newCapacity;
}

void StrVec::reserve(size_t sz) // 分配至少能容纳sz个元素的内存空间
{
    if (sz > capacity())
    {
        auto newdata = alloc.allocate(sz);
        auto dest = newdata; // dest指向每一个新内存的位置
        auto elem = element; // elem指向每一个旧内存的位置
        for (std::size_t i = 0; i != size(); ++i)
        {
            alloc.construct(dest++, std::move(*elem++)); // 用move可以避免再次拷贝，优化性能
        }
        free(); // 移动完元素后就要释放旧内存
        element = newdata;
        first_free = dest;
        cap = element + sz;
    }
}
void StrVec::resize(std::size_t sz, const std::string &str)
{
    auto new_first_free = element + sz;
    if (sz >= size())
    {
        reserve(sz);
        while (first_free != new_first_free)
        {
            alloc.construct(first_free++, std::move(str));
        }
    }
    else // size减少后，capacity不应该改变
    {
        while (first_free != new_first_free)
        {
            alloc.destroy(--first_free);
        }
    }
}
