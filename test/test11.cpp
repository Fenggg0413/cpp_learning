#include<iostream>
#include<iomanip>

int main()
{
    int n;
    while (std::cin >> n)
    {
        int arr[n][n], i, j;
        for(i = 0; i < n; ++i)  //初始化每行的首元素和末元素
        {
            arr[i][0] = 1;
            arr[i][i] = 1;
        }
        for(i = 2; i < n; ++i)  //初始化数组
        {
            for (j = 1; j <= i - 1; ++j)
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j <= i; ++j)
                std::cout << std::setw(5) <<arr[i][j];
            std::cout << '\n';
        }
        std::cout << std::endl;
    }
}