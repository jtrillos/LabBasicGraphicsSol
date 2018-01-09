
#include <iostream>
#include "tools.h"
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <queue>
#include <cmath>
#include <math.h>

using namespace std;

double mySum(double d1, double d2) {
    double reduce_d1 = reducePrecision(d1);
    double reduce_d2 = reducePrecision(d2);
    return (reduce_d1+reduce_d2);
}

void print_vector(vector<double> vec){
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

int main()
{
    int count = 1000;
    double min = 100;
    double max = 101;
    int seed = 22;
    std::vector<double> out;

    createRandom(seed, count, min, max, out);
    //print_vector(out);

    //2. c) (i)
    double sum1 = accumulate(out.begin(), out.end(), 0.0, mySum);
    cout << "Add them up using std::accumulate: " << sum1 << endl;

    //2. c) (ii)
    vector<double> ascend = out;
    sort(ascend.begin(), ascend.end());
    double sum2 = accumulate(ascend.begin(), ascend.end(),0.0, mySum);
    cout << "Sort values ascending and then add: " << sum2 << endl;

    //2. c) (iii)
    vector<double> descend = ascend;
    reverse(descend.begin(), descend.end());
    double sum3 = accumulate(descend.begin(), descend.end(),0.0, mySum);
    cout << "Sort values descending and then add: " << sum3 << endl;

    //2. c) (iv)
    //A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element,
    //at the expense of logarithmic insertion and extraction.
    priority_queue<double, std::vector<double>, std::greater<double> > pq;
    for (int i = 0; i < out.size(); i++) {
        pq.push(out[i]);
    }
    //print_queue(pq);
    double sum4 = 0.0;
    while(!pq.empty()) {
        double small1 = pq.top();
        pq.pop();
        double small2 = pq.top();
        sum4 = sum4 + mySum(small1, small2);
        pq.pop();
    }
    cout << "Gather the values in a min-heap and then add: " << sum4 << endl;

    return 0;
}
