/* 
   CH-230-A 
   a11_p6.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include "Vector.h"
#include <iostream>

# define DIMENSION 2

int main(void) {

    // creating instances
    Vector v1;
    std::cout << "v1 = ";

    const double* v2_arr = new double[DIMENSION]{1, 2};
    Vector v2(DIMENSION, v2_arr);
    delete [] v2_arr;

    Vector v3(v2);

    const double* v4_arr = new double[DIMENSION]{3, 4};
    Vector v4(DIMENSION, v4_arr);
    delete [] v4_arr;

    // executing tasks
    std::cout << "||v2|| = " << v2.norm() << std::endl;

    std::cout << "v2 + v4 = ";
    (v2.add(v4)).print();

    std::cout << "v2 - v4 = ";
    (v2.subtract(v4)).print();

    std::cout << "v2 . v4 = " << v2.scalar_product(v4) << std::endl;

    return 0;
}
