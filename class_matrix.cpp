#include <iostream>
#include "class_matrix.h"
#include <vector>

using namespace std;

Matrix::Matrix()
{
    cout << "Please enter a positive number of rows and columns" << endl;

    cout << "Rows: ";
    cin >> rows;
    cout << "Columns: ";
    cin >> cols;

    data.resize(rows, vector<double>(cols, 0));
}

Matrix::Matrix(int r, int c) : rows(r), cols(c)
{
    data.resize(rows, vector<double>(cols, 0));
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

int Matrix::GetSizeRows()
{
    return this->rows;
}

int Matrix::GetSizeCols()
{
    return this->cols;
}

double Matrix::GetDataFromMatrix(int i, int j)
{
    return data[i][j];
}

void Matrix::SetDataInMatrix(int i, int j, double number)
{
    data[i][j] = number;
}

void Matrix::SetSizeRows(int rows)
{
    this->rows = rows;
}

void Matrix::SetSizeCols(int cols)
{
    this->cols = cols;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this == &other) return *this;

    rows = other.rows;
    cols = other.cols;
    data = other.data;

    return *this;
}

Matrix Matrix::operator-(Matrix& other)
{
    if (rows != other.rows || cols != other.cols) 
    {
        throw std::invalid_argument("Matrices dimensions must match for subtraction.");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }

    return result;
}

Matrix& Matrix::operator*=(double number)
{
    MultiplyingMatrixNumber(*this, number);

    return *this;
}

Matrix& operator--(Matrix& other)
{
    MakePrefixDecrement(other);

    return other;
}

Matrix& operator--(Matrix& other, int)
{
    MakePostfixDecrement(other, 1);

    return other;
}

Matrix& MakePrefixDecrement(Matrix& a)
{
    double number;

    for (int i = 0; i < a.GetSizeRows(); i++)
    {
        for (int j = 0; j < a.GetSizeCols(); j++)
        {
            number = a.GetDataFromMatrix(i, j);
            number--;
            a.SetDataInMatrix(i, j, number);
        }
    }

    return a;
}

Matrix& MakePostfixDecrement(Matrix& a, int)
{
    MakePrefixDecrement(a);

    return a;
}

Matrix& MultiplyingMatrixNumber(Matrix& other, double num)
{
    double element;

    for (int i = 0; i < other.GetSizeRows(); i++)
    {
        for (int j = 0; j < other.GetSizeCols(); j++)
        {
            element = other.GetDataFromMatrix(i, j);
            element *= num;
            other.SetDataInMatrix(i, j, element);
        }
    }
    
    return other;
}

ostream& operator<<(ostream& os, const Matrix& outData)
{
    for (int i = 0; i < outData.rows; ++i)
    {
        for (int j = 0; j < outData.cols; ++j)
        {
            os << outData.data[i][j] << ' ';
        }
        os << '\n';
    }

    return os;
}

void FillMatrix(Matrix &other)
{
    cout << "Please enter the numbers." << endl << endl;

    for (int i = 0; i < other.rows; i++)
    {
        for (int j = 0; j < other.cols; j++)
        {
            cout << "Enter the numbers for the " << i + 1 << " line " << j + 1 << " column: ";
            cin >> other.data[i][j];
        }
    }
}
