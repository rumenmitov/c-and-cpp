/* 
   CH-230-A 
   a12_p4.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

// simple class for fractions

#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
class Fraction {

private:						// internal implementation is hidden
	int num;					// numerator
	int den;					// denominator

	int gcd(int a, int b);		// calculates the gcd of a and b
	int lcm(int a, int b);

public:
	Fraction();					// empty constructor
	Fraction(int, int = 1); 	// constructor taking values for fractions and
								// integers. Denominator by default is 1

    // setters needed for user defined fraction
    void setNum(int num) { this->num = num; }
    void setDen(int den) { this->den = den; }

    // prints it to the screen
    friend std::ostream& operator<<(std::ostream&, const Fraction&);

    // gets fraction from user
    friend std::istream& operator>>(std::istream&, Fraction&);

    // overloading operators / and *
    Fraction operator/(const Fraction&);
    Fraction operator*(const Fraction&);
};


#endif /* FRACTION_H_ */
