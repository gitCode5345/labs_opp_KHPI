#include <iostream>
#include "brokenLine_class.cpp"
#include "point_class.cpp"

using namespace std;

int main()
{
    vector<Point> points;
    points.push_back(Point(1, 2));
    points.push_back(Point(3, 4));
    points.push_back(Point(5, 6));

    BrokenLine chain(points);

    cout << "Using [] operator:" << endl << endl;
    cout << chain[1] << endl;

    cout << "Using () operator:" << endl << endl;
    chain();

    cout << "Using << operator:" << endl << endl;
    cout << chain << endl;

    cout << "Using function remove point:" << endl << endl;
    chain.RemovePoint(0);
    cout << chain << endl;

    cout << "Count of points: " << chain.getNumberOfPoints() << endl;

    cout << "Using function add point:" << endl << endl;
    chain.AddPoint(Point(4,7));
    cout << chain << endl;

    cout << "Using function insert point:" << endl << endl;
    chain.InsertPoint(Point(100,20), 0);
    cout << chain << endl; 

    BrokenLine otherChain(chain);

    cout << "Number of points: " << otherChain.getNumberOfPoints() << " All points:\n " << otherChain << endl;

    return 0;
}
