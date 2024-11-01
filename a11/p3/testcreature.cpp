/* 
   CH-230-A 
   a11_p3.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

#include "Creature.h"

using namespace std;

int main() { 
    // printing results
    cout << "Creating a Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();

    cout << "\nCreating first Archer.\n";
    Archer a;
    a.run();
    a.bowAttack();

    cout << "\nCreating second Archer.\n";
    Archer a2;
    a2.run();
    a2.bowAttack();

    cout << "\nCreating first Dragon.\n";
    Dragon d;
    d.run();
    d.fireAttack();

    cout << "\nCreating second Dragon.\n";
    Dragon d2;
    d2.run();
    d2.fireAttack();

    cout << endl;

    return 0;
} 
