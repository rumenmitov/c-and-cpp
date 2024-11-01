/* 
   CH-230-A 
   a9_p3.cpp
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <iostream>

float abs(float num);

int main(void) {

    // get user input
    float num;
    std::cin >> num;

    // print result
    std::cout << "Result: " << abs(num) << std::endl;

    return 0;
}

float abs(float num) {
    /* NOTE:
     * The task asks us to return a negative number if number is less than 0.
     * This however is pointless, hence I will apply the mathematical 
     * definition for absolute value, whereby the return value is always
     * positive.
     */

    if (num < 0) return -1 * num;
    else return num;
}
