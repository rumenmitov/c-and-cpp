/* 
   CH-230-A 
   a5_p3.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_lower(char* str);

int main(void) {

    // get user input
    char buf[50];

    printf("Insert string: ");
    fgets(buf, sizeof(buf), stdin);

    // if string is not empty, call function and print result
    if (*buf != '\n') {
        printf("There are %d lower case letters.\n", count_lower(buf));
    }

    return 0;
}

int count_lower(char* str) {
    int result = 0;

    // loop thru string and compare character to lower case
    while (*str != '\0') {
        if (*str == tolower(*str) && *str != '\n') result++;

        str++;
    }
    
    return result;
}
