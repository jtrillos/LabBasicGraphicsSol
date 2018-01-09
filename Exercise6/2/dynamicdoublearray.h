
#ifndef DYNAMICDOUBLEARRAY_H
#define DYNAMICDOUBLEARRAY_H

#include <stdio.h>

class DynamicDoubleArray {
public:
    DynamicDoubleArray();
    ~DynamicDoubleArray();
    int get_size(); // get the number of elements stored inside the array
    double& at(int idx); // access the element positioned at idx
    void push_back(double d); // adds a new element to the array
    void remove(int idx); // remove the element at idx from the array
    void clear(); // delete all the data store inside the array
private:
    double* elements;
    int size;
};

#endif // DYNAMICDOUBLEARRAY_H
