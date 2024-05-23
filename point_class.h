#ifndef POINT_H_CLASS_CPP
#define POINT_H_CLASS_CPP

#include <iostream>
#include <fstream>

using namespace std;

class Point
{
public:
    Point(double x = 0, double y = 0);

    friend ostream& operator<<(ostream& os, const Point& osPoint);
    
private:
    double x, y;
};

#endif
