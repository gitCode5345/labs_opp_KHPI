#ifndef POLYLINE_H
#define POLYLINE_H

#include "line.h"

class Polyline : public Line
{
public:
    Polyline(const vector<pair<double, double>>& coords);
    double GetLength() const override;
};

#endif
