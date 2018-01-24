

// Skeleton gradient_descent_1d
double skel_gradient_descent_1d( SimpleGraph* plot, double x, double (*energy)( double, double& ) ) {
}

/*

Call this in the following way:

double energy( double x, double& grad ) {
	grad = 2*x;
	return x*x;
}

SimpleGraph* plot = SimpleGraph::getInstance();
double xSolution = skel_gradient_descent_1d( plot, 1, energy );


*/


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

double energy_nd (const vector<double>& xs, vector<double>& grads ) {
    double value = xs[0] * xs[0] + (xs[2] - 1) * (xs[2] - 1) + (xs[0] - xs[1]) * (xs[0] - xs[1]) + (xs[1] - xs[2]) * (xs[1] - xs[2]);
    grads.resize(xs.size());
    grads[0] = 2 * xs[0] + 2 * (xs[0] - xs[1]);
    grads[1] = 2 * (xs[1] - xs[0]) + 2 * (xs[1] - xs[2]);
    grads[2] = 2 * (xs[2] - 1) + 2 * (xs[2] - xs[1]);
    return value;
}
