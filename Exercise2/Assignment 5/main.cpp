/*
* Jaime Manuel Trillos Ujueta
* 2895358
*/
#include <iostream>

using namespace std;

int main()
{
    int array[100] = {0};
    for (int i = 2; i < 100; i++){
        for (int j = i * i; j < 100; j+=i){
            array[j - 1] = 1;
        }
    }
    for (int i = 2; i < 100; i++){
        if (array[i - 1] == 0){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
