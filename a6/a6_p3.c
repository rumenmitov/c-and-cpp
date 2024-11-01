/* 
   CH-230-A 
   a6_p3.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

// using ternary operator determine the MIN and MAX
#define MIN(a, b, c) ((a < b && a < c) ? a : (b < a && b < c) ? b : c)

#define MAX(a, b, c) ((a > b && a > c) ? a : (b > a && b > c) ? b : c)

// apply given formula to get the MID_RANGE
#define MID_RANGE(a, b, c) ((float) (MIN(a, b, c) + MAX(a, b, c)) / 2)

int main(void) {

    // get user input
    char buf[255];

    int a, b, c = 0;

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%i", &a);

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%i", &b);

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%i", &c);

    // print answer
    printf("The mid-range is: %.6f\n", MID_RANGE(a, b, c));

    return 0;
}
