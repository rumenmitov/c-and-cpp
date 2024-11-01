/* 
   CH-230-A 
   a11_p2.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/


#include <iostream>

using namespace std;

class Creature {
	public:
		Creature();  

        // adding a destructor
        ~Creature();
		void run() const;

	protected:
		int distance;
};

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

class Wizard : public Creature {
	public:
		Wizard();

        // adding a destrucor
        ~Wizard();
		void hover() const;

	private:
		int distFactor;
};

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

// my classes with a constructor, destructor, method and a property
class Archer : public Creature {
    public:
        Archer();
        ~Archer();
        void bowAttack() const;

    private:
        int damage;
};

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

class Dragon : public Creature {
    public: 
        Dragon();
        ~Dragon();
        void fireAttack() const;

    private:
        int healthpoints;
        int damage;
};

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

