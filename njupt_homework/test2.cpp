#include <iostream>
#include <stdlib.h>

using namespace std;

class Matrix
{
    int row = -1, col = -1;
    int m[100] = {};
    int n;

public:
    Matrix(){};

    Matrix(int row, int col) : row(row), col(col)
    {
        cout << "请输入该矩阵元素:" << endl;
        for (int i = 0; i != row * col; i++)
        {
            cin >> m[i];
        }
    };

    void disp();

    Matrix operator+(const Matrix &Matrx)
    {
        if ((Matrx.col != this->col) || (Matrx.row != this->row))
        {
            cout << "program terminated!" << endl;
            ::exit(-1);
        }
        else
        {
            Matrix matr;
            matr.col = Matrx.col;
            matr.row = Matrx.row;
            for (int i = 0; i != row * col; i++)
            {
                matr.m[i] = this->m[i] + Matrx.m[i];
            }
            return matr;
        }
    }

    Matrix &operator=(const Matrix &Matrx)
    {
        if ((this->col == -1 && this->row == -1) || ((Matrx.col == this->col) && (Matrx.row == this->row)))
        {
            if (this->col == -1 && this->row == -1)
            {
                this->col = Matrx.col;
                this->row = Matrx.row;
            }
            for (int i = 0; i != row * col; i++)
            {
                this->m[i] = Matrx.m[i];
            }
            return *this;
        }
        else
        {
            cout << "program terminated!" << endl;
            ::exit(-1);
        }
    }
};

void Matrix::disp()
{
    for (int i = 0; i < row; i++)
    {
        cout << '\t';
        for (int j = 0; j < col; j++)
            cout << *(m + i * col + j) << '\t';
        cout << endl;
    }
}

int main()
{

    int row_a, col_a, row_b, col_b;
    cout << "请输入am矩阵的行数和列数:" << endl;
    cin >> row_a >> col_a;
    Matrix am(row_a, col_a);
    cout << "请输入bm矩阵的行数和列数:" << endl;
    cin >> row_b >> col_b;
    Matrix bm(row_b, col_b), cm;
    cout << "am:" << endl;
    am.disp();
    cout << "bm:" << endl;
    bm.disp();
    cm = am + bm;
    cout << "cm=am+bm:" << endl;
    cm.disp();
    am = bm;
    cout << "am=bm:" << endl;
    am.disp();
    return 0;
}