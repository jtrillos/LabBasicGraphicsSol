#include <iostream>
using namespace std;
int main( int argc, char** argv) {
    int i = 10;
    int j = 23;
    float f = 3.141f;
    double d = 2.718281828459045;
    cout << i/j << ", " <<  j/i << ", " <<  i/2 << ", " <<  j/2 << ", " <<  i%2 << ", " <<  j%2 << ", " <<  (j/3) * 3 + j%3 << ", " <<  f*f*5 << ", " <<  f/d << ", " <<  d/f << ", " <<  d*i << ", " <<  d/i << endl;
}
