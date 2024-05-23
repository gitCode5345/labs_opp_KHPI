#include <iostream>
#include "point_class.h"
#include <fstream>

using namespace std;

Point::Point(double x, double y) : x(x), y(y) {}

ostream& operator<<(ostream& os, const Point& osPoint)
{
    cout << "(" << osPoint.x << ", " << osPoint.y << ")";
    return os;
}
