/* 
   CH-230-A 
   a10_p5.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include "Critter.h"

using namespace std;

Critter::Critter() {
    // default Critter
    this->name = "default_critter";
    this->height = HEIGHT;
    this->hunger = convert(0);
    this->boredom = 0;

    cout << "Hello from Case 1 Constructor 👋\n";
}

Critter::Critter(const std::string& newname) : name(newname) {
    // Critter with set name only
    this->height = HEIGHT;
    this->hunger = convert(0);
    this->boredom = 0;

    cout << "Hello from Case 2 Constructor 👋\n";
}

Critter::Critter(const std::string& newname, int hunger, 
        int boredom, double height) : name(newname) {
    
    // Critter with set properties (height is optional)
    this->height = height;
    this->hunger = convert(hunger);
    this->boredom = boredom;

    cout << "Hello from Case 3 Constructor 👋 (using height of " 
        << this->height << ")\n";
}

void Critter::setName(const string& newname) {
	this->name = newname;
}

void Critter::setHunger(int newhunger) {
	this->hunger = convert(newhunger);
}

void Critter::setBoredom(int newboredom) {
    this->boredom = newboredom;
}

void Critter::setHeight(double newheight) {
    this->height = newheight;
}

void Critter::print() {
	cout << "I am " << this->name << ".\nMy hunger level is " 
        << convert(this->hunger) << ".\nMy boredom level is " 
        << this->boredom << ".\nI am " 
        << this->height << " metres tall." << endl;
}

const string& Critter::getName() {
    return this->name;
}

int Critter::getHunger() {
	return this->convert(hunger);
}

int Critter::getBoredom() {
    return this->boredom;
}

double Critter::getHeight() {
    return this->height;
}

// using mapping scheme as stated in the question
double Critter::convert(int hunger) {
    double ans = 0.0;
    switch (hunger) {
        case 10:
            ans = 1.0;
            break;

        case 9:
            ans = 0.9;
            break;

        case 8:
            ans = 0.8;
            break;

        case 7:
            ans = 0.7;
            break;

        case 6:
            ans = 0.6;
            break;

        case 5:
            ans = 0.5;
            break;

        case 4:
            ans = 0.4;
            break;

        case 3:
            ans = 0.3;
            break;

        case 2:
            ans = 0.2;
            break;

        case 1:
            ans = 0.1;
            break;

        case 0: 
            ans = 0.0;
            break;

        default:
            break;
    }

    return ans;
}

int Critter::convert(double hunger) {
    int ans = 0;

    // swittch statement requires an int 😡
    switch (int (hunger * 10)) {
        case 10:
            ans = 10;
            break;

        case 9:
            ans = 9;
            break;

        case 8:
            ans = 8;
            break;

        case 7:
            ans = 7;
            break;

        case 6:
            ans = 6;
            break;

        case 5:
            ans = 5;
            break;

        case 4:
            ans = 4;
            break;

        case 3:
            ans = 3;
            break;

        case 2:
            ans = 2;
            break;

        case 1:
            ans = 1;
            break;

        case 0: 
            ans = 0;
            break;

        default:
            break;
    }

    return ans;
}
