/* 
   CH-230-A 
   a4_p2.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <string.h>

int main(void) {

    // user input
    char input[50];
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';

    /* 
     * boolean value to keep track of where to print 
     * the character (left or right)
     */
    int isLeft = 0;
    // looping through user input
    for (size_t i = 0; i < strlen(input); ++i) {
        if (isLeft) {
            printf(" %c\n", input[i]);
        } else {
            printf("%c\n", input[i]);
        }


        // updating boolean value
        isLeft = !isLeft;
    }

    return 0;
}
