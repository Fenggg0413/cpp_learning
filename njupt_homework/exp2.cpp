#include<fstream>
#include<iostream>
using namespace std;

void ReadFile(char* s)
{
    ifstream ifs(s);
    char ch;
    while(ifs.get(ch))   //逐字符读取
    {
        cout << ch;
    }
    ifs.close();
}

void Change(char *s1 ,char *s2)
{
    char c;
    ifstream ifs(s1);
    if (!ifs.is_open())
    { // 判断文件是否打开成功
        cout << "Failed to open file " << s1 << endl;
        return;
    }
    ofstream ofs(s2); // 创建新文件
    if (!ofs.is_open())
    { // 判断文件是否创建成功
        cout << "Failed to create file " << s2 << endl;
        ofs.close(); // 关闭原文件
        return;
    }
    while(ifs.get(c))
    {
        if(c>='a' && c<='z')
        {
            c = c - 32;
        }
        ofs.put(c);
    }
    ifs.close();
    ofs.close();
}

int main()
{
    char s1[20], s2[20];
    cin >> s1 >> s2;
    Change(s1, s2);
    ReadFile(s2);
    return 0;
}