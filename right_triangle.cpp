#include "right_triangle.h"
#include <iostream>

using namespace std;

RightTriangle::RightTriangle(double firstSide, double secondSide) : Pair(firstSide, secondSide) {}

RightTriangle::RightTriangle(Pair& other)
{
    this->SetX(other.GetX());
    this->SetY(other.GetY());
}

double RightTriangle::CalculateHypotenuse()
{
    return sqrt(pow(this->GetX(), 2) + pow(this->GetY(), 2));
}

double RightTriangle::CalculateArea()
{
    return (this->GetX() * this->GetY()) / 2;
}

Pair ModifyPair(Pair& modify, double number)
{
    double x = modify.GetX();
    double y = modify.GetY();

    Pair newModifyPair(x * number, y * number);

    return newModifyPair;
}
