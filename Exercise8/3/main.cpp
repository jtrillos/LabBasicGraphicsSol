
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

void print_vector(vector<double> vec){
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<double> generateSamplePoints(double x1, double x2, int number){
    vector<double> xs;
    double x;
    for (int i = 0; i < number; i++) {
        x = exp(log(x1) + (log(x2) - log(x1)) * i / number);
        xs.push_back(x);
    }
    return xs;
}

vector<double> f_x(vector<double> x){
    vector<double> ys;
    double y;
    for (int i = 0; i < x.size(); i++) {
        y = (1 - cos(x[i])) / (pow(x[i], 2));
        ys.push_back(y);
    }
    return ys;
}

vector<double> g_x(vector<double> x){
    vector<double> gs;
    double g;
    for (int i = 0; i < x.size(); i++) {
        g = (1.0 / 2.0 * pow(x[i], 2) - 1.0 / 24.0 * pow(x[i], 4)) / (pow(x[i], 2));
        //cout << g << "  ";
        gs.push_back(g);
    }
    return gs;
}

vector<double> b_x(vector<double> x){
    vector<double> bs;
    double b;
    for (int i = 0; i < x.size(); i++) {
        b = exp(-abs(x[i]) * pow(10, 3));
        bs.push_back(b);
    }
    return bs;
}

vector<double> F_x(vector<double> x){
    vector<double> Fs, f, g, b;
    double F;
    f = f_x(x);
    g = g_x(x);
    b = b_x(x);
    for (int i = 0; i < x.size(); i++) {
        F = b[i] * g[i] + (1 - b[i]) * f[i];
        Fs.push_back(F);
    }
    return Fs;
}

int main()
{
    vector<double> xs, ys, gs, bs, Fs;

    //3. a)
    double x1 = pow(10, -15);
    double x2 = 1;
    int number = 1000;
    xs = generateSamplePoints(x1, x2, number);
    //print_vector(xs);

    //3. b)
    ys = f_x(xs);
    plotLogX(xs, ys);
    gs = g_x(xs);
    plotLogX(xs, gs);

    //3. c)
    bs = b_x(xs);
    plotLogX(xs, bs);

    //3. d)
    Fs = F_x(xs);
    plotLogX(xs, Fs);
    return 0;
}
