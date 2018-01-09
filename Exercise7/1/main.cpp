
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
    std::cout << "Solution 1. a) and b)" << endl;
    std::vector<double> array;
    // fill this array with values
    array.push_back( 29 );
    array.push_back( 49 );
    array.push_back( 52 );
    array.push_back( 26 );
    array.push_back( 89 );

    // iterate using pointers
    // &array[0] : is the pointer to the first element
    // (&array[0]) + array.size() : is the pointer *behind* the last element
    for( double* it1 = &array[0]; it1 != (&array[0]) + array.size(); ++ it1 ) {
    std::cout << *it1 << " ";
    }
    std::cout << endl;
    // change the data
    array[0] = 49;
    array[1] = 29;
    std::swap( array[2], array[3]) ;
    // iterate using iterators. See that they share the same semantics.
    for( std::vector<double>::iterator it1 = array.begin(); it1 != array.end(); ++ it1 )
    {
    std::cout << *it1 << " ";
    }
    std::cout << endl;

    std::cout << endl << "Solution 1. c)" << endl;
    std::list<double> list;
    // fill this array with values
    list.push_back(29);
    list.push_back(49);
    list.push_back(52);
    list.push_back(26);
    list.push_back(89);

    // iterate using iterators. See that they share the same semantics.
    for( std::list<double>::iterator it1 = list.begin(); it1 != list.end(); ++ it1 ){
        std::cout << *it1 << " ";
    }
    std::cout << endl;

    return 0;
}
