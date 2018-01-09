
#include "dynamicdoublearray.h"

DynamicDoubleArray::DynamicDoubleArray(){
    size = 0;
    elements = new double[100];
}

DynamicDoubleArray::~DynamicDoubleArray(){
    delete [] elements;
}

int DynamicDoubleArray::get_size(){
    return size;
}

double& DynamicDoubleArray::at(int idx){
    return elements[idx];
}

void DynamicDoubleArray::push_back(double d){
    if(size > 100){
        double* newElement = new double[size*2];
        // set the value of newElement
        newElement = elements;
        newElement[size] = d;
        size++;
        // clear elements
        delete elements;
        elements = newElement;
        delete newElement;
    }else {
        elements[size] = d;
        size++;
    }
}

void DynamicDoubleArray::remove(int idx){
    for (int i=idx; i<size; i++){
        elements[i] = elements[i+1];
    }
    elements[size-1] = 0;
    size--;
}

void DynamicDoubleArray::clear(){
    for (int i=0; i<size; i++){
        elements[i] = 0;
    }
    size = 0;
}
