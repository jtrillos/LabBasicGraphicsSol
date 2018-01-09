#include <iostream>

using namespace std;

void callByValue(int value) {
    value = 5;
}
void callByReference(int&
    reference) {
    reference = 10;
}
void callByPointer(int* pointer) {
    *pointer = 20;
}

int main()
{
    int value = 0;
    callByValue(value);
    std::cout << value << std::endl;
    callByReference(value);
    std::cout << value << std::endl;
    callByPointer(&value);
    std::cout << value << std::endl;
    return 0;
}
