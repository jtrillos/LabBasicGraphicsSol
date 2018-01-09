
#ifndef HEAPVECTOR_H
#define HEAPVECTOR_H

#include <stdio.h>
#include <vector>

class HeapVector {
    std::vector<double> values;
    int size;

public:
    HeapVector();
    ~HeapVector();
    unsigned int heap_size();
    double top() const; // returns the smallest element
    void insert( double d ); // inserts value d into the heap
    void pop_top(); // removes the smallest element
    void print();
};

#endif // HEAPVECTOR_H
