#include "line.h"

Line::Line(const vector<pair<double, double>>& coords) : coordinates(coords) {}

vector<pair<double, double>> Line::GetCoordinates() const
{
    return coordinates;
}
