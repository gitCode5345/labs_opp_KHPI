#ifndef VECTORLAB_H
#define VECTORLAB_H

#include <iostream>
#include <stdexcept>

using namespace std;

class VectorLab {
private:
    int* myVector;
    int size;
    int vectorCapacity;

    void ResizeVec(int newCapacity);

public:
    VectorLab(int initialCapacity = 10);
    ~VectorLab();

    int operator[](int index) const;
    int& operator[](int index);
    operator int() const;
    void operator-(int n);
    void operator+(int n);

    void PrintInformation() const;
};

#endif
