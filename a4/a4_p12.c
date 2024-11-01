/* 
   CH-230-A 
   a4_p12.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceAll(char *str, char c, char e);

int main(void) {

    // get user input
    char buf[80];

    while(1) {
        printf("Enter string: ");
        fgets(buf, sizeof(buf), stdin);
        buf[strlen(buf) - 1] = '\0';
        char* string = (char*) malloc(strlen(buf) * sizeof(char));
        strcpy(string, buf);

        if (strcmp(buf, "stop") == 0) return 0;

        char c, e;

        printf("Enter character to be replaced: ");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%c", &c);

        printf("Enter replacing character: ");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%c", &e);

        // print results before replacement
        printf("\nCharacter to be replaced is %c\n", c);
        printf("Replacing character is %c\n", e);
        printf("Original string is %s\n", string);

        // call function
        replaceAll(string, c, e);

        // print final result
        printf("Final string is %s\n\n", string);

        free(string);
    }

    return 0;
}

void replaceAll(char *str, char c, char e) {
    // loop until end of string and replace character
    while (*str != '\0') {
        if (*str == c) {
            *str = e;
        }

        ++str;
    }
}
