/* 
   CH-230-A 
   a13_p2.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <cstring>
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

// print conjugate as per task specifications
void Complex::Conjugate() {
    std::cout << real;
    if (imag != 0) 
        std::cout << " " << ((imag < 0) ? "+ " : "- ") << std::abs(imag) 
        << "i";
    std::cout << std::endl;
}

// add, subtract, multiplication and assignment methods
Complex Complex::operator+(const Complex& c) const {
    return Complex(this->real + c.real, this->imag + c.imag);
}

Complex Complex::operator-(const Complex& c) const {
    return Complex(this->real - c.real, this->imag - c.imag);
}

Complex Complex::operator*(const Complex& c) const {
    return Complex(this->real * c.real - this->imag * c.imag,
            this->real * c.imag + this->imag * c.real);
}

const Complex& Complex::operator=(const Complex& c) {
    this->real = c.real;
    this->imag = c.imag;
    return *this;
}

// streams overloading
std::istream& operator>>(std::istream& in, Complex& c) {
    /* NOTE
     * Complex numbers should be entered with spaces between the
     * sign.
     *
     * Example:
     * 2 + 1i
     */
    in >> c.real;
    
    // get the sign of the imaginary number
    char sign;
    in >> sign;

    // get the imaginary number and remove the i character
    char buf[255];
    in.getline(buf, sizeof(buf), 'i');

    // save the imaginary number
    sscanf(buf, "%lf", &c.imag);

    // adjust the imaginary number if necessary
    if (sign == '-') c.imag *= -1;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.real;
    if (c.imag != 0) 
        out << " " << ((c.imag < 0) ? "- " : "+ ") << std::abs(c.imag) 
        << "i";
    out << std::endl;

    return out;
}
