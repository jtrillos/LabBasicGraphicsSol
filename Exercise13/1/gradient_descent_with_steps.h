#ifndef GRADIENT_DESCENT_WITH_STEPS_H
#define GRADIENT_DESCENT_WITH_STEPS_H

#include <iostream>

#include "tools.h"

using namespace std;

vector<double> gradient_descent_nd_with_steps( const vector<double>& x0s, double (*energy_nd)( const vector<double>& x, vector<double>& grad ), double maxStepSize = -1, int steps = -1, void (*progress)( const vector<double>& x, const vector<double>& grad ) = NULL ) {
    double stepsize = 1000;
	vector<double> xs( x0s );
	
	double stepRest = maxStepSize;
	
	int iter = 0;
	vector<double> grad(xs.size());
	double e = energy_nd( xs, grad );

	if( progress ) {
		progress( xs, grad );
	}
	
	while( true ) {
		if( stepsize < 1e-10 ) {
			cout << "break: stepsize too small (" << stepsize << ")" << endl;
			break; // lambda too small
		}
		if( vector_norm(grad) < 1e-10 ) {
			cout << "break: gradient too small (" << vector_norm(grad) << ")" << endl;
			break; // gradient too small
		}
		if( steps == 0 ) {
			cout << "break: sufficient steps" << endl;
			break;
		}
		

		// do not walk past the rest of maxStepSize
		double curStepSize = (stepRest <= 0 || stepsize < stepRest) ? (stepsize) : (stepRest);
		
		// normalize gradient
//		vector<double> gradNormalized = mulVector( 1.0/vectorNorm(grad), grad );

		// do the step
		double gradNorm = vector_norm( grad );
		vector<double> xs_next = add_vector( xs, mul_vector( -curStepSize/gradNorm, grad ) );
		vector<double> grad_next(xs.size());
		double e_next = energy_nd( xs_next, grad_next );
		
		double c1 = 0.9; // 1e-3;
		if( e_next <= e - gradNorm * curStepSize * c1 ) { // wolfe condition
//		if( e_next <= e - sqr(gradNorm) * curStepSize * c1 ) { // wolfe condition
			cout << "iter: " << ++ iter << " energy: " << e << " -> " << e_next << "; stepsize: " << stepsize << endl;
			xs = xs_next;
			e = e_next;
			grad = grad_next;

			stepsize = stepsize * 1.1;
			if( maxStepSize > 0 ) {
				stepsize = std::min( stepsize, maxStepSize );
			}

			stepRest -= curStepSize;
			if( stepRest <= 0 ) {
                if( progress && steps % 10 == 0 ) {
					progress( xs, grad );
				}
				if( steps > 0 ) {
					-- steps;
				}
				stepRest = maxStepSize;
			}

		} else {
			stepsize = stepsize / 2.0;
		}

	}

	return xs;
}


#endif

