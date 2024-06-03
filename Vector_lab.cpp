#include "Vector_lab.h"

VectorLab::VectorLab(int initialCapacity) : size(0), vectorCapacity(initialCapacity) 
{
    if (initialCapacity <= 0) throw invalid_argument("Capacity must be positive");

    this->myVector = new int[initialCapacity];
}

VectorLab::~VectorLab() 
{
    delete[] this->myVector;
}

void VectorLab::ResizeVec(int newCapacity) 
{
    int* new_vector = new int[newCapacity];

    for (int i = 0; i < size; ++i)
    {
        new_vector[i] = this->myVector[i];
    }

    delete[] this->myVector;
    this->myVector = new_vector;
    vectorCapacity = newCapacity;
}

int VectorLab::operator[](int index) const 
{
    if (index < 0 || index >= this->size) throw out_of_range("Index out of range");

    return this->myVector[index];
}

int& VectorLab::operator[](int index) 
{
    if (index < 0 || index >= this->size) throw out_of_range("Index out of range");

    return this->myVector[index];
}

VectorLab::operator int() const 
{
    return this->size;
}

void VectorLab::operator-(int n) 
{
    if (n < 0) throw invalid_argument("Number of elements to remove must be non-negative");
    if (n > this->size) throw out_of_range("Cannot remove more elements than present in the array");

    this->size -= n;
    ResizeVec((size) * 2);
}

void VectorLab::operator+(int n) 
{
    if (n < 0) throw invalid_argument("Number of elements to add must be non-negative");

    if (size + n > vectorCapacity) 
    {
        ResizeVec((size + n) * 2);
    }

    for (int i = 0; i < n; ++i) 
    {
        this->myVector[this->size + i] = 0;
    }

    this->size += n;
}

void VectorLab::PrintInformation() const 
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
