#ifndef MATRIX_H_CLASS
#define MATRIX_H_CLASS

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<double>> data;
    int rows;
    int cols;

public:
    // Конструктори
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix& other);

    int GetSizeRows();
    int GetSizeCols();

    double GetDataFromMatrix(int i, int j);
    void SetDataInMatrix(int i, int j, double number);

    void SetSizeRows(int rows);
    void SetSizeCols(int cols);

   friend void FillMatrix(Matrix &other);

    Matrix& operator=(const Matrix& other);
    Matrix operator-(Matrix& other);
    Matrix& operator*=(double number);

    friend Matrix& operator--(Matrix& other);
    friend Matrix& operator--(Matrix& other, int);
    friend ostream& operator<<(ostream& os, const Matrix& outData);
};

Matrix& MakePrefixDecrement(Matrix& a);
Matrix& MakePostfixDecrement(Matrix& a, int);
Matrix& MultiplyingMatrixNumber(Matrix& other, double num);

#endif
