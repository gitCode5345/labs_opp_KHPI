#include <iostream>
#include "pair.cpp"
#include "right_triangle.cpp"

using namespace std;

int main()
{
    Pair classPair(12,9);
    RightTriangle triangle(classPair);

    classPair = ModifyPair(triangle, 2);
    triangle = classPair;

    cout << "First side: " << triangle.GetX() << endl;
    cout << "Second side: " << triangle.GetY() << endl;

    cout << "===============================================" << endl;

    cout << "Product of numbers: " << classPair.GetX() << " and " << classPair.GetY() << " = " << classPair.CalculateProductNumbers() << endl << endl;
    cout << "Gipotenus of triangle with catets " << triangle.GetX() << " and " << triangle.GetY() << " = " << triangle.CalculateHypotenuse() << endl << endl;
    cout << "Area of triangle with catets " << triangle.GetX() << " and " << triangle.GetY() << " = " << triangle.CalculateArea() << endl << endl;
    cout << "Product of catets of triangle = " << triangle.CalculateProductNumbers() << endl << endl;

    return 0;
}
