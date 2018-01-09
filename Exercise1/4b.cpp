#include <iostream>
using namespace std;

// Binomial Coefficient C(n, i)
int binCoefficient(int n, int k){
  if (k == 0 || k == n){
    return 1;
  }else{
    return  (binCoefficient(n-1, k-1) + binCoefficient(n-1, k));
  }
}

int main( int argc, char** argv) {
    int n, k;
    cout << "Insert n: ";
    cin >> n;
    cout << "Insert i: ";
    cin >> k;
    cout << "The value of C(" << n << ", " << k << ") is: " << binCoefficient(n, k);
}
