/* 
   CH-230-A 
   a12_p6.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include "Rectangle.h"
#include "Square.h"

Square::Square(const char *n, double sideLength) : 
    Rectangle(n, sideLength, sideLength), sideLength(sideLength) {}

Square::~Square() {
}

double Square::calcArea() const {
	std::cout << "calcArea of Square...\n";
	return sideLength * sideLength;
}

double Square::calcPerimeter() const {
	std::cout << "calcPerimeter of Square...\n";
    return 4 * sideLength;
}
