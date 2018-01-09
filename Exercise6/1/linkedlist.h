
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <string>

struct Element {
    Element* _previous;
    Element* _next;
    std::string value;
};
class LinkedList {
private:
    Element* _head;
    Element* _tail;
    unsigned int number_of_elements;

public:
    LinkedList();
    ~LinkedList();
    Element* head(); // return first element
    Element* tail(); // return last element
    unsigned int size(); // return number of elements
    Element* remove(Element* element); // remove element e, return the previous element
    Element* insert(Element* previous, std::string value);
    // add value after ’previous’; if ’previous’ is ’NULL’ prepend; return the new element
    void clear(); // clear elements
    void print(); // print contents
    unsigned int remove_value(std::string value); //removes all strings that equal to value and returns their count.
    void insert_sorted(std::string value); // inserts a string before the first element that does not compare smaller.
};
#endif // LINKEDLIST_H
