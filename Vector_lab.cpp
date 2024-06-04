#include <iostream>
#include <string>
#include "Vector_lab.h"

using namespace std;

template<typename T1>
VectorLab<T1>::VectorLab(int initialCapacity) : size(0), vectorCapacity(initialCapacity) 
{
    if (initialCapacity <= 0) throw invalid_argument("Capacity must be positive");

    this->myVector = new T1[initialCapacity];
}

template<typename T1>
VectorLab<T1>::~VectorLab() 
{
    delete[] this->myVector;
}

template<typename T1>
void VectorLab<T1>::ResizeVec(int newCapacity) 
{
    T1* new_vector = new T1[newCapacity];

    for (int i = 0; i < size; ++i)
    {
        new_vector[i] = this->myVector[i];
    }

    delete[] this->myVector;
    this->myVector = new_vector;
    vectorCapacity = newCapacity;
}

template<typename T1>
T1 VectorLab<T1>::operator[](int index) const 
{
    if (index < 0 || index >= this->size) throw out_of_range("Index out of range");

    return this->myVector[index];
}

template<typename T1>
T1& VectorLab<T1>::operator[](int index) 
{
    if (index < 0 || index >= this->size) throw out_of_range("Index out of range");

    return this->myVector[index];
}

template<typename T1>
VectorLab<T1>::operator int() const 
{
    return this->size;
}

template<typename T1>
void VectorLab<T1>::operator-(int n) 
{
    if (n < 0) throw invalid_argument("Number of elements to remove must be non-negative");
    if (n > this->size) throw out_of_range("Cannot remove more elements than present in the array");

    this->size -= n;
    ResizeVec((size) * 2);
}

template<typename T1>
void VectorLab<T1>::operator+(int n) 
{
    if (n < 0) throw invalid_argument("Number of elements to add must be non-negative");

    if (size + n > vectorCapacity) 
    {
        ResizeVec((size + n) * 2);
    }

    cout << "Please, enter the values you want to add to the vector" << endl;
    for (int i = 0; i < n; ++i)
    {
        bool trueCin = false;
        T1 value;

        while (!trueCin)
        {
            cout << "Enter value #" << (i + 1) << ": ";

            if constexpr (is_same<T1, string>::value)
                getline(cin >> ws, value);
            else
                cin >> value;

            if (cin.fail())
            {
                cout << "Invalid input. Please enter a value of the correct type." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                trueCin = true;
            }
        }

        this->myVector[this->size + i] = value;
    }

    this->size += n;
}

template<typename T1>
void VectorLab<T1>::PrintInformation() const 
{
    cout << "{ ";

    for (int i = 0; i < this->size; ++i) 
    {
        cout << this->myVector[i];

        if (i == this->size - 1)
        {
            break;
        }

        else
        {
            cout << ", ";
        }
    }

    cout << " }" << endl;
}
