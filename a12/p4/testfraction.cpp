/* 
   CH-230-A 
   a12_p4.cpp
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

    cout << "Fraction division: " << a / b << endl;;
    cout << "Fraction multiplication: " << a * b << endl;

    return 0;
}
