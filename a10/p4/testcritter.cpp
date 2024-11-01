/* 
   CH-230-A 
   a10_p4.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv) {
    // initialize instances of Critter

	Critter c1;
    Critter c2("Critter #2");
    Critter c3a("Critter #3_a", HUNGER, 5, 12);
    Critter c3b("Critter #3_b", HUNGER, 5);

    // set hunger to 2
    c1.setHunger(HUNGER);
    c2.setHunger(HUNGER);
    // print results
    cout << endl << "Critter #1:" << endl;
    c1.print();

    cout << endl << "Critter #2" << endl;
    c2.print();

    cout << endl << "Critter #3 a" << endl;
    c3a.print();

    cout << endl << "Critter #3 b" << endl;
    c3b.print();

    return 0;
}
