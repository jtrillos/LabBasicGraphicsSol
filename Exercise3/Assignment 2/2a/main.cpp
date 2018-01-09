#include <iostream>

using namespace std;

int string_length(const char* string) {
    int length = 0;
    for(const char* ptr = string; *ptr != '\0'; ++ ptr) {
        ++ length;
    }
    return length;
}

char* string_copy(const char* string) {
    // we need to add 1 because of ’\0’
    char* result = new char[string_length(string) + 1];
    // write your code here (remember zero-termination !)
    for(int idx = 0; idx < string_length(string) + 1; ++ idx) {
        result[idx] = *(string+idx);
    }
    return result;
}

int main(int argc, char** argv) {
    const char* string_c = "This is a string and is a long one so that we can create memory leaks when it is copied and not deleted";
    // write your code here
    cout << string_copy(string_c) <<endl;
    return 0;
}
