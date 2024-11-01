/* 
   CH-230-A 
   a12_p7.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/


#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
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

int getRandSize();

const int num_obj = 25;                          // incrementing to 25

int main() {
    srand(static_cast<int>(time(0)));           // generate seed

	Area *list[num_obj];						// (1) Initializing 
                                                //     a pointer to an array
                                                //     that will hold 25
                                                //     instances of Area
	int index = 0;								// (2) Initializing the index
                                                //     variable to 0
	double sum_area = 0.0;						// (3) Initializing the sum of
                                                //     the area to 0
    double sum_perimeter = 0.0;                 // initializing sum of
                                                // perimeter to 0

    // generate rnadom objects with random colors and random sizes
    const char* const COLORS[4] = {
        "RED", "BLACK", "VIOLET", "BLUE"
    };

#define NUM_OF_TYPES_OF_OBJECTS 4
    for (int i = 0; i < num_obj; ++i) {
        const char* color = COLORS[rand() % 4];
        const int object_type = rand() % NUM_OF_TYPES_OF_OBJECTS;

        if (object_type == 0) {
            list[i] = new Circle(color, getRandSize());
            cout << "\nCreating new cirlce:\n";

        } else if (object_type == 1) {
            // for rings the outer radius should be greater than the inner
            double r1 = getRandSize(), r2 = getRandSize();

            list[i] = new Ring(color, (r1 > r2 ? r1 : r2), (r1 > r2 ? r2 : r1));
            cout << "\nCreating new ring:\n";

        } else if (object_type == 2) {
            list[i] = 
                new Rectangle(color, getRandSize(), getRandSize());

            cout << "\nCreating new rectangle:\n";

        } else {
            list[i] = new Square(color, getRandSize());
            cout << "\nCreating new square:\n";

        }

        double a = list[i]->calcArea(), p = list[i]->calcPerimeter();
        cout << "Area is: " << a << endl;
        cout << "Perimeter is: " << p << endl;
    }

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

    // free memory
    for (int i = 0; i < num_obj; ++i) {
        delete list[i];
    }

	return 0;
}

int getRandSize() {
    return rand() % 96 + 5;
}
