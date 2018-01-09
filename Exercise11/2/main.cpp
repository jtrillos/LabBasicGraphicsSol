
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

void print_vector(vector<double> vec){
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

/*function gradient_descent(f, gradient_f, x0) do
    x <- x0, y <- f(x), lambda <- 1e-4
    while lambda > 1e-6 and ||gradient_f(x)|| > 1e-3 do
        x1 <- x - lambda * gradient_f(x) # next position and
        y1 <- f(x1) # new function value
        if y1 < y then # did the energy decrease, then do the step
            x <- x1, y <- y1
            lambda <- lambda * 1.2 # slowly increase step size
        else
            lambda <- lambda / 2.0 # no, we went too far, decrease step size
        end
        if |y1 - y| < 1e-6 then
            break
    end
end*/

//2. a)
double skel_gradient_descent_1d( double x0, double (*energy)( double, double& ) ){
    double lambda = 1e-4;
    double x = x0;
    double grad;
    double y = energy(x, grad);
    while (lambda > 1e-6 && abs(grad) > 1e-3) {
        double x1 = x - lambda * grad;
        double y1 = energy(x1, grad);
        if (y1 < y){
            x = x1;
            y = y1;
            lambda = lambda * 1.2;
        } else{
            lambda = lambda / 2.0;
        }
    }
    return x;
}

double energy( double x, double& grad ) {
    grad = 2 * x;
    return pow(x,2);
}

//2. c)
vector<double> skel_gradient_descent_nd(const vector<double>& x0, double (*energy_nd)( const vector<double>&, vector<double>& ) ){
    double lambda = 1e-4;
    vector <double> x = x0;
    vector <double> x1, grads;
    double y = energy_nd(x, grads);
    while (lambda > 1e-6 && norm_vector(grads) > 1e-3) {
        x1.resize(x.size());
        for (int i = 0; i < x.size(); i++) {
            x1[i] = x[i] - lambda * grads[i];
        }
        double y1 = energy_nd(x1, grads);
        if (y1 < y){
            x = x1;
            y = y1;
            lambda = lambda * 1.2;
        } else{
            lambda = lambda / 2.0;
        }
    }
    return x;
}

double energy_nd (const vector<double>& xs, vector<double>& grads ) {
    double value = xs[0] * xs[0] + (xs[2] - 1) * (xs[2] - 1) + (xs[0] - xs[1]) * (xs[0] - xs[1]) + (xs[1] - xs[2]) * (xs[1] - xs[2]);
    grads.resize(xs.size());
    grads[0] = 2 * xs[0] + 2 * (xs[0] - xs[1]);
    grads[1] = 2 * (xs[1] - xs[0]) + 2 * (xs[1] - xs[2]);
    grads[2] = 2 * (xs[2] - 1) + 2 * (xs[2] - xs[1]);
    return value;
}

int main()
{
    //2. b)
    double xSolution = skel_gradient_descent_1d( 2, energy );
    cout << "1d:  " << xSolution << endl;
    cout << "The 1d gradient is:" << endl;
    cout << 2 * xSolution << endl << endl;

    //2. d)
    vector<double> start;
    start.push_back( 1 );
    start.push_back( 2 );
    start.push_back( 3 );
    vector<double> x2Solution = skel_gradient_descent_nd( start, energy_nd );
    printf("nd:  ");
    print_vector(x2Solution);
    cout << "The nd gradient is:" << endl;
    double grad1 = 2 * x2Solution[0] + 2 * (x2Solution[0] - x2Solution[1]);
    double grad2 = 2 * (x2Solution[1] - x2Solution[0]) + 2 * (x2Solution[1] - x2Solution[2]);
    double grad3 = 2 * (x2Solution[2] - 1) + 2 * (x2Solution[2] - x2Solution[1]);
    cout << grad1 << " " << grad2 << " " << grad3 << endl;
    return 0;
}
