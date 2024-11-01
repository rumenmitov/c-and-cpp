/* 
   CH-230-A 
   a13_p7.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

// class and function definitions
class OwnException : public std::exception {
    public:
        // constructor should accept a string
        OwnException(std::string) { }
        // overriding what() method
        std::string what() { return "OwnException\n"; }
};


void errFunc(int n) {
    // throw a different error based on parameter
    switch (n) {
        case 1:
            throw 'a';
            break;

        case 2:
            throw 12;
            break;

        case 3:
            throw true;
            break;

        default:
            throw OwnException("Default case exception");
    }
}

int main(void) {

    // try-catch block to catch the thrown errors
    try {
        errFunc(1);
    } catch (char c) {
        std::cerr << "Caught in main: " << c << std::endl;
    }

    try {
        errFunc(2);
    } catch (int i) {
        std::cerr << "Caught in main: " << i << std::endl;
    }

    try {
        errFunc(3);
    } catch (bool b) {
        std::cerr << "Caught in main: " << b << std::endl;
    }

    try {
        errFunc(0);
    } catch (OwnException& err) {
        std::cerr << err.what() << std::endl;
    }

    return 0;
}
