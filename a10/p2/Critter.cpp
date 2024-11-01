/* 
   CH-230-A 
   a10_p2.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include "Critter.h"

using namespace std;

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

void Critter::setAge(int newage) {
    this->age = newage;
}

void Critter::setHealth(int newhealth) {
    this->health = newhealth;
}

void Critter::print() {
	cout << "I am " << this->name << ".\nMy hunger level is " << this->hunger 
        << ".\nMy boredom level is " << this->boredom << ".\nI am " 
        << this->height << " metres tall.\nI am " << this->age 
        << " years old.\nI have " << this->health << " health points." << endl;
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

int Critter::getAge() {
	return this->age;
}
int Critter::getHealth() {
	return this->health;
}
