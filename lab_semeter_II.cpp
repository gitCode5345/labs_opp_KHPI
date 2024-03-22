#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

struct Movie
{
    string nameOfMovie;
    string director;
    int year;
    string country;
};

vector<Movie> movies;

time_t myTime = time(NULL);
tm *currentTime = localtime(&myTime);
string nowTime = " Time: " + to_string(currentTime->tm_hour) + ":" + to_string(currentTime->tm_min) + ":" + to_string(currentTime->tm_sec) + "\n";

int menu();
void ReadFromFile();
void WriteToFile();
void WriteHistoryAction(string historyActions);
void ReadHistoryAction();
void AddElement();
void PrintData();
void SortByMovieTitle();
void DeleteElement();
void ChangeElement();

int main()
{
    while (true)
    {
        switch (menu())
        {

        case 1:
            WriteToFile();
            break;

        case 2:
            ReadFromFile();
            break;

        case 3:
            SortByMovieTitle();
            break;

        case 4:
            AddElement();
            break;

        case 5:
            DeleteElement();
            break;

        case 6:
            ChangeElement();
            break;

        case 7:
            PrintData();
            break;

        case 8:
            ReadHistoryAction();
            break;
        case 9:
            
            return 0;
            
        default:
            cout << "Enter the correct information" << endl;
            break;
        }
    }

    return 0;
}

int menu()
{
    int value;
    cout << "Select an action" << endl;
    cout << endl;

    cout << "1. Write information to a file\n2. Read information from a file\n3. Sort information by movie title\n4. Add element\n5. Delete element\n6. Change information in an element\n7. Output data about movies\n8. View action history \n9. Close the program" << endl;
    cin >> value;

    return value;
}

void WriteToFile()
{
    if (movies.empty())
    {
        cout << "There is no recorded data on the films." << endl;
        return;
    }

    string path;
    cout << "Specify the path to the file" << endl;
    cin >> path;

    if (path == "consoleData.txt")
    {
        cout << "Not allowed" << endl;
        return;
    }
    
    ofstream ofFile(path, ios::binary | ios::out);

    if (!ofFile)
    {
        cout << "Error opening file" << endl;
        return;
    }

    for (auto &mov : movies)
    {
        ofFile.write(reinterpret_cast<const char*>(&mov), sizeof(mov));
    }

    ofFile << endl;

    cout << "Information successfully saved to file" << nowTime << endl;
    WriteHistoryAction("Information successfully saved to file" + nowTime);

    ofFile.close();
}

void AddElement()
{
    bool correctInput = false;
    
    cout << "Add a new item" << endl;
    Movie element;

    cout << "Name of movie: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, element.nameOfMovie);

    cout << "Country of publishing: ";
    getline(cin, element.country);

    cout << "Name of the director: ";
    getline(cin, element.director);

    cout << "Year: ";

    while (!correctInput)
    {
        cin >> element.year;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Try again: ";
        }
        else
        {
            correctInput = true;
        }
        
    }

    cout << endl;

    movies.push_back(element);
    cout << "New item added successfully" << nowTime << endl;
    WriteHistoryAction("New item added successfully" + nowTime);

}

void ReadFromFile()
{
    string path;
    cout << "Specify the path to the file" << endl;
    cin >> path;

    if (path == "consoleData.txt")
    {
        cout << "Not allowed" << endl;
        return;
    }

    ifstream ifFile;
    
    ifFile.open(path, ios::binary | ios::in);

    if(!ifFile)
    {
        cout << "Error opening file" << endl;
        return;
    }
    else if (ifFile.eof())
    {
        cout << "File is empty" << endl;
        return;
    }

    movies.clear();
    
    Movie currentMovie;
    while (ifFile.read(reinterpret_cast<char*>(&currentMovie), sizeof(currentMovie)))
    {
        movies.push_back(currentMovie);
    }

    cout << "The file was read successfully" << nowTime << endl;

    WriteHistoryAction("The file was read successfully" + nowTime);
    PrintData();
    ifFile.close();
}

void SortByMovieTitle()
{
    if (movies.empty())
    {
        cout << "There is no recorded data on the films." << endl;
        return;
    }
    
    for (int i = 0; i < movies.size(); i++)
    {
        for (int j = movies.size() - 1; j > i; j--)
        {
            if (movies[j].nameOfMovie[0] < movies[j - 1].nameOfMovie[0])
            {
                swap(movies[j], movies[j - 1]);
            }
        }
    }

    cout << "Data is successfully sorted" << nowTime << endl;

    WriteHistoryAction("Data is successfully sorted" + nowTime);
    PrintData();
}

void PrintData()
{
    if (movies.empty())
    {
        cout << "There is no recorded data on the films." << endl;
        return;
    }
    
    cout << "All data:" << endl;

    for (int i = 0; i < movies.size(); i++)
    {
        cout << "Index: " << i + 1 << " Name: " << movies[i].nameOfMovie << "\n" << " Year of publish: " << movies[i].year << "\n" << " Name of director: " << movies[i].director << "\n" << " Country of publish: " << movies[i].country << endl;
        cout << endl;
    }
}

void DeleteElement()
{
    int index;
    bool correctInput = false;

    if (movies.empty())
    {
        cout << "There is no recorded data on the films." << endl;
        return;
    }

    cout << "Enter the number of the record you want to delete" << endl;

    while(!correctInput)
    {
        cin >> index;
        if(cin.fail() || (index <= 0 || index > movies.size()))
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Try again: ";
        }
        else
        {
            correctInput = true;
        }
    }

    movies.erase(movies.begin() + (index - 1));
    
    cout << "Deleting data successfully" << endl;
    cout << endl;

    WriteHistoryAction("Deleting data successfully" + nowTime);
    PrintData();
}

void ChangeElement()
{
    int index;
    bool correctInput = false;

    if (movies.empty())
    {
        cout << "There is no recorded data on the films." << endl;
        return;
    }

    cout << "Enter the index of the movie whose information you want to change" << endl;

    while(!correctInput)
    {
        cin >> index;
        if(cin.eof() || (index <= 0 || index > movies.size()))
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Try again: ";
        }
        else
        {
            correctInput = true;
        }
    }

    correctInput = false;

    cout << "Name of movie: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, movies[index - 1].nameOfMovie);

    cout << "Country of publishing: ";
    getline(cin, movies[index - 1].country);

    cout << "Name of the director: ";
    getline(cin, movies[index - 1].director);

    cout << "Year: ";
    while (!correctInput)
    {
        cin >> movies[index - 1].year;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Try again: ";
        }
        else
        {
            correctInput = true;
        }
        
    }

    cout << "The data was successfully changed" << nowTime << endl;
    WriteHistoryAction("The data was successfully changed" + nowTime);
    cout << endl;
}

void WriteHistoryAction(string historyActions)
{
    ofstream consoleLog;

    consoleLog.open("consoleData.txt", ios::app | ios::out);

    if (!consoleLog.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    
    consoleLog << historyActions << "\n";
    consoleLog.close();
}

void ReadHistoryAction()
{
    string getData;
    ifstream consoleLog;

    consoleLog.open("consoleData.txt", ios::in);

    if (!consoleLog.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    
    while (getline(consoleLog, getData))
    {
        if (consoleLog.eof())
        {
            break;
        }
        
        cout << getData << endl;
    }

    consoleLog.close();
}
