#ifndef VECTORLAB_H
#define VECTORLAB_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T1>
class VectorLab {
private:
    T1* myVector;
    int size;
    int vectorCapacity;

    void ResizeVec(int newCapacity);

public:
    VectorLab(int initialCapacity = 10);
    ~VectorLab();

    T1 operator[](int index) const;
    T1& operator[](int index);
    operator int() const;
    void operator-(int n);
    void operator+(int n);
    void PrintInformation() const;
};

template<>
class VectorLab<char*>
{
public:
    VectorLab(int initialCapacity)
    {
        cout << "Error: char* type is not supported." << endl;
    }

    ~VectorLab() {}
    
    char* operator[](int index) const { return nullptr; }
    char*& operator[](int index) { static char* dummy = nullptr; return dummy; }
    operator int() const { return 0; }
    void operator+(int n) {}
    void operator-(int n) {}
    void PrintInformation() const {}
};

#endif
