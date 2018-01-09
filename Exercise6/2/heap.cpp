

#include <iostream>
#include "heap.h"
#include <limits>

using namespace std;

Heap::Heap(){
    head = NULL;
}

Heap::~Heap(){
    while (head != NULL) {
        pop_top();
    }
}

double Heap::top() const{
    //return the smallest element
    if (head != NULL){
        return head->value;
    }else {
        cout << "empty heap" << endl;
        return numeric_limits<double>::max();
    }
}

void Heap::insert(double d){
    //insert value d into the heap
    if (head == NULL){
        head = new HeapElement;
        head ->value = d;
        head->parent = NULL;
        head->child1 = NULL;
        head->child2 = NULL;
    }else {
        HeapElement* freepos = insert_as_leaf(d);
        repair_upwards(freepos);
    }
}

HeapElement* Heap::find_leaf(){
    //find some leaf (element without children)
    HeapElement* leaf = head;
    while (leaf->child1 != NULL || leaf->child2 != NULL) {
        //if it has child
        if (leaf->child1 !=NULL && leaf->child2 != NULL) {
            //if it has two children
            if (rand()%2 == 0){
                leaf = leaf->child1;
            }else {
                leaf = leaf->child2;
            }
        }else if (leaf->child1 != NULL) {
            leaf = leaf->child1;
        }else {
            leaf = leaf->child2;
        }
    }
    return leaf;
}

HeapElement* Heap::insert_as_leaf(double d){
    //insert a value as leaf, return the element
    HeapElement* freepos_parent = find_leaf();
    HeapElement* freepos = new HeapElement;

    //if left child is NULL then insert to left child, else otherwise
    if(freepos_parent->child1 == NULL){
        freepos_parent->child1 = freepos;
    }else {
        freepos_parent->child2 = freepos;
    }
    //insert the new value to the position freepos
    freepos->parent = freepos_parent;
    freepos->value = d;
    freepos->child1 = NULL;
    freepos->child2 = NULL;

    return freepos;
}

void Heap::pop_top(){
    //removes the smallest element
    if (head == NULL){
        cout << "The heap is already empty" << endl;
    }else if (head->child1 == NULL && head->child2 == NULL) {
        delete head;
        head = NULL;
    }else {
        //find a leaf node
        HeapElement* leaf = find_leaf();
        //cut the leaf
        if (leaf == leaf->parent->child1){
            leaf->parent->child1 = NULL;
        }else{
            leaf->parent->child2 = NULL;
        }

        //change head to the leaf
        leaf->parent = NULL;
        leaf->child1 = head->child1;
        leaf->child2 = head->child2;

        //change the parent of childs of previous head
        if (head->child1 != NULL){
            head->child1->parent = leaf;
        }
        if (head->child2 != NULL){
            head->child2->parent = leaf;
        }

        delete head;
        head = leaf;

        repair_downwards(leaf);
    }
}

void Heap::print(){
    order(head);
    cout << endl;
}

void Heap::order(HeapElement* p){
    if(p != NULL){
        cout << p->value << " ";
        if (p->child1){
            order(p->child1);
        }
        if (p->child2){
            order(p->child2);
        }
    }else return;
}

void swap_element_values(HeapElement* e1, HeapElement* e2){
    double temp;
    temp = e1->value;
    e1->value = e2->value;
    e2->value = temp;

}

void repair_upwards(HeapElement* child){
    // assure the heap property upwards
    while (child->parent != NULL && child->parent->value > child->value){
        //swap the value
        swap_element_values(child->parent, child);
        //set to one level higher
        repair_upwards(child->parent);
    }
}

void repair_downwards(HeapElement* parent){
    // assure the heap property downwards
    HeapElement* small_child = new HeapElement;

    while (parent->child1 != NULL || parent->child2 != NULL){
        //if it has child
        if (parent->child1 != NULL){
            small_child = parent->child1;
            if (parent->child2 != NULL && parent->child2->value < parent->child1->value){
                //if it has two child
                small_child = parent->child2;
            }
        }
        else{
            small_child = parent->child2;
        }
        if (parent->value > small_child->value){
            swap_element_values(small_child, parent);
        }
        parent = small_child;
    }
}
