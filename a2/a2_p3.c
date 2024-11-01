/* 
   CH-230-A 
   a2_p3.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main(void) {

    int weeks, days, hours;

    printf("Weeks: ");
    scanf("%i", &weeks);
    printf("Days: ");
    scanf("%i", &days);
    printf("Hours: ");
    scanf("%i", &hours);

    // computing and printing to stdout
    printf("Total number of hours: %i\n", ((weeks * 7) + days) * 24 + hours);
    return 0;
}
