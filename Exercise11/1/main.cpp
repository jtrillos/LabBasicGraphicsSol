
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

vector<double> f_x(vector<double> x, int u){
    vector<double> fx;
    double f;
    for (int i = 0; i < x.size(); i++) {
        f = pow(x[i],2) - u;
        fx.push_back(f);
    }
    return fx;
}

double f(double x){
    return (pow(x,2) - 2);
}

double f_dev(double x){
    return 2*x;
}

vector<double> f_dev(vector<double> x){
    vector<double> f_dev;
    double epsilon = 0.1e-10; //say
    double temp;
    for (int i=0; i<x.size(); i++){
        temp= (f(x[i]+epsilon)-f(x[i]))/epsilon;
        f_dev.push_back(temp);
    }
    return f_dev;
}

double g(double x){
    return (x/2+1/x);
}

vector<double> g_x(vector<double> x){
    vector<double> gs, f, fdev;
    f=f_x(x, 2);
    fdev=f_dev(x);
    double g;
    for (int i=0; i<x.size(); i++) {
        g=x[i]-f[i]/fdev[i];
        gs.push_back(g);
    }
    return gs;
}

double f_est(double x, double x0){
    return f(x0)+(x-x0)*f_dev(x0);
}

/*function root = newton( x0, f, f‘, epsilon, maxiterations )
    iteration <- 0, x <- x0
    do
        xp <- x
        x <- x - f(x) / f‘(x)
        iteration <- iteration + 1
    until iteration > maxiterations or abs(x-xp) < epsilon
    root <- x
end*/

double newton(double randicand, double index, double epsilon){
    double m = index - 1, x = 1.0;
    double xp = 0.0;
    while(abs(xp - x) >= epsilon){
        xp = x;
        x = x + (-1 * (pow(x,index)) + randicand) / (index * pow(x,m));
    }
    return x;
}

int main()
{
    //1. a)
    SimpleGraph* plot = SimpleGraph::getInstance();
    vector<double> fs, xs, fdev, gs;
    for (int i = 0; i <= 2 / 0.002; i++) {
        xs.push_back((double)i * 0.002);
    }
    //print_vector(xs);

    //draw f_x in [0, 2].
    fs = f_x(xs, 2);
    plot->setData( xs, fs );
    plot->show();

    //draw f_dev in [0, 2].
    fs = f_x(xs, 2);
    fdev = f_dev(xs);
    plot->setData( xs, fdev );
    plot->show();

    //draw g_x in [0, 2]
    gs = g_x(xs);
    plot->setData( xs, gs );
    plot->show();
    //print_vec(gs);

    cout << "f_dev = 2x" << endl;
    cout << "g_x = x/2+1/x" << endl;

    //1. b)
    double x0 = 2;
    double root0 = g(x0);
    cout << "First estimate is: " << root0 << endl;
    fs = f_x(xs, 2);
    plot->setData( xs, fs );
    plot->markPosition(root0);
    plot->show();
    plot->clear();

    //1. c)
    const double epsilon = 0.000001; //tolerance (sixt decimal)
    double root = 2.0;
    int count = 0;
    while (abs(sqrt(2) - root) >= epsilon) {
        x0 = root;
        double x1 = 0.0;
        double y1 = f_est(x1, x0);
        double y0 = f_est(x0, x0);
        fs = f_x(xs, 2);
        plot->setData( xs, fs );
        root = g(x0);
        plot->markPosition(root);
        plot->addLine(x1, y1, x0, y0);
        plot->show();
        count ++;
    }
    cout << "Total iterations: " << count << endl;
    cout << "Root is: " << root << endl;

    double r, i;
    bool flag = false;
    cout << "Enter the radicand:" << endl;
    cin >> r;
    do {
        cout << "Enter the index (index >= 2):" << endl;
        cin >> i;
        if (i >= 2){
            flag = true;
        }
    }while (!flag);
    cout << "The root is: " << newton(r, i, epsilon) << endl;
    cout << "Complexity: O((log n) F(n)) where F(n) is the cost of calculating f(x)/f'(x)" << endl;
    cout << "Solution: If f(x) can be evaluated with variable precision, the algorithm can be improved." << endl;
    /*
     * Because of the "self-correcting" nature of Newton's method, meaning that it is unaffected by small perturbations
     * once it has reached the stage of quadratic convergence, it is only necessary to use m-digit precision at a step
     * where the approximation has m-digit accuracy. Hence, the first iteration can be performed with a precision twice
     * as high as the accuracy of x_0, the second iteration with a precision four times as high, and so on. If the precision
     * levels are chosen suitably, only the final iteration requires f(x)/f'(x)\, to be evaluated at full n-digit precision.
     */
    cout << "Then the complexity is O(F(n))" << endl; //Taken from: https://stackoverflow.com/questions/5005753/what-is-newton-raphson-square-methods-time-complexity

    return 0;
}
