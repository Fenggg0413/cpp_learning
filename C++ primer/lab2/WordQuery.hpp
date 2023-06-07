#ifndef __WORDQUERY_H
#define __WORDQUERY_H
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include "VecStr.h"
using namespace std;
#endif
class QueryResult
{
    friend void printInfo(ostream &os, const QueryResult &qr);

private:
    string word;
    shared_ptr<set<size_t>> wordQuerySet;
    shared_ptr<StrVec> textFile;

public:
    QueryResult(string w, shared_ptr<set<size_t>> s, shared_ptr<StrVec> v)
        : word(w), wordQuerySet(s), textFile(v) {}
    QueryResult() = default;
};
class TextQuerie
{
public:
    TextQuerie(ifstream &input) : textPtr(new StrVec) // 初始化shared_ptr
    {
        string line;
        while (getline(input, line))
        {
            textPtr->push_back(line);
            size_t n = textPtr->size(); // 设置当前的行号
            istringstream iline(line);
            string word;
            while (iline >> word)
            {
                auto &iter = textMap[word]; // iter是一个shared_ptr
                if (!iter)
                {
                    iter.reset(new set<size_t>); // 如果该ptr是空指针，则分配一个新的set给iter
                }
                else
                {
                    iter->insert(n);
                }
            }
        }
    }
    QueryResult query(const string &word) const // 查询word并返回结果
    {
        static shared_ptr<set<size_t>> nodata(new set<size_t>);
        auto res = textMap.find(word);
        if (res != textMap.end()) // 找到
        {
            return QueryResult(word, res->second, textPtr);
        }
        else // 没找到
        {
            return QueryResult(word, nodata, textPtr);
        }
    }

private:
    shared_ptr<StrVec> textPtr; // 智能指针记得初始化后再使用
    map<string, shared_ptr<set<size_t>>> textMap;
};
void runQueries(ifstream &input)
{
    TextQuerie tq(input);
    while (true)
    {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || (s == "q"))
        {
            break;
        }
        else
        {
            printInfo(std::cout, tq.query(s));
        }
    }
}
void printInfo(ostream &os, const QueryResult &qr) // ostream参数方便将数据存入文件
{
    os << qr.word << " occurs " << qr.wordQuerySet->size()
       << ((qr.wordQuerySet->size() > 1) ? " times: " : " time: ") << endl; // 打印单词出现的次数
    if (qr.wordQuerySet->begin() == qr.wordQuerySet->end())                 // 如果没找到单词
    {
        os << "Query fail, No such word!" << endl;
    }
    else
    {
        for (auto &val : *qr.wordQuerySet) // 打印set中的每一行
        {
            os << "\t(line " << val << " )\t" << *(qr.textFile->begin() + (val - 1)) << "\n";
        }
        os << endl;
    }
}