/* 
   CH-230-A 
   a11_p5.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

#include "Shapes.h"

int main(int argc, char** argv) {

  Circle c("first circle", 3, 4, 7);
  RegularPolygon r("TRIANGLE", 1, 1, 3);

  r.printName();
  c.printName();

  // my instances
  Circle circle("my circle", 1, 2, 5);
  Rectangle rectangle("my rectangle", 2.3, 2.1, 5, 6);
  Square square("my square", 3.2, 2.4, 5);

  std::cout << "Perimeter of the circle \"" << circle.getName() 
      << "\" is: " << circle.perimeter() << " units\n";
  std::cout << "Area of the circle \"" << circle.getName() 
      << "\" is: " << circle.area() << " units^2\n";

  std::cout << "Perimeter of the rectangle \"" << rectangle.getName() 
      << "\" is: " << rectangle.perimeter() << " units\n";
  std::cout << "Area of the rectangle \"" << rectangle.getName() 
      << "\" is: " << rectangle.area() << " units^2\n";

  std::cout << "Perimeter of the square \"" << square.getName() 
      << "\" is: " << square.perimeter() << " units\n";
  std::cout << "Area of the square \"" << square.getName() 
      << "\" is: " << square.area() << " units^2\n";
}
