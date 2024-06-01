#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include <iostream>
#include "pair.h"
#include <cmath>

using namespace std;

class RightTriangle : public Pair
{
private:
    
public:
    RightTriangle(double firstSide = 0, double secondSide = 0);
    RightTriangle(Pair& other);

    double CalculateHypotenuse();
    double CalculateArea();
    friend Pair ModifyPair(Pair& modify, double number);
};

#endif
