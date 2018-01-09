
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

vector<double> f_2(vector<double> x, int u){
    vector<double> f_2;
    double f2;
    for (int i = 0; i < x.size(); i++) {
        f2 = pow(x[i],2) - u;
        f_2.push_back(f2);
    }
    return f_2;
}

double func(double x){
    return (pow(x,2) - 2);
}

/*function root = bisection( a, b, f, epsilon )
    if f(a)*f(b) >= 0
        error "No root detected in [a,b]!"
        root <- 0
        return
    end
    while b-a > epsilon do
        c <- (a+b)/2.0
        if f(c) == 0
            a <- c, b <- c
        else if f(a)f(c) < 0
            b <- c
        else // f(b)f(c)<0
            a <- c
        end
    end
    root <- (a+b)/2.0 // return the middle of the interval as guess
end*/

double bisection(double a, double b, double epsilon){
    double root;
    int count = 0;
    if (func(a) * func(b) >= 0){
        cout << "No root detected in [" << a << ", " << b << " ]!" << endl;
        root = 0;
        return root;
    }

    while ((b - a) > epsilon) {
        double c = (a + b) / 2.0;
        if (func(c) == 0) {
            a = c;
            b = c;
            count++;
        }else if(func(a) * func(c) < 0){
            b = c;
            count++;
        }else if(func(b) * func(c) < 0){
            a = c;
            count++;
        }
    }
    root = (a + b) / 2.0;
    cout << "Maximal error is " << (b - a) / 2.0 << endl;
    cout << count << " iterations are necessary to determine sqrt(2) up to the third decimal" << endl;
    return root;
}

double bisection2(double a, double b, double epsilon){
    double root;
    SimpleGraph* plot = SimpleGraph::getInstance();
    if (func(a) * func(b) >= 0){
        cout << "No root detected in [" << a << ", " << b << " ]!" << endl;
        root = 0;
        return root;
    }

    while ((b - a) > epsilon) {
        double c = (a + b) / 2.0;
        if (func(c) == 0) {
            a = c;
            b = c;
            plot->markPosition(a);
            plot->markPosition(b);
            plot->show();
        }else if(func(a) * func(c) < 0){
            b = c;
            plot->markPosition(a);
            plot->markPosition(b);
            plot->show();
        }else if(func(b) * func(c) < 0){
            a = c;
            plot->markPosition(a);
            plot->markPosition(b);
            plot->show();
        }
    }
    root = (a + b) / 2.0;
    return root;
}

int main()
{
    //4. a)
    SimpleGraph* plot = SimpleGraph::getInstance();
    vector<double> f2, x;
    for (int i = 0; i <= 2 / 0.002; i++) {
        x.push_back((double)i * 0.002);
    }
    //print_vector(x);
    //draw f2 in [0, 2].
    f2 = f_2(x, 2);
    plot->setData( x, f2 );
    plot->show();

    //4. b)
    double a = 0.0;
    double b = 2.0;
    double epsilon = 0.001, root;
    root = bisection(a,b,epsilon);

    //4. c)
    root = bisection2(a,b,epsilon);
    cout<<root<<endl;
    return 0;
}
