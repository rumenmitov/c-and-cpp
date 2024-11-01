/* 
   CH-230-A 
   a12_p6.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef _CIRCLE_H
#define _CIRCLE_H
#include "Area.h"

class Circle : public Area {
	public:
		Circle(const char *n, double a);
		~Circle();
		double calcArea() const;

        // getter for radius required by Ring
        double getRadius() const { return radius; }
        // perimeter of a circle is 2π * radius
        double calcPerimeter() const;
	private:
		double radius;
};

#endif
