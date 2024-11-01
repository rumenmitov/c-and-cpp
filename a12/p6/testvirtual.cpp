#include <iostream>
using namespace std;
#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"
 
/* Relationship of the classes:
 *  Area
 *  |
 *  → Rectangle
 *    |
 *    → Square
 *  → Circle
 *    |
 *    → Ring
 */
const int num_obj = 7;                          // incrementing to 7, as to
                                                // have space for square
                                                // instance
int main() {
	Area *list[num_obj];						// (1) Initializing 
                                                //     a pointer to an array
                                                //     that will hold 7
                                                //     instances of Area
	int index = 0;								// (2) Initializing the index
                                                //     variable to 0
	double sum_area = 0.0;						// (3) Initializing the sum of
                                                //     the area to 0
    double sum_perimeter = 0.0;                 // initializing sum of
                                                // perimeter to 0
	cout << "Creating Ring: ";
	Ring blue_ring("BLUE", 5, 2);				// (4) Creating an instance 
                                                //     of a ring using
                                                //     a parametric constructor
                                                //     and setting the color to
                                                //     blue, the outer radius 
                                                //     to 5 and the inner 
                                                //     radius to 2
	cout << "Creating Circle: ";
	Circle yellow_circle("YELLOW", 7);
	cout << "Creating Rectangle: ";
	Rectangle green_rectangle("GREEN",5,6);
	cout << "Creating Circle: ";
	Circle red_circle("RED", 8);
	cout << "Creating Rectangle: ";
	Rectangle black_rectangle("BLACK", 10, 20);
	cout << "Creating Ring: ";
	Ring violet_ring("VIOLET", 100, 5);
    cout << "Creating Square: ";
    Square white_square("WHITE", 10);
	list[0] = &blue_ring;						// (5) Setting the first
                                                //     element of the array
                                                //     to the blue_ring
                                                //     instance of Ring 
                                                //     using pass-by-reference
	list[1] = &yellow_circle;
	list[2] = &green_rectangle;
	list[3] = &red_circle;
	list[4] = &black_rectangle;
	list[5] = &violet_ring;
    list[6] = &white_square;
	while (index < num_obj) {					// (7) Loops while index is
                                                //     smaller than the size
                                                //     of the array
		(list[index])->getColor();				
        sum_perimeter += list[index]->calcPerimeter(); // add perimeter 
                                                       // of element to 
                                                       // the total sum
		double area = list[index++]->calcArea();// (8) The current element
                                                //     is extracted from the
                                                //     array, the index is
                                                //     incremented by 1, and 
                                                //     the are of the element
                                                //     is saved into variable
                                                //     area
		sum_area += area;
	}
	cout << "\nThe total area is "
			<< sum_area << " units^2" << endl;	// (9) The contents of the 
                                                //     variable area are 
                                                //     printed to the stdout
    cout << "\nThe total perimeter is " 
        << sum_perimeter << " units" << endl; // print total perimeter
	return 0;
}
