
#include <iostream>
#include "tools.h"
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <queue>
#include <cmath>
#include <math.h>
#include "gradient_descent_skel.h"

using namespace std;

vector<double> samplesX, samplesY;

void sampleG(){
    //g_(3,10)
    for (int i = 0; i <= 100; i++) {
        samplesX.push_back((double) i / 100.0);
        samplesY.push_back((double) 3 * sin(2 * PI * 10 * samplesX[i]) + 10 * cos(2 * PI * 3 * samplesX[i]));
    }
}

void print_vector(vector<double> vec){
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

double order_polynomial(vector<double>& a, double x){
    double pol = 0;
    for (int i = 0; i < a.size(); i++) {
        int p = a.size() - 1 - i;
        pol += (a[p] * pow(x,p));
    }
    return pol;
}

double energy_function(vector<double>& a){
    double energy = 0.0;
    for(int i = 0; i < samplesX.size(); i++){
        energy += pow((order_polynomial(a, samplesX[i]) - samplesY[i]), 2);
    }
    return energy;
}

vector<double> gradient_e(vector<double>& a){
    vector<double> delta;
    delta.resize(a.size(), 0.0);
    for(int i = 0; i < samplesX.size(); i++){
        auto val = 2 * (order_polynomial(a, samplesX[i]) - samplesY[i]);
        for (int j = 0; j < a.size(); j++){
            delta[a.size() - 1 - j] += val * pow(samplesX[i], j);
        }
    }
    return delta;
}

void polynomial_fit_energy(vector<double>& a){
    std::reverse(a.begin(),a.end());
    double energy = energy_function(a);
    vector<double> param = gradient_e(a);
    cout << "a = [ ";
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "] => Energy = " << energy << " and Gradient: ";
    for (int i = 0; i < param.size(); i++){
        cout << param[i] << " ";
    }
    cout << endl;
}


void polynomial_fit_energy_grad_nd(vector<double>& a){
    std::reverse(a.begin(),a.end());
    double energy = energy_function(a);
    vector<double> param = gradient_e(a);
    cout << "a = [ ";
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "] => Energy = " << energy << " and Gradient: ";
    for (int i = 0; i < param.size(); i++){
        cout << param[i] << " ";
    }
    cout << endl;
    vector<double> gradient_nd = skel_gradient_descent_nd( param, energy_nd );
    cout << "The nd gradient is: ";
    print_vector(gradient_nd);
}

int main()
{
    //1. a)
    SimpleGraph* plot = SimpleGraph::getInstance();
    sampleG();

    //1. b)
    plot->setData( samplesX , samplesY );
    plot->show();

    //1. c) d)
    vector<double> a;
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    polynomial_fit_energy(a);
    a.clear();
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    polynomial_fit_energy(a);
    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    polynomial_fit_energy(a);
    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    polynomial_fit_energy(a);
    a.clear();
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    polynomial_fit_energy(a);
    a.clear();

    //1. e)
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    polynomial_fit_energy_grad_nd(a);
    a.clear();

    //1. f)
    int count = 4;
    double min = 0;
    double max = 10000;
    int seed = 123456;
    std::vector<double> out;
    create_random(seed, count, min, max, out);
    //print_vector(out);
    polynomial_fit_energy(out);

    return 0;
}
