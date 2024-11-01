/* 
   CH-230-A 
   a12_p6.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <cmath>
#include "Circle.h"

Circle::Circle(const char *n, double a) : Area(n) {
	radius = a;
}

Circle::~Circle() {
}

double Circle::calcArea() const {
	std::cout << "calcArea of Circle...\n";
	return radius * radius * M_PI;
}

double Circle::calcPerimeter() const {
    std::cout << "calcPerimeter of Circle...\n";
    return 2 * radius * M_PI;
}
