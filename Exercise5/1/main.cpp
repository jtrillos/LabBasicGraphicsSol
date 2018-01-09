
#include <iostream>
#include "dynamicdoublearray.h"

using namespace std;

int main()
{
    DynamicDoubleArray dda;
    cout << "The dynamic double array is:" << endl;
    for (int i=0; i<100; i++){
        dda.push_back(0.1*i);
        cout << dda.at(i) << ", ";
    }
    cout << endl;
    cout << "The current size is: " << dda.get_size() << endl;
    cout << endl << endl;

    dda.remove(0);
    cout << "I remove the firts element:" << endl;
    for (int i=0; i<dda.get_size(); i++){
        cout << dda.at(i) << ", ";
    }
    cout << endl;
    cout << "The current size is: " << dda.get_size() << endl;
    cout << endl << endl;

    dda.clear();
    cout << "I clear the array, the current size is: " << dda.get_size() << endl;
    cout << endl << endl;

    cout << "I inserted again a dynamic double array which is:" << endl;
    for (int i=0; i<50; i++){
        dda.push_back(0.5*i);
        cout << dda.at(i) << ", ";
    }
    cout << endl;
    cout << "The current size is: " << dda.get_size() << endl;
    cout << endl << endl;

    cout << "The algorithmic complexity for adding a new element (push back) is: o(n log n)" << endl;
    return 0;
}
