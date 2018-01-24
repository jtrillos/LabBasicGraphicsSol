
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
#include "SimpleImage.h"

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

double g_x(double c1, double c2, double x){
   return c1 * sin(2 * PI * c2 * x) + c2 * cos(2 * PI * c1 * x);
}

double g_fit_energy(vector<double>& c){
    double energy = 0.0;
    for(int i = 0; i < samplesX.size(); i++){
        energy += pow((g_x(c[0],c[1],samplesX[i]) - samplesY[i]), 2);
    }
    return energy;
}

vector<double> gradient_e(vector<double>& c){
   vector<double> delta;
    delta.resize(2, 0.0);
    for(int i = 0; i < 100; i++){
        auto val = 2 * (g_x(c[0],c[1],samplesX[i]) - samplesY[i]);
        delta[0] += val * (sin(2 * PI * c[1] * samplesX[i]) - 2 * PI * samplesX[i] * c[1] * sin(2 * PI * c[0] * samplesX[i]));
        delta[1] += val * (2 * PI * c[0] * samplesX[i] * cos(2 * PI * c[1] * samplesX[i]) + cos(2 * PI * c[0] * samplesX[i]));
    }
    return delta;
}

void g_fit_energy_gradient(vector<double>& c, vector<double>& g){
    double energy = g_fit_energy(c);
    g = gradient_e(c);
    cout << "[" << c[0] << ", " << c[1] << "]: energy= " << energy;
    cout << " gradients= (" << g[0] << ", " << g[1] << ")" << endl;
}

void g_fit_energy_gradient_nd(vector<double>& c, vector<double>& g){
    double energy = g_fit_energy(c);
    g = gradient_e(c);
    cout << "[" << c[0] << ", " << c[1] << "]: energy= " << energy;
    cout << " gradients= (" << g[0] << ", " << g[1] << ")" << endl;
    vector<double> gradient_nd = skel_gradient_descent_nd( c, energy_nd );
    cout << "The nd gradient is: ";
    print_vector(gradient_nd);
}

int main()
{
    SimpleImage& vis = *SimpleImage::getInstance();
    SimpleGraph* plot = SimpleGraph::getInstance();
    //2. a)
    sampleG();
    plot->setData( samplesX , samplesY );
    plot->show();

    //2. b) c)
    vector<double> grads_c ={0.0, 0.0};
    vector<vector<double>> constant = {{3,10}, {3.5,10}, {4,10}, {3,10.5}, {3,11}};
    for(int i = 0; i < constant.size(); i++){
        g_fit_energy_gradient(constant[i],grads_c);
    }

    //2. d) e)
    cout << endl;
    vector<double> g_c ={0.0, 0.0};
    vector<vector<double>> c = {{3.1,10.1},{3.5,10}, {4,10}, {3,10.5}, {3,11}};
    for(int i = 0; i < c.size(); i++){
        g_fit_energy_gradient_nd(c[i],g_c);
    }

    //2. f)
    vis.create(300,300); //create an image with 300x300 pixels
    for (int i = 0; i < c.size(); i++){
        double energy = g_fit_energy(c[i]);
        vis(c[i][0], c[i][1]) = energy;
    }
    vis.show(); //close window to continue


    return 0;
}
