/* 
   CH-230-A 
   a3_p6.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

// function prototype
float to_pounds(int kg, int g);

int main(void) {

    // get user input
    int kg;
    scanf("%d", &kg);

    int g;
    scanf("%d", &g);

    // print result
    printf("Result of conversion: %f\n", to_pounds(kg, g));
    return 0;
}

// define function
float to_pounds(int kg, int g) {
    float total_kg = kg + (float) g / 1000;
    return total_kg * 2.2;
}
