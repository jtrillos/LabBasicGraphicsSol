/*
* Jaime Manuel Trillos Ujueta
* 2895358
*/
#include <iostream>

using namespace std;

int main()
{
    char c;
    cout << "A-Z: ";
    for(c = 'A'; c <= 'Z'; ++c){
        cout << int(c) << " ";
    }
    cout << endl << "a-z: ";
    for(c = 'a'; c <= 'z'; ++c){
        cout << int(c) << " ";
    }
    cout << endl << "0-9: ";
    for(c = '0'; c <= '9'; ++c){
        cout << int(c) << " ";
    }
    cout << endl;
    return 0;
}
