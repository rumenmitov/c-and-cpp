/* 
   CH-230-A 
   a10_p8.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

#include "Complex.h"

// constructors
Complex::Complex() {
    real = 0;
    imag = 0;
}

Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

Complex::Complex(const Complex& c) {
    real = c.real;
    imag = c.imag;
}

// no need for destructor as no memory was allocated
Complex::~Complex() {}

// getters
double Complex::getReal() { return real; }
double Complex::getImag() { return imag; }

// setters
void Complex::setReal(double real) { this->real = real; }
void Complex::setImag(double imag) { this->imag = imag; }

// print complex number
void Complex::Print() {
    std::cout << real;
    if (imag != 0) 
        std::cout << " " << ((imag < 0) ? "- " : "+ ") << std::abs(imag) 
        << "i";
    std::cout << std::endl;
}

// print conjugate as per task specifications
void Complex::Conjugate() {
    std::cout << real;
    if (imag != 0) 
        std::cout << " " << ((imag < 0) ? "+ " : "- ") << std::abs(imag) 
        << "i";
    std::cout << std::endl;
}

// add, subtract and multiplication methods
Complex Complex::add(Complex c) {
    Complex res;
    res.real = this->real + c.real;
    res.imag = this->imag + c.imag;

    return res;
}

Complex Complex::subtract(Complex c) {
    Complex res;
    res.real = this->real - c.real;
    res.imag = this->imag - c.imag;

    return res;
}

Complex Complex::multiply(Complex c) {
    Complex res;

    res.real = real * c.real - (imag * c.imag);
    res.imag = real * c.imag + imag * c.real;

    return res;
}

