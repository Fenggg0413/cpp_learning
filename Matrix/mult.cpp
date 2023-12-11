#include <vector>
#include <iostream>
#include <utility>

std::vector<std::vector<int>> multiplyMat(std::vector<std::vector<int>> mat1, std::vector<std::vector<int>> mat2)
{
    int m = mat1.size();
    int n = mat2[0].size();
    int s1 = mat1[0].size();
    int s2 = mat2.size();
    if (s1 != s2)
        throw("can not multiply matrix!");
    std::vector<std::vector<int>> newMat{};
    for (int i = 0; i < m; ++i)
    {
        newMat.push_back({});
        for (int j = 0; j < m; ++j)
            newMat[i].push_back(0); // 初始化矩阵
    }
    std::cout << "------------------------------------\n";
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int val{};
            for (int k = 0; k < s1; ++k)
                val += mat1[i][k] * mat2[k][j];
            newMat[i][j] = val;
        }
    }
    return std::move(newMat);
}

int main()
{
    int m{}, n{};
    std::cout << "mat1: \n";
    std::cin >> m >> n;
    std::vector<std::vector<int>> mat1{};
    for (int i = 0; i < m; ++i)
    {
        mat1.push_back({});
        for (int j = 0; j < n; ++j)
        {
            int val;
            std::cin >> val;
            mat1[i].push_back(val);
        }
    }
    std::cout << "mat2: \n";
    std::cin >> m >> n;
    std::vector<std::vector<int>> mat2{};
    for (int i = 0; i < m; ++i)
    {
        mat2.push_back({});
        for (int j = 0; j < n; ++j)
        {
            int val;
            std::cin >> val;
            mat2[i].push_back(val);
        }
    }

    auto newMat = multiplyMat(mat1, mat2);
    for (auto cow : newMat)
    {
        for (auto val : cow)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}