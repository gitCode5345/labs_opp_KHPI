#include <iostream>
#include <vector>
#include "class_matrix.cpp"

using namespace std;

int main()
{
    Matrix m_matrix(2,2);
    Matrix n(2,2);

    FillMatrix(m_matrix);
    FillMatrix(n);

    Matrix m = m_matrix - n;
    n *= 2;
    n--;

    cout << m << endl;
    cout << "=================================" << endl;
    cout << n << endl;

    return 0;
}
