/* 
   CH-230-A 
   a10_p8.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

#include "Complex.h"

int main(void) {

    Complex c1, c2, c3;


    // get user input
    double real, imag;

    std::cout << "First complex number:\n";
    std::cout << "Real: ";
    std:: cin >> real;
    c1.setReal(real);
    std::cout << "Imaginary: ";
    std:: cin >> imag;
    c1.setImag(imag);
    std::cout << std::endl;

    std::cout << "Second complex number:\n";
    std::cout << "Real: ";
    std:: cin >> real;
    c2.setReal(real);
    std::cout << "Imaginary: ";
    std:: cin >> imag;
    c2.setImag(imag);
    std::cout << std::endl;

    // results
    std::cout << "First complex number is: ";
    c1.Print();

    std::cout << "The conjugate of the first number is: ";
    c1.Conjugate();

    std::cout << "Second complex number is: ";
    c2.Print();

    std::cout << "The conjugate of the second number is: ";
    c2.Conjugate();

    c3 = c1.add(c2);
    std::cout << "The result of c1 + c2 is: ";
    c3.Print();

    c3 = c1.subtract(c2);
    std::cout << "The result of c1 - c2 is: ";
    c3.Print();

    c3 = c1.multiply(c2);
    std::cout << "The result of c1 * c2 is: ";
    c3.Print();

    return 0;
}
