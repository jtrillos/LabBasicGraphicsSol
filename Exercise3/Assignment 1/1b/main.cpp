#include <iostream>

using namespace std;

int main()
{
    double number = 10.0;
    double& reference(number); // reference to variable number
    double* pointer(&number); // pointer to variable number
    std::cout << &number << "; " << &reference << "; " << pointer << std::endl;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    *pointer = 15;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    reference = 50;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    number = 10;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    return 0;
}
