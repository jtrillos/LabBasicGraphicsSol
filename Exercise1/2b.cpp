#include <iostream>
using namespace std;

int mean( int a, int b ) {
    return (a + b)/2;
}

int abs( int a ) {
    if( a >= 0 ) {
        return a;
    } else {
        return -a;
    }
}

int min( int a, int b ) {
    if( a < b ) {
        return a;
    } else {
        return b;
    }
}

int max( int a, int b ) {
    if( a > b ) {
        return a;
    } else {
        return b;
    }
}

int square( int a ) {
    return a * a;
}

int main( int argc, char** argv) {
    int result = mean(min( max( 10, 1 ), abs( -9 ) ), 6 );
    cout << result;
}
