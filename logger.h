#ifndef LOGGER_H
#define LOGGER_H

#include "trapezoid.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Logger
{
public:
    Logger();
    ~Logger();

    ofstream logFile;
    
    void AddRecord(const string& className, vector<Trapezium>& trapeziums);
};

#endif
