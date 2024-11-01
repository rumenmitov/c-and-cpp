/* 
   CH-230-A 
   a13_p8.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <exception>
#include <iostream>

// class definitions
class Motor {
    public:
        Motor() { throw "This motor has problems"; }
};

class Car {
    public:
        Car() {
            try {
                Motor motor;
            } catch (char const* err) {
                throw err;
            }

        }
};

class Garage {
    public:
        Garage() {
            try {
                Car car;
            } catch (...) {
                throw "The car in this garage has problems with the motor";
            }
        }
};

int main(void) {

    // initialize garage
    try {
        Garage garage;
    } catch (char const* err) {
        std::cerr << err << std::endl;
    }
    return 0;
}
