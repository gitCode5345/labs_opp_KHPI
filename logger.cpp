#include "logger.h"
#include "trapezoid.h"
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

Logger::Logger() 
{
    logFile.open("log.txt", ios::out | ios::app);
    logFile << "ClassName: Trapezium" << endl;
}

Logger::~Logger()
{
    logFile.close();
}

void Logger::AddRecord(const string& className, vector<Trapezium>& trapeziums)
{
    time_t now = time(0);
    tm* localTime = localtime(&now);

    if (this->logFile.is_open())
    {
        logFile << "ClassName: " << className << " numberOfEntities: " << Trapezium::GetCount() << endl;
        logFile << "time: " << 1900 + localTime->tm_year << '.' << 1 + localTime->tm_mon << '.' << localTime->tm_mday << ' '
                << localTime->tm_hour << ':' << localTime->tm_min << ':' << localTime->tm_sec << endl;

        for (auto& trap : trapeziums)
        {
            logFile << "object Name: " << trap.GetObjectName() << endl;
            logFile << "object Area: " << trap.CountArea() << " object Perimeter: " << trap.CountPerimetr() << endl;
        }
    }
    else
    {
        cout << "Error writing to log file!" << endl;
    }
}
