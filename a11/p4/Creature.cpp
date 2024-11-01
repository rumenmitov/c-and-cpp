/* 
   CH-230-A 
   a11_p4.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/


#include <iostream>

#include "Creature.h"

using namespace std;


Creature::Creature(): distance(10) {
    // announcing that creature was created
    std::cout << "a new creature has entered the fight!\n";
}    

Creature::~Creature() {
    std::cout << "creature was destroyed!\n";
}

void Creature::run() const { 
    cout << "running " << distance << " meters!\n";
}  

Wizard::Wizard() : distFactor(3) {
    // announcing that wizard was created
    std::cout << "a new wizard has entered the fight!\n";
}  

Wizard::~Wizard () {
    std::cout << "wizard was destroyed!\n";
}

void Wizard::hover() const {
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}

Archer::Archer() : damage(2) {
    std::cout << "a new archer has entered the fight!\n";
}

Archer::~Archer() {
    std::cout << "archer was destroyed!\n";
}

void Archer::bowAttack() const { 
    cout << "firing bow at a distance of " << distance 
        << "and dealing " << damage << " damage!\n";
}

Dragon::Dragon() : healthpoints(100), damage(10) {
    std::cout << "a new dragon has entered the fight!\n";
}

Dragon::~Dragon() {
    std::cout << "dragon was destroyed!\n";
}

void Dragon::fireAttack() const {
    cout << "breathing fire, dealing " << damage << " damage over " << distance 
        << " metres, and healing "
        << damage << " HP. Current HP is " << healthpoints << "!\n";
}
