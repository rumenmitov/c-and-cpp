/* 
   CH-230-A 
   a12_p6.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef _SQUARE_H
#define _SQUARE_H
#include "Area.h"
#include "Rectangle.h"

class Square : public Rectangle {
	public:
		Square(const char *n, double sideLenght);
		~Square();
		double calcArea() const;

        // perimeter of a square is 4 * sideLength
        double calcPerimeter() const;
	private:
		double sideLength;
};

#endif
