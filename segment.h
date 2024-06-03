#ifndef SEGMENT_H
#define SEGMENT_H

#include "line.h"

class Segment : public Line
{
public:
    Segment(const pair<double, double>& start, const pair<double, double>& end);
    double GetLength() const override;
};

#endif
