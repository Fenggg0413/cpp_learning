#include "WordQuery.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifs("test.txt");
    if(!ifs.is_open())
    {
        std::cout << "File open fail!" << endl;
        exit(-1);
    }
    runQueries(ifs);
    ifs.close();
}
