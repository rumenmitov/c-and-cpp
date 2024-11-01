/* 
   CH-230-A 
   a4_p11.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int count_insensitive(char *str, char c);

int main(void) {

    // get user input with max size of 50 chars
    printf("Enter string: ");
    char* string1 = (char*) malloc(50 * sizeof(char));
    fgets(string1, 50, stdin);
    string1[strlen(string1) - 1] = '\0';

    // create string2 with right size
    char* string2 = (char*) malloc(strlen(string1) * sizeof(char));

    // copy and free string1
    strcpy(string2, string1);
    free(string1);

    // print results
    printf("The character 'b' occurs %d times.\n", 
            count_insensitive(string2, 'b'));

    printf("The character 'H' occurs %d times.\n", 
            count_insensitive(string2, 'H'));

    printf("The character '8' occurs %d times.\n", 
            count_insensitive(string2, '8'));

    printf("The character 'u' occurs %d times.\n", 
            count_insensitive(string2, 'u'));

    printf("The character '$' occurs %d times.\n", 
            count_insensitive(string2, '$'));

    // free memory
    free(string2);

    return 0;
}

int count_insensitive(char *str, char c) {
    c = tolower(c);
    int count = 0;
    while (*str != '\0') {
        if (tolower(*str) == c) ++count;

        ++str;
    }

    return count;
}
