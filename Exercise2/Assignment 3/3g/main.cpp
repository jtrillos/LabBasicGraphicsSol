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

int string_length(const char* s){
    int length = 0;
    while(s[length]!='\0'){
        length++;
    }
    return length;
}

int main()
{
    char buffer[100];
    const char* message = "Hello world";
    int len = string_length(message);
    for (int i=0; i<len; ++i){
        buffer[i] = map(message[i]);
        cout << buffer[i] << " ";
    }
    cout << endl;
    return 0;
}
