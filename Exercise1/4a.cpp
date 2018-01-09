#include <iostream>
using namespace std;

int fib_recursion(int n){
    if ((n == 0) || (n == 1)){
        return n;
    }else {
        return fib_recursion(n-1)+fib_recursion(n-2);
    }
}

int main( int argc, char** argv) {
    cout << "The fibonacci number for 1 is: " << fib_recursion(1) << endl;
    cout << "The fibonacci number for 5 is: " << fib_recursion(5) << endl;
    cout << "The fibonacci number for 6 is: " << fib_recursion(6) << endl;
    cout << "The fibonacci number for 100 is: " << fib_recursion(100) << endl;
}
