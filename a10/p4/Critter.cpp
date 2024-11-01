/* 
   CH-230-A 
   a10_p4.cpp
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
    this->hunger = 0;
    this->boredom = 0;

    cout << "Hello from Case 1 Constructor 👋\n";
}

Critter::Critter(const std::string& newname) : name(newname) {
    // Critter with set name only
    this->height = HEIGHT;
    this->hunger = 0;
    this->boredom = 0;

    cout << "Hello from Case 2 Constructor 👋\n";
}

Critter::Critter(const std::string& newname, int hunger, 
        int boredom, double height) : name(newname) {
    
    // Critter with set properties (height is optional)
    this->height = height;
    this->hunger = hunger;
    this->boredom = boredom;

    cout << "Hello from Case 3 Constructor 👋 (using height of " 
        << this->height << ")\n";
}

void Critter::setName(const string& newname) {
	this->name = newname;
}

void Critter::setHunger(int newhunger) {
	this->hunger = newhunger;
}

void Critter::setBoredom(int newboredom) {
    this->boredom = newboredom;
}

void Critter::setHeight(double newheight) {
    this->height = newheight;
}

void Critter::print() {
	cout << "I am " << this->name << ".\nMy hunger level is " << this->hunger 
        << ".\nMy boredom level is " << this->boredom << ".\nI am " 
        << this->height << " metres tall." << endl;
}

const string& Critter::getName() {
    return this->name;
}

int Critter::getHunger() {
	return this->hunger;
}

int Critter::getBoredom() {
    return this->boredom;
}

double Critter::getHeight() {
    return this->height;
}
