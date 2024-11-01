/* 
   CH-230-A 
   a3_p3.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

// function prototype
float convert(int cm);

int main(void) {

    // get input
    int input;
    scanf("%i", &input);

    // print conversion
    printf("Result of conversion: %.6f\n", convert(input));
    return 0;
}

// first cast int to float and then divide by 10e4 to return km
float convert(int cm) {
    return ((float) cm) / 10e4;
}
