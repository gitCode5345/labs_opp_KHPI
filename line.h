#ifndef LINE_H
#define LINE_H

#include <vector>

using namespace std;

class Line
{
protected:
    vector<pair<double, double>> coordinates;

public:
    Line(const vector<pair<double, double>>& coords);
    virtual ~Line() = default;

    virtual double GetLength() const = 0;

    vector<pair<double, double>> GetCoordinates() const;
};

#endif // LINE_H
