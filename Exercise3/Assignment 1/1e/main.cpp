#include <iostream>

using namespace std;

int main()
{
    double array[5] = { 10.0, 20.0, 30.0, 40.0, 50.0 };
    double* begin = array;
    std::cout << *(begin + 0) << std::endl;
    std::cout << *(begin + 1) << std::endl;
    std::cout << *(begin + 2) << std::endl;
    double* end = array + 5;
    int diff = end - begin;
    diff /= 2;
    double value = *(begin + 1) + *(end - (diff));
    std::cout << value << std::endl;
    std::cout << *end << std::endl;
    double* ptr = begin;
    while (ptr != end) {
        std::cout << *(ptr ++) << " ";
    }
    std::cout << endl;
    ptr = end;
    while (ptr != begin) {
        std::cout << *(-- ptr) << " ";
    } ;
    std::cout << endl;
    return 0;
}
