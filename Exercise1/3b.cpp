#include <iostream>
using namespace std;

int sumfirstN (int n){
    int sum = 0;
    for (int i=1; i<=n; i++){
        sum = sum + i;
    }
    return sum;
}

int main( int argc, char** argv) {
    int n;
    cout << "Insert a natural number: ";
    cin >> n;
    cout << "The sum is: " << sumfirstN(n);
}

