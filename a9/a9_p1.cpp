/* 
   CH-230-A 
   a9_p1.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <string>

int main(void) {

    std:: cout << "Enter country of origin: ";

    // get input
    std::string country;
    std::getline(std::cin, country);

    // print out country
    std::cout << "Your country is: " << country << std::endl;

    return 0;
}
