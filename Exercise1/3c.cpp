#include <iostream>
using namespace std;

int fib_loop(int n){
    int f = 1, fPrev = 1;
    if (n == 0){
        return 0;
    }
    for(int i = 2; i < n; i++){
        int temp = f;
        f = f + fPrev;
        fPrev = temp;
    }
    return f;
}

int main( int argc, char** argv) {
    int n;
    cout << "Insert a natural number: ";
    cin >> n;
    cout << "The fibonacci number is: " << fib_loop(n);
}
