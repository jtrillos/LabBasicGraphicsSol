

#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

LinkedList::LinkedList(){
    _head = NULL;
    _tail = _head;
    number_of_elements = 0;
}

LinkedList::~LinkedList(){
    clear();
}

Element* LinkedList::head(){
    return _head;
}

Element* LinkedList::tail(){
    return _tail;
}

unsigned int LinkedList::size(){
    return number_of_elements;
}

// remove element e, return the previous element
Element* LinkedList::remove(Element *element){
    Element* previous;
    previous = element->_previous;
    if (element == _tail){
        if (element == _head) {
            //only one element in the list
            _head = NULL;
            _tail = _head;
        }
        //delete the last element
        else{
            element ->_previous->_next = NULL;
            _tail = element->_previous;
        }
    }
    //remove the head
    else if (element == _head){
        element->_next->_previous = NULL;
        _head = element->_next;
    }
    //delete element in the middle
    else{
        element->_previous->_next = element->_next;
        element->_next->_previous = element->_previous;
        previous = element->_previous;
    }
    delete element;
    number_of_elements -= 1;
    return previous;
}

// add value after ’previous’; if ’previous’ is ’NULL’ prepend; return the new element
Element* LinkedList::insert(Element *previous, std::string value){
    // add value after ’previous’, return the new element
    Element* newEle = new Element;
    newEle->value = value;
    //if previous is null
    if (previous == NULL) {
        newEle->_previous = NULL;
        //if no elements
        if (_head == NULL) {
            _head = _tail = newEle;
            newEle->_next = NULL;
        }
        //if there are elements
        else{
            newEle->_next = _head;
            _head->_previous = newEle;
            // if the list has only one element(_head = _tail)
            if (_head->_next == NULL){
                newEle->_next = _tail;
                _tail->_previous = newEle;
            }
            _head = newEle;
        }
    }
    //insert element after tail
    else if (previous==_tail){
        newEle->_next=NULL;
        newEle->_previous=previous;
        previous->_next=newEle;
        _tail=newEle;
    }
    //insert element in the middle
    else{
        newEle->_next = previous->_next;
        previous->_next->_previous = newEle;
        newEle->_previous = previous;
        previous->_next = newEle;
    }
    number_of_elements += 1;
    return newEle;
}

// clear elements
void LinkedList::clear() {
    while (_head != NULL){
        remove(_head);
    }
}

// print contents
void LinkedList::print(){
    Element* e;
    e = _head;
    while (e != NULL){
        cout << e->value << " ";
        e = e->_next;
    }
    cout<<endl;
    delete e;
}

unsigned int LinkedList::remove_value(std::string value){
    //removes all strings that equal to value and returns their count.
    unsigned int count = 0;
    Element* e;
    e = _head;
    while (e != NULL){
        //if the values are equal
        if (!(e->value).compare(value)){
            e = remove(e);
            count ++;
        }
        if (e != NULL){
            e = e->_next;
        }
        else if(e == NULL && _head != NULL){ //head was removed
            e = _head;
        }
        else{
            break;
        }
    }
    return count;
}

void LinkedList::insert_sorted(std::string value){
    // inserts a string before the first element that does not compare smaller.
    Element* e;
    e = _head;
    // the value of the first character that does not match is greater in the compared string
    if (e == NULL || (e->value).compare(value) >= 0){
        insert(NULL, value);
    }
    else{
        //the value of the first character that does not match is lower in the compared string
        while (e!=NULL && (e->value).compare(value) < 0){
            e = e->_next;
        }

        if (e != NULL){
            insert(e->_previous, value);
        }
        else{
            insert(_tail, value);
        }
    }
}
