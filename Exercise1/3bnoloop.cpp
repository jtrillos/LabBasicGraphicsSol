#include <iostream>
using namespace std;

int sumfirstN (int n){
    if (n != 0){
        return n + sumfirstN (n-1);
    }else{
        return n;
    }
}

int main( int argc, char** argv) {
    int n;
    cout << "Insert a natural number: ";
    cin >> n;
    cout << "The sum is: " << sumfirstN(n);
}

