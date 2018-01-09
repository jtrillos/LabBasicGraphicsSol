#include <iostream>

using namespace std;

int main()
{
    int i,n;
    int *p;
    float sum = 0;
    float mean;
    float variance;
    cout << "How many numbers would you like to type? ";
    cin >> i;
    p = new (nothrow) int[i];
    if (p == 0)
        cout << "Error: memory could not be allocated";
    else{
        for (n=0; n<i; n++){
            cout << "Enter number: ";
            cin >> p[n]; }
            cout << "You have entered: ";
            for (n=0; n<i; n++){
                cout << p[n] << ", ";
                sum += p[n];
            }
            cout << endl;
            mean = sum/n;
            cout << "The mean is: " << mean << endl;

            float temp=0;
            for (n=0; n<i; n++){
                temp += (mean-p[n]) * (mean-p[n]);
            }
            variance = temp/n;
            cout << "The variance is: " << variance << endl;
            delete[] p;
    }
    return 0;
}
