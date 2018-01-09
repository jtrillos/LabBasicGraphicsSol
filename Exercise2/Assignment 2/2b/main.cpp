/*
* Jaime Manuel Trillos Ujueta
* 2895358
*/
#include <iostream>

using namespace std;

int main(){
    int a[40], b[40], c[8], d[40];
    for (int i=0; i<40; ++i){
        int sum = 0;
        a[i] = 2*(i+1);
        for (int j=0; j<=i; ++j){
            sum += a[j];
            b[i] = sum;
        }
    }
    for (int i=0; i<8; ++i){
        int prod = 1;
        for (int j=0; j<=i; ++j){
            prod *= a[j];
            c[i] = prod;
        }
    }

    cout << "Array a:";
    for (int i=0; i<40; ++i){
        cout << a[i] << ",";
        d[i] = a[39-i];
    }

    cout << endl << endl << "Array b:";
    for (int i=0; i<40; ++i){
        cout << b[i] << ",";
    }

    cout << endl << endl << "Array c:";
    for (int i=0; i<8; ++i){
        cout << c[i] << ",";
    }

    cout << endl << endl << "Array d:";
    for (int i=0; i<40; ++i){
        cout << d[i] << ",";
    }
    cout << endl;

    cout << "a[6]: " << a[6] << endl;
    cout << "a[100]: " << a[100] << endl;
    cout << "a[100000]: " << a[100000] << endl;

    return 0;
}
