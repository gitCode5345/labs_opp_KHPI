#include "pair.h"
#include <iostream>

using namespace std;

Pair::Pair(double x, double y) : x(x), y(y) {}

double Pair::GetX()
{
    return this->x;
}

double Pair::GetY()
{
    return this->y;
}

void Pair::SetX(double number)
{
    this->x = number;
}

void Pair::SetY(double number)
{
    this->y = number;
}

double Pair::CalculateProductNumbers()
{
    return this->x * this->y;
}
