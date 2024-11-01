/* 
   CH-230-A 
   a13_p2.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <fstream>

#include "Complex.h"

int main(void) {

    std::ifstream f_in1("in1.txt");
    if (!f_in1.good()) {
        std::cerr << "Couldn't open in1.txt";
        exit(1);
    }

    std::ifstream f_in2("in2.txt");
    if (!f_in2.good()) {
        std::cerr << "Couldn't open in2.txt";
        exit(1);
    }

    std::ofstream f_out("output.txt");
    if (!f_out.good()) {
        std::cerr << "Couldn't open output.txt";
        exit(1);
    }

    Complex c1, c2;

    f_in1 >> c1;
    f_in2 >> c2;

    std::cout << "sum=" << c1 + c2 << std::endl;
    std::cout << "difference=" << c1 - c2 << std::endl;
    std::cout << "product=" << c1 * c2 << std::endl;

    f_out << "sum=" << c1 + c2 << std::endl;
    f_out << "difference=" << c1 - c2 << std::endl;
    f_out << "product=" << c1 * c2 << std::endl;

    return 0;
}
