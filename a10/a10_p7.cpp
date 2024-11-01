/* 
   CH-230-A 
   a10_p7.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include <cstring>  // standard C string.h header file

using namespace std;

/*
	Naive string: the goal is to illustrate how copy constructors 
	should be handled. See also charbuffer.cpp
*/

class NaiveString {
private:
	char *str;
public:
	NaiveString(const char*);
	NaiveString(const NaiveString&);
	void update(char, char);
	void print();

    // adding method funcByref
    void funcByRef(NaiveString&);

    // adding destructor
    ~NaiveString();
};

NaiveString::NaiveString(const char* t) {
	str = new char[strlen(t) + 1];
	strcpy(str, t);

    cout << "Calling constructor from char array." << endl;
}

/* 
	Copy constructor: creates a new instance of 
	naive string starting from an existing one 
*/


NaiveString::NaiveString(const NaiveString& src) {
	str = new char[strlen(src.str) + 1];
	strcpy(str, src.str);
	// please note that we can access src.str even if it is private
	// as we are inside the NaiveString class
    
    cout << "Calling constructor from NativeString reference." << endl;
}

/* replaces occurrences of oldchar by newchar */
void NaiveString::update(char oldchar, char newchar) {
	unsigned int i;
	for (i = 0; i < strlen(str); i++) 
		if (str[i] == oldchar)
			str[i] = newchar;
}

void NaiveString::print() {
	cout << str << endl;
}

// implementing funcByref as a method as the question states
void NaiveString::funcByRef(NaiveString& s) {
    cout << "funcByRef() being called" << endl;
    s.update('B', 'C');
    s.print();
}

NaiveString::~NaiveString() {
    delete [] str;
}

void funcByVal(NaiveString s) {
	cout << "funcbyval() being called" << endl;
	s.update('B', 'C');
	s.print();
}

int main(int argc, char** argv) {
	NaiveString a("aBcBdB");
    // calling second type of constructor
    NaiveString b(a);
	a.print();
	cout << "About to call funcbyval()" << endl;
	funcByVal(a);
	a.print();
	cout << "About to call funcByRef() method" << endl;
	a.funcByRef(a);
	a.print();
}
