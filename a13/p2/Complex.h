/* 
   CH-230-A 
   a13_p2.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
    private:
        double real;
        double imag;

    public:

        // constructors
        Complex();
        Complex(double, double);
        Complex(const Complex&);

        // destructor
        ~Complex();

        // getters
        double getReal();
        double getImag();

        // setters
        void setReal(double);
        void setImag(double);

        // methods
        void Conjugate();

        /* 
         * add, subtract, multiplication and assignment
         * written with prototypes from task
         */
        Complex operator+(const Complex&) const;
        Complex operator-(const Complex&) const;
        Complex operator*(const Complex&) const;
        const Complex& operator=(const Complex&);

        // overloading stream operators 
        friend std::istream& operator>>(std::istream& in, Complex&);
        friend std::ostream& operator<<(std::ostream& out, const Complex&);

        
};

#endif
