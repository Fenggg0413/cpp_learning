#ifndef __VECSTR_H
#define __VECSTR_H
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#endif

class StrVec
{
private:
    std::string *element; // 指向第一个元素
    std::string *first_free;
    std::string *cap; // 指向尾后元素
    static std::allocator<std::string> alloc;
    void reallocate(); // 重新分配capacity
    void free();       // 释放所有内存
    void chk_n_alloc() // 检查alloc的大小是否够用，如果不够用则调用reallocate重新分配内存
    {
        if (size() == capacity())
            reallocate();
    }
    // 拷贝时使用，将一个指针范围的内容拷贝到另一个序列中，返回一个pair，
    // fisrt元素为目标序列的首元素，second为目标序列最后一个元素的后一个位置
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);

public:
    StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string> list);
    StrVec(const StrVec &sv);
    StrVec &operator=(const StrVec &sv);
    ~StrVec();
    void push_back(const std::string &str);
    void resize(std::size_t sz, const std::string &str);
    void reserve(std::size_t sz);
    std::size_t size() const
    {
        return first_free - element;
    }
    std::size_t capacity() const
    {
        return cap - element;
    }
    auto begin() const -> std::string *
    {
        return element;
    }
    auto end() const -> std::string *
    {
        return cap;
    }
};