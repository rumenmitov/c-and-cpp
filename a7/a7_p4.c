/* 
   CH-230-A 
   a7_p4.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#define FUNC_NUM 3

#include <stdio.h>
#include <ctype.h>
#include <string.h>


// function prototypes
void printUppercase(char* str);
void printLowercase(char* str);
void printFlipped(char* str);

int main(void) {

    // function array with functions indexed based on input criteria
    void (*func_ptr_arr[FUNC_NUM]) (char* str) = {
        printFlipped,
        printLowercase,
        printUppercase
    };

    // get user string
    char str[255];
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    char buf[255];
    int input;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%i", &input);

    // exit if value entered is 4
    while (input != 4) {

        // call the desired function
        func_ptr_arr[FUNC_NUM - input](str);

        // ask for new command
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%i", &input);
    }

    return 0;
}

void printUppercase(char* str) {
    // loop thru all characters and make them uppercase
    for (; *str != '\0'; str++) {
        printf("%c", toupper(*str));
    }
    printf("\n");
}

void printLowercase(char* str) {
    // loop thru all characters and make them lowercase
    for (; *str != '\0'; str++) {
        printf("%c", tolower(*str));
    }
    printf("\n");
}

void printFlipped(char* str) {
    // loop thru all characters and switch lowercase and uppercase
    for (; *str != '\0'; str++) {
        if (*str == tolower(*str)) {
            printf("%c", toupper(*str));
        } else {
            printf("%c", tolower(*str));
        }
    }
    printf("\n");
}
