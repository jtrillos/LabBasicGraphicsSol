
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // std::accumulate

using namespace std;

void print_vec(vector<double> vec){
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){


    const double data[] = {
        -1.37, 2.04, 4.98, 5.36, 8.88e-1, 2.47, -1.19e-1, -5.57e-1,
        2.83, 5.38e-1, 4.69, 7.37, 3.78, 5.29, 6.30, 2.62, 2.60,
        4.35, 5.31, 3.53, 7.64, 4.41e-1, 1.61, 4.71 };
    const int dataCount = sizeof( data ) / sizeof( data[0] );

    vector<double> data_vec;
    for (int i = 0; i < dataCount; ++i){
        data_vec.push_back(data[i]);
    }
    cout << "The vector is:" << endl;
    print_vec(data_vec);

    //Re-implementation 4c with STL
    double minimum = *( min_element(data_vec.begin(), data_vec.end()) );
    double maximum = *( max_element(data_vec.begin(), data_vec.end()) );
    double sum = accumulate(data_vec.begin(), data_vec.end(), 0.0);
    double mean2 = sum / double(data_vec.size());
    cout << endl << "min: " << minimum << endl;
    cout << "max: " << maximum << endl;
    cout << "mean: " << mean2 << endl;

    //Re-implementation 4d with count_if
    int s2_2 = count_if(data_vec.begin(), data_vec.end(), [](double i) {return i < 2; });
    int s4_2 = count_if(data_vec.begin(), data_vec.end(), [](double i) {return i < 4; });
    int s6_2 = count_if(data_vec.begin(), data_vec.end(), [](double i) {return i < 6; });
    cout << endl << "# of smaller than 2: " << s2_2 << endl;
    cout << "# of smaller than 4: " << s4_2 << endl;
    cout << "# of smaller than 6: " << s6_2 << endl;

    //Sorting the array and re-implementation previous exercises
    sort(data_vec.begin(), data_vec.end());
    cout << endl << "After sorting:" << endl;
    print_vec(data_vec);

    vector<double>::iterator low2, low4, low6;
    low2 = lower_bound(data_vec.begin(), data_vec.end(), 2);
    low4 = lower_bound(data_vec.begin(), data_vec.end(), 4);
    low6 = lower_bound(data_vec.begin(), data_vec.end(), 6);

    int s2_3 = low2 - data_vec.begin();
    int s4_3 = low4 - data_vec.begin();
    int s6_3 = low6 - data_vec.begin();
    cout << "# of smaller than 2: " << s2_3 << endl;
    cout << "# of smaller than 4: " << s4_3 << endl;
    cout << "# of smaller than 6: " << s6_3 << endl;

    //Copying the vector 4 times
    vector<double> data_vec4(4*data_vec.size());
    copy(data_vec.begin(), data_vec.end(), data_vec4.begin());
    copy(data_vec.begin(), data_vec.end(), data_vec4.begin() + data_vec.size());
    copy(data_vec.begin(), data_vec.end(), data_vec4.begin() + 2 * data_vec.size());
    copy(data_vec.begin(), data_vec.end(), data_vec4.begin() + 3 * data_vec.size());
    cout << endl << "After copying:" << endl;
    print_vec(data_vec4);

    //Sorting and removing duplicates (unique)
    sort(data_vec4.begin(), data_vec4.end());
    auto last = unique(data_vec4.begin(), data_vec4.end());
    data_vec4.erase(last, data_vec4.end());
    cout << endl << "After removing duplicates:" << endl;
    print_vec(data_vec4);
    return 0;
}
