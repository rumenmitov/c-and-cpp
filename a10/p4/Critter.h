/* 
   CH-230-A 
   a10_p4.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <string> // defines standard C++ string class

#define HEIGHT 5
#define HUNGER 2

/* First C++ class */
class Critter {
private:  // data members are private
	std::string name;
	int hunger;
	int boredom;
	double height;

public: // business logic methods are public
    // constructors
    Critter();
    Critter(const std::string&);
    Critter(const std::string&, int, int, double = 10);
	// setter methods
	void setName(const std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
    void setHeight(double newheight);
	// getter method
    const std::string& getName();
	int getHunger();
    int getBoredom();
    double getHeight();
	// service method
	void print();
};
