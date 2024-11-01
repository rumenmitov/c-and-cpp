/* 
   CH-230-A 
   a3_p4.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int position(char str[], char c) {
    int idx;
    /* Loop until end of string */
    for (idx = 0; str[idx] != c && str[idx] != '\0'; ++idx) {
       /* let the loop run, body is NULL because it does not need to do
        * anything
        */
       NULL; 
    }

    // return index which has a default value of 0
    return idx;
}

int main() {
    char line[80];
    while (1) {
        printf("Enter string:\n");
        fgets(line, sizeof(line), stdin);
        printf("The first occurrence of ’g’ is: %d\n", position(line, 'g'));
    }
}

/*
 * Program prints 0, because the for loop does not do any checks,
 * but rather it returns on the first iteration with the first index i.e. 0
 *
 * Another problem arises when g is the 0-th character because then the
 * function does not return anything
 */
