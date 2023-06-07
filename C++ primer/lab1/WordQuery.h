#ifndef __WORDQUERY_H
#define __WORDQUERY_H
#include <memory>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
#endif
class QueryResult
{
    friend void printInfo(ostream &os, const QueryResult &qr);
private:
    string word;          //要查询的单词
    shared_ptr<set<size_t>> wordQuerySet;  //查询单词出现的行数
    shared_ptr<vector<string>> textFile;    //保存文件数据的字符串
public:
    QueryResult(string w, shared_ptr<set<size_t>> s, shared_ptr<vector<string>> v)
        : word(w), wordQuerySet(s), textFile(v) {}
    set<size_t>::iterator begin() const;
    set<size_t>::iterator end() const;
    shared_ptr<vector<string>> get_file() const;
};
class TextQuery
{
private:
    shared_ptr<vector<string>> textPtr;
    map<string, shared_ptr<set<size_t>>> textMap;

public:
    TextQuery(ifstream &input);
    QueryResult query(const string &word) const;
};
void runQueries(ifstream &input);
void printInfo(ostream &os, const QueryResult &qr);