
#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace std;

bool check(string ani, string animal[]);

int main()
{
    string animal[11] ={"wolverine", "chicken", "turtle", "dog", "snail", "cat", "sardine", "zebra", "dog", "snail", "dog"};
    LinkedList LL; //create a list

    cout << "Adding the following animals: " << endl;
    Element* element = NULL;
    for (int i=0; i<11; i++){
        LL.insert(element, animal[i]);
        LL.print();
        if(LL.head() == LL.tail()){
            element = LL.head();
        }else {
            element = element->_next;
        }
    }

    cout << endl;
    LL.remove_value("dog");
    LL.remove_value("wolverine");
    cout << "After removing dog and wolverine, the current list is: " << endl;
    LL.print();
    LL.clear();

    cout << endl;
    cout << "Insert sorted test: " << endl;
    for (int i=0; i<11; i++){
        LL.insert_sorted(animal[i]);
        LL.print();
    }

    cout << endl;
    string ani;
    cout << "Input an animal: ";
    cin >> ani;
    while (ani != "end"){
        if (check(ani, animal)){
            cout << "Deleting " << ani << endl;
            LL.remove_value(ani);
            LL.print();
            cout << endl;
        }else {
            cout << "Inserting " << ani << endl;
            LL.insert_sorted(ani);
            LL.print();
            cout << endl;
        }
        cout << "Input an animal: ";
        cin >> ani;
    }

    cout << endl;
    cout << "inserting: o(1)" << endl;//we have the location of the last node
    cout << "removing: o(1)" << endl;
    cout << "inserting sorted: o(n)" << endl;
    cout << "remove by value: o(n)" << endl;
    cout << "accessing by index: o(n)" << endl;

    cout << endl;
    cout << "Advantages: *Dynamic size and *ease of insertion/deletion" << endl;
    cout << "Disadvantages: *More memory space for pointer" <<endl;
    return 0;
}

bool check(string ani, string animal[]){
    for (int i=0; i<11; i++) {
        if (ani == animal[i]) {
            return true;
        }
    }
    return false;
}
