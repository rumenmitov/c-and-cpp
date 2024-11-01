/* 
   CH-230-A 
   a10_p8.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef COMPLEX_H
#define COMPLEX_H

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
        void Print();
        void Conjugate();

        // add, subtract and multiplication written with prototypes from task
        Complex add(Complex);
        Complex subtract(Complex);
        Complex multiply(Complex);
        
};

#endif
