/* 
   CH-230-A 
   a12_p5.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>
#include "fraction.h"

using namespace std;

int main(void) {
    Fraction a, b;

    cout << "First fraction (in the format %d/%d): ";
    cin >> a;
    cout << "Second fraction (in the format %d/%d): ";
    cin >> b;

    Fraction added_fraction = a + b;
    Fraction subtracted_fraction = a - b;
    cout << "Greater fraction " << ((a > b) ? a : b) << endl;;
    cout << "Added result: " << added_fraction << endl;
    cout << "Subtraction result: " << subtracted_fraction << endl;

    return 0;
}
