/*
* Jaime Manuel Trillos Ujueta
* 2895358
*/
#include <iostream>

using namespace std;

char map(char ch){
    if(ch>='A' && ch<='Z'){
        ch=ch+32;
    }else if(ch>='a' && ch<='z'){
        ch=ch-32;
    }
    return ch;
}

int main()
{
    char c;
    cout << "Insert a character (Alphabet): ";
    cin >> c;
    cout << map(c) << endl;
    return 0;
}
