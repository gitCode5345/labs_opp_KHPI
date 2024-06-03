#include "segment.h"
#include <cmath>

Segment::Segment(const pair<double, double>& start, const pair<double, double>& end) : Line({start, end}) {}

double Segment::GetLength() const
{
    double dx = coordinates[1].first - coordinates[0].first;
    double dy = coordinates[1].second - coordinates[0].second;
    return sqrt(dx * dx + dy * dy);
}
