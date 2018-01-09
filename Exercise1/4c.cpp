#include <iostream>
using namespace std;
int main( int argc, char** argv) {
    int rows = 6;
    for (int i = 0; i < rows; i++){
        int val = 1;
        for (int j = 1; j < (rows - i); j++){
            cout << "      ";
        }
        for (int y = 0; y <= i; y++){
            cout << "           " << val;
            val = val * (i - y)/(y + 1);
        }
        cout << endl << endl;
    }
    cout << endl;
}
