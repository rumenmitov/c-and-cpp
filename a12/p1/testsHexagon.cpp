/* 
   CH-230-A 
   a12_p1.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

#include "Shapes.h"

int main(void) {

    // create instances
    Hexagon blue_hex(9, "blue");
    Hexagon green_hex(15, "green");
    Hexagon blue_hex_copy(blue_hex);

    // print results
    std::cout << "Blue Hexagon:\n";
    std::cout << "perimeter=" << blue_hex.perimeter() << " units\n";
    std::cout << "area=" << blue_hex.area() << " units^2\n";
    std::cout << std::endl;

    std::cout << "Green Hexagon:\n";
    std::cout << "perimeter=" << green_hex.perimeter() << " units\n";
    std::cout << "area=" << green_hex.area() << " units^2\n";
    std::cout << std::endl;

    std::cout << "Blue Hexagon Copy:\n";
    std::cout << "perimeter=" << blue_hex_copy.perimeter() << " units\n";
    std::cout << "area=" << blue_hex_copy.area() << " units^2\n";
    std::cout << std::endl;

    return 0;
}
