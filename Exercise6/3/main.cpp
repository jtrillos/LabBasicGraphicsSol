
#include <iostream>
#include "dynamicdoublearray.h"
#include "heapvector.h"
#include <limits>

using namespace std;

int main(){
    cout << "How can you access the parent element / children elements of an arbitrary element?" << endl;
    cout << "i: an arbitrary valid index of the array storing the heap." << endl;
    cout << "If tree root at index 0, with valid indices 0 througn n-1  " << endl;
    cout << "For each element at index i: " << endl;
    cout << "children at indices 2i + 1 and 2i + 2  " << endl;
    cout << "parent at index floor((i - 1) / 2)  " << endl;
    cout << "If tree root at index 1, with valid indices 1 througn n  " << endl;
    cout << "For each element at index i: " << endl;
    cout << "children at indices 2i and 2i + 1  " << endl;
    cout << "parent at index floor(i / 2)  " << endl << endl;

    cout << "Advantages: Binary tree can be stored in an array. No space is required for Pointer" << endl << endl;

    cout << "HeapVector: inserting the inputs:" << endl;
    HeapVector hv;
    double input[20] = { 29, 49, 52, 26, 29, 89, 11, 91, 65, 68, 91, 44, 19, 74, 51, 77, 93, 90, 56, 28 };
    for (int i = 0; i < 20; i++){
        hv.insert(input[i]);
        hv.print();
    }

    cout << endl << "HeapVector: removing the smallest number iteratively:" << endl;
    DynamicDoubleArray dda;
    hv.print();
    for (int j = 0; j <20; j++){
        dda.push_back (hv.top());
        hv.pop_top();
        hv.print();
    }

    cout << "HeapVector: after appending, the dynamic array is:" << endl;
    for (int j = 0; j <20; j++){
        cout<<dda.at(j)<<" ";
    }
    cout << endl;
    return 0;
}
