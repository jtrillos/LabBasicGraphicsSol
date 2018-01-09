

#ifndef HEAP_H
#define HEAP_H
struct HeapElement {
    double value;
    HeapElement* parent;
    HeapElement* child1;
    HeapElement* child2;
};

class Heap {
    HeapElement* head;

public:
    Heap();
    ~Heap();
    bool is_empty() const; // returns whether the heap is empty
    double top() const; // returns the smallest element
    void insert( double d ); // inserts value d into the heap
    void pop_top(); // removes the smallest element
    void print();
    void order(HeapElement* p);
private:
    HeapElement* find_leaf(); // find some leaf (element without children)
    HeapElement* insert_as_leaf(double d); // insert a value as leaf, return the element
};

void swap_element_values(HeapElement* e1, HeapElement* e2); // swap element values
void repair_upwards(HeapElement* child); // assure the heap property upwards
void repair_downwards(HeapElement* parent); // assure the heap property downwards
#endif // HEAP_H
