

// Skeleton gradient_descent_1d
double skel_gradient_descent_1d( double x, double (*energy)( double, double& ) );


/*

Call this in the following way:

double energy( double x, double& grad ) {
    grad = 2*x;
    return x*x;
}

double xSolution = skel_gradient_descent_1d( 1, energy );


*/

vector<double> skel_gradient_descent_nd(
    const vector<double>& x, double (*energy)( const vector<double>&, vector<double>& ) );


/*

Call this in the following way:

// function f(x0,x1) = x0^2 + x0*x1 + x1^2
double (*energy_nd)( const vector<double>& xs, vector<double>& grads ) {
    double value = xs[0]*xs[0] + xs[0]*xs[1] + xs[1] * xs[1];
    grads[0] = 2*xs[0] + xs[1];
    grads[1] = xs[0] + 2* xs[1];
    return value;
}

vector<double> start; start.push_back( 1 ); start.push_back( 2 );
vector<double> xSolution = skel_gradient_descent_nd( start, energy_nd );


*/
