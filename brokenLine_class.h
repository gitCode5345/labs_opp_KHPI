#ifndef BROKEN_LINE_H
#define BROKEN_LINE_H

#include <iostream>
#include "point_class.h"

using namespace std;

class BrokenLine
{
    public:
        BrokenLine();
        BrokenLine(vector<Point> pts);
        BrokenLine(const BrokenLine& other);
        ~BrokenLine();

        void AddPoint(const Point& points);
        void InsertPoint(const Point& pnt, int index);
        void RemovePoint(int index);
        int getNumberOfPoints();
        Point& operator[](int index);
        void operator()();
        friend ostream& operator<<(ostream& os, const BrokenLine& chain);
        friend fstream& operator>>(fstream& fs, const BrokenLine& fsChain);

    private:
        vector<Point> vecPoints;
};

#endif
