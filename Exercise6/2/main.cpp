
#include <iostream>
#include "heap.h"
#include "dynamicdoublearray.h"
#include <limits>

using namespace std;

int main()
{
    Heap heap;
    cout << "Heap: inserting the inputs: " << endl;
    double input[20] = { 29, 49, 52, 26, 29, 89, 11, 91, 65, 68, 91, 44, 19, 74, 51, 77, 93, 90, 56, 28 };
    for (int i = 0; i < 20; i++){
        heap.insert(input[i]);
        heap.print();
    }
    DynamicDoubleArray dda;
    cout << endl << "Heap: removing the smallest number iteratively: " << endl;
    for (int j = 0; j <20; j++){
        dda.push_back(heap.top());
        heap.pop_top();
        heap.print();
    }
    cout << "Heap: after appending, the dynamic array is " << endl;
    for (int j = 0; j <20; j++){
        cout<<dda.at(j)<<" ";
    }
    cout << endl << endl;

    cout << "top: o(n)" << endl;
    cout << "insert: o(logn)" << endl;
    cout << "poptop: o(logn)" << endl;
    cout << "heap sort: o(n logn)" << endl;
    return 0;
}
