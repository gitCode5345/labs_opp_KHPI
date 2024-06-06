#include <iostream>
#include "brokenLine_class.h"
#include <vector>

using namespace std;

BrokenLine::BrokenLine() : vecPoints(0) {}

BrokenLine::BrokenLine(std::vector<Point> pts) : vecPoints(pts) {}

BrokenLine::BrokenLine(const BrokenLine& other) : vecPoints(other.vecPoints) {}

BrokenLine::~BrokenLine()
{
    std::cout << "The destructor has started working" << std::endl;
}

void BrokenLine::RemovePoint(int index)
{
    if (index >= 0 && index < vecPoints.size())
        vecPoints.erase(vecPoints.begin() + index);
    else
        cout << "Sorry, you entered an incorrect index" << endl;
}

int BrokenLine::getNumberOfPoints()
{
    return vecPoints.size();
}

void BrokenLine::AddPoint(const Point& points)
{
    vecPoints.push_back(points);
}

void BrokenLine::InsertPoint(const Point& pnt, int index)
{
    if (index >= 0 && index <= vecPoints.size() - 1)
    {
        vecPoints.insert(vecPoints.begin() + index, pnt);
    }

    else
    {
        cout << "Please specify the correct location for the point" << endl;
    }
}

Point& BrokenLine::operator[](int index)
{
    return vecPoints[index];
}

void BrokenLine::operator()()
{
    cout << "Number of points: " << this->getNumberOfPoints() << endl;
    for (const Point& point : vecPoints) 
        cout << point << endl;
}

ostream& operator<<(ostream& out, const BrokenLine& chain)
{
    for (const Point& point : chain.vecPoints)
        out << point << endl;

    return out;
}
