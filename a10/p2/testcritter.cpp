/* 
   CH-230-A 
   a10_p2.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv) {
	Critter c;

	string name;
	int hunger, boredom;
    double height;

    // new properties
    int age, health;
 
	cout << endl << "Please enter data: " << endl;
	cout << "Name: ";
	// cin >> name; will not work if name contains
	// spaces
	getline(cin, name);
	c.setName(name);
	cout << "Hunger: ";
	cin >> hunger;
	c.setHunger(hunger);
    cout << "Boredom: ";
    cin >> boredom;
    c.setBoredom(boredom);
    cout << "Height (in metres): ";
    cin >> height;
    c.setHeight(height);
    cout << "Age: ";
    cin >> age;
    c.setAge(age);
    cout << "Health: ";
    cin >> health;
    c.setHealth(health);


	cout << "You have created:" << endl;
	c.print();
        return 0;
}
