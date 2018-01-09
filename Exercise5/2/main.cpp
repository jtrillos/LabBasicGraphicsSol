/*
* Jaime Manuel Trillos Ujueta
* 2895358
*/
#include <iostream>
#include "math.h"

using namespace std;

void bubbleSortIndices(double* data, int size);
void bubbleSortPointer(double* data, int size);
void joinSorted(double* left, int sizeLeft, double* right, int sizeRight,double * output);
void mergeSort(double * data, int size);
void print(double* array, int size);

int main()
{
    cout << "The input array is: ";
    double* array;
    int size=10;
    array = new double[size];
    for (int i = 0; i < size; i++){
        array[i] = rand() % 10 + 1;
        cout << array[i] << " ";
    }
    cout << endl << endl;

    bubbleSortIndices(array, size);
    cout << "The bubble sort array: ";
    print(array, size);
    cout << endl;

    cout << "b) There is no semantic difference." << endl << endl;

    cout << "The input array is: ";
    for (int i = 0; i < size; i++){
        array[i] = rand() % 20 + 1;
        cout << array[i] << " ";
    }
    cout << endl << endl;

    mergeSort(array, size);
    cout << "The merge sort array: ";
    print(array, size);
    cout << endl;

    cout << "e) BubbleSort Complexity: o(n*n)." << endl;
    cout << "MergeSort Complexity: o(n log n)." << endl;
    return 0;
}

void bubbleSortIndices(double* data, int size){
    double temp;
    do{
        for (int i = 0; i < size - 1; i++){
            if (data[i]>data[i + 1]){
                //change the place
                temp = data[i + 1];
                data[i + 1] = data[i];
                data[i] = temp;
            }
        }
        size--;
    } while (size > 1);
}

void bubbleSortPointer(double* data, int size){
    double temp;
    do{
        for (int i = 0; i < size - 1; i++){
            if ( *(data+i) > *(data+i+1) ){
                temp = *(data + i + 1);
                *(data + i + 1) = *(data + i );
                *(data + i ) = temp;
            }
        }
        size--;
    } while (size > 1);
}

void joinSorted(double* left, int sizeLeft, double* right, int sizeRight,double* output){
    int o_idx=0, l_idx=0, r_idx=0;
    //if there are elements left in both side, them compare and put the smaller one to the output.
    while (l_idx < sizeLeft && r_idx < sizeRight){
        if (left[l_idx] <= right[r_idx]){
            output[o_idx++] = left[l_idx++];
        }
        else {
            output[o_idx++] = right[r_idx++];
        }
    }
    //if only the left side has more elements, then just append those elements to the output.
    while (l_idx < sizeLeft){
        output[o_idx++] = left[l_idx++];
    }
    //if only the right side has more elements, then just append those elements to output.
    while (r_idx < sizeRight){
        output[o_idx++] = right[r_idx++];
    }
    // change the order inside the input data.
    for (int i = 0; i < sizeLeft; i++){
        left[i] = output[i];
    }
    for (int j = 0; j < sizeRight; j++){
        right[j] = output[sizeLeft+ j];
    }
}

void mergeSort(double* data, int size){
    if(size<=1){
        data=data;
    }else{
        double *temp = new double[size];
        int sizeLeft = size / 2;
        double * left;
        double * right;

        left = data ;
        right = data + sizeLeft;
        int sizeRight=size-sizeLeft;

        mergeSort(left, sizeLeft);
        mergeSort(right, sizeRight);

        joinSorted(left, sizeLeft, right, sizeRight, temp);
        delete[] temp;
    }
}

void print(double* array, int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

