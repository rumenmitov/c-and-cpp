/* 
   CH-230-A 
   a10_p1.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

// commenting out namespace
/* using namespace std; */

int main(int argc, char** argv)
{
	Critter c;

    std::string name;
	int hunger;
 
    std::cout << std::endl << "Please enter data: " << std::endl;
    std::cout << "Name: ";
	// cin >> name; will not work if name contains
	// spaces
	getline(std::cin, name);
	c.setName(name);
    std::cout << "Hunger: ";
    std::cin >> hunger;
	c.setHunger(hunger);

    std::cout << "You have created:" << std::endl;

    // print was removed from critter class
	c.print();
        return 0;
}
