#include <iostream>
#include "segment.h"
#include "line.h"
#include "polyline.h"

using namespace std;

int main()
{
    Segment segment({0, 0}, {3, 4});
    Polyline polyline({{0, 0}, {3, 4}, {6, 8}, {9, 12}});

    Line* lines[] = {&segment, &polyline};

    for (const Line* line : lines)
    {
        vector<pair<double, double>> coords = line->GetCoordinates();
        cout << "Coordinates: ";

        for (const auto& coord : coords)
        {
            cout << "(" << coord.first << ", " << coord.second << ") ";
        }
        cout << "\nLength: " << line->GetLength() << "\n\n";
    }

    return 0;
}
