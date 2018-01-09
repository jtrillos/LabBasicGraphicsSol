#ifndef __TOOLS_H
#define __TOOLS_H


#include "SimpleGraph.h"

#include <cmath>
#include <vector>

using namespace std;

void createRandom( int seed, int count, double min, double max, std::vector<double>& out ) {
	srand( seed );
	out.reserve( count ); out.clear();
	while( count-- > 0 ) {
		out.push_back( min + (max-min) * ((double)rand() / (double)RAND_MAX) );
	}
}

double roundFloat( double x, int binaryDigits ) { 
	return ldexp( floor( ldexp( x, binaryDigits ) + 0.5 ), -binaryDigits ); 
}

double reducePrecision( double x ) { 
	int exp; 
	double m = frexp(x, &exp); 
	m = roundFloat( m, 10 ); 
	return ldexp( m, exp ); 
}


void plotLogX( const vector<double>& xs, const vector<double>& ys) {
	SimpleGraph* plot = SimpleGraph::getInstance();
	plot->setData( xs, ys );
	plot->setLogX( true );
	plot->show(); //close window to continue
}


#endif
