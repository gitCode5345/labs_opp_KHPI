#include "polyline.h"
#include <cmath>

Polyline::Polyline(const vector<pair<double, double>>& coords) : Line(coords) {}

double Polyline::GetLength() const
{
    double totalLength = 0.0;

    for (size_t i = 1; i < coordinates.size(); ++i)
    {
        double dx = coordinates[i].first - coordinates[i - 1].first;
        double dy = coordinates[i].second - coordinates[i - 1].second;
        totalLength += sqrt(dx * dx + dy * dy);
    }

    return totalLength;
}
