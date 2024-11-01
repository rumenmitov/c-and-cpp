/* 
   CH-230-A 
   a11_p1.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

#include "Box.h"

int main(void) {

    // get user input
    int n = 0;

    std::cout << "Enter size of array: ";
    std::cin >> n;
    std::cout << std::endl;

    Box* box_arr = new Box[2*n];

    for (int i = 0; i < n; ++i) {
        double height = 0, width = 0, depth = 0;
        std::cout << "Box #" << i <<":\n";
        std::cout << "Height: ";
        std::cin >> height;
        std::cout << "Width: ";
        std::cin >> width;
        std::cout << "Depth: ";
        std::cin >> depth;
        box_arr[i] = Box(height, width, depth);
        std::cout << std::endl;
    }

    for (int i = n; i < 2*n; ++i) {
        std::cout << "Copying box #" << i - n << "...\n";
        box_arr[i] = Box(box_arr[i - n]);
    }
    std::cout << std::endl;

    for (int i = 0; i < 2*n; ++i) {
        std::cout << "Volume of box #" << i << " is "
            << box_arr[i].getHeight() * box_arr[i].getWidth() 
            * box_arr[i].getDepth() << " units^3\n";
    }

    // free memory
    delete [] box_arr;

    return 0;
}

