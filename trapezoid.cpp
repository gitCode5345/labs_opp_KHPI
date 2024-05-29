#include "logger.h"
#include "trapezoid.h"
#include <iostream>

using namespace std;

int Trapezium::count = 0;

Trapezium::Trapezium()
{
    this->sideA = 0;
    this->sideB = 0;
    this->height = 0;
    this->objectName = "";
}

Trapezium::Trapezium(string name, double a, double b, double h) : objectName(name), sideA(a), sideB(b), height(h)
{
    count++;
}

Trapezium::~Trapezium()
{
    count--;
}

int Trapezium::GetCount()
{
    return count;
}

string Trapezium::GetObjectName()
{
    return this->objectName;
}

void Trapezium::SetObjectName(string name)
{
    this->objectName = name;
}

void AddStory(const string& action)
{
    Logger log;
    time_t now = time(0);
    tm* localTime = localtime(&now);

    if (!log.logFile)
    {
        cout << "Unfortunately, writing history to a file is not available." << endl;

        return;
    }
    
    log.logFile << "Action performed: " << action << "\n"
                << "time: " << 1900 + localTime->tm_year << '.' << 1 + localTime->tm_mon << '.' << localTime->tm_mday << ' '
                << localTime->tm_hour << ':' << localTime->tm_min << ':' << localTime->tm_sec << endl << endl; 
}


double Trapezium::CountArea()
{
    AddStory("The area is calculated");

    return (sideA + sideB) * height / 2;
}

double Trapezium::CountPerimetr()
{
    AddStory("The perimetr is calculated");
    
    return sideA + sideB + 2 * sqrt(height * height + pow((sideB - sideA) / 2, 2));
}

void Trapezium::GetInformationOfTrapezoid()
{
    cout << "Name of trapezoid: " << this->GetObjectName() << "\n"
         << "Dimensions of sides and height: "
         << "Size A: " << this->sideA << " "
         << "Size B: " << this->sideB << " "
         << "Height: " << this->height << " " << "\n"
         << "Perimetr of trapezoid: " << this->CountPerimetr() << "\n"
         << "Area of trapezoid: " << this->CountArea() << endl << endl;
}

void FindTrapezoidWithLargestArea(vector<Trapezium> &tr)
{
    Trapezium largestTrap;

    for (size_t i = 0; i < tr.size(); i++)
    {
        if (largestTrap.CountArea() < tr[i].CountArea())
        {
            largestTrap = tr[i];
        }
        
    }
    
    cout << "The largest trapezoid has been found, and here is information about it: " << endl << endl;
    largestTrap.GetInformationOfTrapezoid();
    AddStory("The largest area of the trapezoid was found");
}
