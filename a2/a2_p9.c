/* 
   CH-230-A 
   a2_p9.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main(void) {

    char input;
    scanf("%c", &input);

    // using ascii codes check if input is a digit, letter (either
    // uppercase or lowercase). If not it is some other symbol
    if (input >= '0' && input <= '9') {
        printf("%c is a digit\n", input);
    } else if ((input >= 'A' && input <= 'Z') ||
               (input >= 'a' && input <= 'z')) {
        printf("%c is a letter\n", input);
    } else {
        printf("%c is some other symbol\n", input);
    }
    return 0;
}
