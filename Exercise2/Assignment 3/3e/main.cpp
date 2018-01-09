/*
* Jaime Manuel Trillos Ujueta
* 2895358
*/
#include <iostream>

using namespace std;

int string_length(const char* s){
    int length = 0;
    while(s[length]!='\0'){
        length++;
    }
    return length;
}

int main()
{
    const char* message = "Hello world";
    cout << string_length(message) << endl;
    return 0;
}
