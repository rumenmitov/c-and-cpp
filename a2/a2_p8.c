/* 
   CH-230-A 
   a2_p8.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main(void) {

    // take in user input
    int input;
    scanf("%d", &input);

    // using mod operator to check if 2 and 7 are factors
    if (input % 2 == 0 && input % 7 == 0) {
        printf("The number is divisible by 2 and 7\n");
    } else {
        printf("The number is NOT divisible by 2 and 7\n");
    }
    return 0;
}
