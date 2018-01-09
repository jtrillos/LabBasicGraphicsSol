#ifndef __TOOLS_H
#define __TOOLS_H


#include "SimpleGraph.h"

#include <cmath>
#include <vector>

using namespace std;



double sqr( double x ) {
	return x*x;
}

inline void create_random( int seed, int count, double min, double max, std::vector<double>& out ) {
	srand( seed );
	out.reserve( count ); out.clear();
	while( count-- > 0 ) {
		out.push_back( min + (max-min) * ((double)rand() / (double)RAND_MAX) );
	}
}

inline double norm_vector( const vector<double>& grad ) {
	double sum = 0;
	for( auto it = grad.begin(); it != grad.end(); ++ it ) {
		sum = sum + (*it)*(*it);
	}
	return sqrt( sum );
}









#endif