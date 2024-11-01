/* 
   CH-230-A 
   a12_p5.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/


#include <cstdio>
#include <iostream>
#include <istream>
#include <ostream>
#include "fraction.h"

Fraction::Fraction() {
	num = 1;
	den = 1;
}

Fraction::Fraction(int n, int d) {
	int tmp_gcd = gcd(n, d);

	num = n / tmp_gcd;
	den = d / tmp_gcd;
}

int Fraction::gcd(int a, int b) {
    if (b == 0) return a;
    if (a == 0) return b;

    int rem = a % b;

	return gcd(b, rem);
}

int Fraction::lcm(int a, int b) {
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

const Fraction& Fraction::operator=(const Fraction& frac) {
    this->num = frac.num;
    this->den = frac.den;

    return *this;
}

Fraction Fraction::operator/(const Fraction& frac) {
    Fraction res(this->num * frac.den, frac.num * this->den);

    return res;
}

Fraction Fraction::operator*(const Fraction& frac) {
    Fraction res(this->num * frac.num, this->den * frac.den);

    return res;
}

Fraction Fraction::operator+(const Fraction& frac) {
    int new_den = lcm(this->den, frac.den);
    int new_num = (this->num * new_den / this->den) + (frac.num * new_den / frac.den);

    return Fraction(new_num, new_den);
}

Fraction Fraction::operator-(const Fraction& frac) {
    int new_den = lcm(this->den, frac.den);
    int new_num = (this->num * new_den / this->den) - (frac.num * new_den / frac.den);

    return Fraction(new_num, new_den);
}

bool Fraction::operator>(const Fraction& frac) {
    return (float (this->num) / this->den) > (float (frac.num) / frac.den);
}

bool Fraction::operator<(const Fraction& frac) {
    return this->num / this->den < frac.num / frac.den;
}
