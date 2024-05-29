#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <string>
#include <vector>
#include <string>

using namespace std;

class Trapezium
{
private:
    static int count;
    string objectName;
    double sideA;
    double sideB;
    double height;
    

public:
    Trapezium();
    Trapezium(string name, double a, double b, double h);
    ~Trapezium();

    static int GetCount();
    void SetObjectName(string name);
    string GetObjectName();
    double CountArea();
    double CountPerimetr();
    void GetInformationOfTrapezoid();
    friend void FindTrapezoidWithLargestArea(vector<Trapezium> &tr);
    friend void AddStory(const string& action);
};

#endif
