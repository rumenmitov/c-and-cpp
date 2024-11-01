/* 
   CH-230-A 
   a10_p2.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <string> // defines standard C++ string class

/* First C++ class */
class Critter {
private:  // data members are private
	std::string name;
	int hunger;
	int boredom;
	double height;

    // my properties
    int age;
    int health;

public: // business logic methods are public
	// setter methods
	void setName(const std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
    void setHeight(double newheight);
    void setAge(int newage);
    void setHealth(int newhealth);
	// getter method
    const std::string& getName();
	int getHunger();
    int getBoredom();
    double getHeight();
    int getAge();
    int getHealth();
	// service method
	void print();
};
