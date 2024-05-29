#include <iostream>
#include <vector>
#include "trapezoid.h"
#include "logger.h"

using namespace std;

int main()
{
    Logger logger;
    vector<Trapezium> trapeziums;

    Trapezium trap3("Higest trapezium", 25, 14, 34);
    Trapezium trap1("Trapezium 1", 5, 7, 3);
    Trapezium trap2("Trapezium 2", 6, 8, 4);
    
    trapeziums.push_back(trap3);
    trapeziums.push_back(trap2);
    trapeziums.push_back(trap1);

    logger.AddRecord("Trapezium", trapeziums);

    for (size_t i = 0; i < trapeziums.size(); i++)
    {
        trapeziums[i].GetInformationOfTrapezoid();
    }
    
    FindTrapezoidWithLargestArea(trapeziums);

    return 0;
}
