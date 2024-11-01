/* 
   CH-230-A 
   a9_p7.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

using namespace std;

void swapping(int& n1, int& n2); // swap ints
void swapping(float& f1, float& f2); // swap floats
void swapping(const char*& c1, const char*& c2); // swap char pointers


int main(void) {
    int a = 7, b = 15;
    float x = 3.5, y = 9.2;
    const char *str1 = "One";
    const char *str2 = "Two";
    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    swapping(a, b);
    swapping(x, y);
    swapping(str1, str2);
    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;
    return 0;
}

// swapping by reference
void swapping(int& n1, int& n2) {
    int swp = n1;
    n1 = n2;
    n2 = swp;
}

void swapping(float& f1, float& f2) {
    float swp = f1;
    f1 = f2;
    f2 = swp;
}

void swapping(const char*& c1, const char*& c2) {
    const char *swp = c1;
    c1 = c2;
    c2 = swp;
}
