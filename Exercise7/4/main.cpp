
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void print_vec(vector<double> vec){
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

double getMin(vector<double> vec){
    double min = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (min > vec[i]) {
            min = vec[i];
        }
    }
    return min;
}

double getMax(vector<double> vec){
    double max = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (max < vec[i]) {
            max = vec[i];
        }
    }
    return max;
}

double getMean(vector<double> vec){
    double sum = 0;
    int size = vec.size();
    for (int i = 0; i < size; i++) {
        sum += vec[i];
    }
    double mean = sum / size;
    return mean;
}


double getDeviation(vector<double> vec){
    double m = getMean(vec);
    int size = vec.size();
    double temp = 0;
    for(int i = 0; i < size; i++)
    {
        temp += (vec[i] - m) * (vec[i] - m) ;
    }
    return sqrt(temp / size);
}

int smaller(vector<double> vec, int val){
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (val > vec[i]) {
            count++;
        }
    }
    return count;
}

int main()
{
    const double data[] = {
        -1.37, 2.04, 4.98, 5.36, 8.88e-1, 2.47, -1.19e-1, -5.57e-1,
        2.83, 5.38e-1, 4.69, 7.37, 3.78, 5.29, 6.30, 2.62, 2.60,
        4.35, 5.31, 3.53, 7.64, 4.41e-1, 1.61, 4.71 };
    const int dataCount = sizeof( data ) / sizeof( data[0] );

    //filling the vector with the values
    vector<double> data_vec;
    for (int i = 0; i < dataCount; ++i){
        data_vec.push_back(data[i]);
    }
    cout << "The vector is:" << endl;
    print_vec(data_vec);

    //erase the 2nd element
    double pos2 = data_vec[1];
    cout << endl << "After erasing and inserting:" << endl;
    data_vec.erase(data_vec.begin() + 1);
    data_vec.insert(data_vec.begin() + 6, pos2);
    print_vec(data_vec);

    //calculations:
    double min = getMin(data_vec);
    double max = getMax(data_vec);
    double mean = getMean(data_vec);
    double dev = getDeviation(data_vec);
    cout << endl << "min: " << min << endl;
    cout << "max: " << max << endl;
    cout << "mean: " << mean << endl;
    cout << "standard deviation: " << dev << endl;

    int s2 = smaller(data_vec, 2);
    int s4 = smaller(data_vec, 4);
    int s6 = smaller(data_vec, 6);
    cout << endl << "# of smaller than 2: " << s2 << endl;
    cout << "# of smaller than 4: " << s4 << endl;
    cout << "# of smaller than 6: " << s6 << endl;
    return 0;
}
