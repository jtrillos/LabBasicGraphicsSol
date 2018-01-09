/*
* Jaime Manuel Trillos Ujueta
* 2895358
*/
#include <iostream>

using namespace std;

int main()
{
    int res = 0;
    for(unsigned char c=100; c>=0; --c) {
        res = res + 1;
    }
    cout << (int) res << std::endl;
    return 0;
}
