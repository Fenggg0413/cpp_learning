#include <vector>
#include <iostream>

class Matrix
{
private:
    ::std::vector<::std::vector<double>> matrix;

public:
    Matrix(int row, int col)
    {
        for (int i = 0; i < row; ++i)
        {
            double val;
            std::vector<double> r;
            for (int j = 0; j < col; ++j)
            {
                std::cin >> val;
                r.push_back(val);
            }
            matrix.push_back(r);
        }
    }

    void printInfo()
    {
        std::cout << "The matrix is:\n";
        for (const auto &row : matrix)
        {
            for(const auto &val : row)
                std::cout << val << "\t";
            std::cout << "\n";
        }
        std::cout << std::endl;
    }

    void rowEchelonForm()
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int lead = 0;

        for (int r = 0; r < rows; ++r)
        {
            
        }
    }
};

int main()
{
    int row, col;
    std::cout << "row: ";
    std::cin >> row;
    std::cout << "col: ";
    std::cin >> col;
    Matrix mat(row, col);
    mat.printInfo();
    return 0;
}