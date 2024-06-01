#ifndef PAIR_H
#define PAIR_H

class Pair
{
private:
    double x;
    double y;

public:
    Pair(double x = 0, double y = 0);

    double GetX();
    void SetX(double number);

    double GetY();
    void SetY(double number);

    double CalculateProductNumbers();

};

#endif
