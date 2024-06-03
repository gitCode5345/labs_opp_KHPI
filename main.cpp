#include <iostream>
#include "Vector_lab.h"

using namespace std;

int main()
{
    try
    {
        VectorLab arr(5);
        arr + 3;
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr.PrintInformation();
        
        cout << "Size: " << int(arr) << endl;

        arr - 2;
        arr.PrintInformation();
        
        arr + 5;
        arr.PrintInformation();

        // exception:
        // cout << arr[10] << endl;
        // arr - 10;

    }
    
    catch (const exception& e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
