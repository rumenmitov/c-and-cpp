/* 
   CH-230-A 
   a12_p4.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/


#include <cstdio>
#include <iostream>
#include <istream>
#include <ostream>
#include "fraction.h"

Fraction::Fraction()
{
	num = 1;
	den = 1;
}

Fraction::Fraction(int n, int d)
{
	int tmp_gcd = gcd(n, d);

	num = n / tmp_gcd;
	den = d / tmp_gcd;
}

int Fraction::gcd(int a, int b)
{
	int tmp_gcd = 1;

	// Implement GCD of two numbers;

	return tmp_gcd;
}

int Fraction::lcm(int a, int b)
{
	return a * b / gcd(a, b);

}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    out << frac.num << " / " << frac.den;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {
    int num, den;
    scanf("%d/%d", &num, &den);

    if (den == 0) {
        fprintf(stderr, "Illegal division by 0!\n");
        exit(1);
    }

    frac.setNum(num);
    frac.setDen(den);

    return in;
}

Fraction Fraction::operator/(const Fraction& frac) {
    Fraction res(this->num * frac.den, frac.num * this->den);

    return res;
}

Fraction Fraction::operator*(const Fraction& frac) {
    Fraction res(this->num * frac.num, this->den * frac.den);

    return res;
}
