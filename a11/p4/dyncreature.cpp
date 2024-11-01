/* 
   CH-230-A 
   a11_p4.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

#include "Creature.h"

using namespace std;

int main() { 

    bool isQuit = false;
    while (!isQuit) {

        // get user input
        cout 
            << "Enter creature you want to spawn (wizard, archer or dragon): ";
        string creatureType;

        cin >> creatureType;

        // create creature type and then delete it
        if (creatureType == "wizard") {
            Wizard* w = new Wizard;
            delete w;
        } else if (creatureType == "archer") {
            Archer* a = new Archer;
            delete a;
        } else if (creatureType == "dragon") {
            Dragon* d = new Dragon;
            delete d;
        } else {
            // exit loop
            isQuit = true;
        }

        cout << endl;

    }

    return 0;
} 
