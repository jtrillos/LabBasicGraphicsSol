#ifndef TOOLS_MATH_H
#define TOOLS_MATH_H

#include <cmath>
#include <vector>

using namespace std;

inline vector<double> add_vector( const vector<double>& xs, const vector<double>& grad ) {
	vector<double> res( xs );

	for( size_t i1 = 0; i1 < res.size(); ++ i1 ) {
		res[i1] = res[i1] + grad[i1];
	}
	return res;
}

inline vector<double> mul_vector( double lambda, const vector<double>& grad ) {
	vector<double> res( grad );

	for( size_t i1 = 0; i1 < res.size(); ++ i1 ) {
		res[i1] = lambda * res[i1];
	}

	return res;
}

template< typename T >
inline T sqr( T a ) { return a*a; }

inline void create_random( int seed, int count, double min, double max, std::vector<double>& out ) {
	srand( seed );
	out.reserve( count ); out.clear();
	while( count-- > 0 ) {
		out.push_back( min + (max-min) * ((double)rand() / (double)RAND_MAX) );
	}
}

inline double vector_norm( const vector<double>& grad ) {
	double sum = 0;
	for( auto it = grad.begin(); it != grad.end(); ++ it ) {
		sum = sum + (*it)*(*it);
	}
	return sqrt( sum );
}

#endif