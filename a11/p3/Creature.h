/* 
   CH-230-A 
   a11_p3.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef CREATURE_H
#define CREATURE_H

class Creature {
	public:
		Creature();  

        // adding a destructor
        ~Creature();
		void run() const;

	protected:
		int distance;
};

class Wizard : public Creature {
	public:
		Wizard();

        // adding a destrucor
        ~Wizard();
		void hover() const;

	private:
		int distFactor;
};

// my classes with a constructor, destructor, method and a property
class Archer : public Creature {
    public:
        Archer();
        ~Archer();
        void bowAttack() const;

    private:
        int damage;
};

class Dragon : public Creature {
    public: 
        Dragon();
        ~Dragon();
        void fireAttack() const;

    private:
        int healthpoints;
        int damage;
};

#endif
