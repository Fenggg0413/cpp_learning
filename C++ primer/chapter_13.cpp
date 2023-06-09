#include<iostream>
#include<string>
#include<memory>
#include<utility>
#include<initializer_list>
#include<algorithm>
class HasPtr
{
private:
    std::size_t *num;
    std::string *s;
    int i;
public:
    HasPtr(const std::string &str = std::string())
    :s(new std::string(str)), num(new std::size_t(1)), i(0) {}
    HasPtr(const HasPtr &hp);
    ~HasPtr();
    HasPtr &operator=(const HasPtr &hp);
};

HasPtr::HasPtr(const HasPtr &hp):num(hp.num), s(hp.s), i(hp.i)
{
    ++(*num);
}

HasPtr::~HasPtr()   //如果计数器为0，则delete掉num和s
{
    if(--(*num) == 0)
    {
        delete num;
        delete s;
    }
}

HasPtr &HasPtr::operator=(const HasPtr &hp) //将右边的赋给左边的，则右边的计数器++，左边的--
{
    ++*hp.num;
    if (--*num == 0)
    {
        delete num;
        delete s;
    }
    num = hp.num;
    i = hp.i;
    s = hp.s;
    return *this;
}



//自定义的vector<string>
class StrVec
{
private:
    std::string *element; //指向第一个元素
    std::string *first_free; 
    std::string *cap;  //指向尾后元素
    static std::allocator<std::string> alloc;
    void reallocate(); //重新分配capacity
    void free();       //释放所有内存
    void chk_n_alloc() // 检查alloc的大小是否够用，如果不够用则调用reallocate重新分配内存
    {
        if(size() == capacity())
            reallocate();
    }
    //拷贝时使用，将一个指针范围的内容拷贝到另一个序列中，返回一个pair，
    //fisrt元素为目标序列的首元素，second为目标序列最后一个元素的后一个位置
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);

public:
    StrVec(): element(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string> list); 
    StrVec(const StrVec &sv);
    StrVec &operator=(const StrVec &sv);
    ~StrVec();
    void push_back(const std::string &str);
    void resize(std::size_t sz, const std::string &str= std::string());
    void reserve(std::size_t sz); 
    std::size_t size() const
    {
        return first_free - element;
    }
    std::size_t capacity() const
    {
        return cap - element;
    }
    auto begin() const -> std::string*
    {
        return element;
    }
    auto end() const -> std::string*
    {
        return cap;
    }
};
StrVec::StrVec(std::initializer_list<std::string> list)
:element(nullptr), first_free(nullptr), cap(nullptr)
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
    if(element)
    {
        std::for_each(element, first_free, [this](std::string &s)
                      { alloc.destroy(&s); });
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
    auto newdata = alloc.allocate(newCapacity); //newdata是新内存的位置
    auto dest = newdata; //dest指向每一个新内存的位置
    auto elem = element; //elem指向每一个旧内存的位置
    for (std::size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));  //用move可以避免再次拷贝，优化性能
    }
    free(); //移动完元素后就要释放旧内存
    element = newdata;
    first_free = dest;
    cap = element + newCapacity;
}

void StrVec::reserve(size_t sz)   //分配至少能容纳sz个元素的内存空间
{
    if(sz > capacity())
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
void StrVec::resize(std::size_t sz, const std::string &str= std::string())
{
    auto new_first_free = element + sz;
    if(sz >= size())
    {
        reserve(sz);
        while (first_free != new_first_free)
        {
            alloc.construct(first_free++, std::move(str));
        }
    }
    else      //size减少后，capacity不应该改变
    {
        while(first_free != new_first_free)
        {
            alloc.destroy(--first_free);
        }
    }
}


