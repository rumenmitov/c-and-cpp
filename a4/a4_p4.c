/* 
   CH-230-A 
   a4_p4.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

/*
 * declaring vowels and unwanted characters list which the user string
 * will be compared to later 
 */
#include <stdio.h>
#include <ctype.h>

int count_consonants(char str[]);

const int ConsonantsNum = 21;
const char Consonants[21] = { 
    'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p',
    'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'
};

int main(void) {

    // get user input
    while (1) {
        char input[100];
        fgets(input, sizeof(input), stdin);

        if (*input == '\n') break;

        // print result
        printf("Number of consonants=%d\n", count_consonants(input));
    }
    return 0;
}

int count_consonants(char str[]) {
    int result = 0;

    // check if end-of-string
    while (*str != '\0') {
        for (int i = 0; i < ConsonantsNum; ++i) {
            if (tolower(*str) == Consonants[i]) {
                /*
                 * if character is a consonant, increment result and exit 
                 * for loop
                 */
                result++;
                break;
            }
        }

        // go to next character
        str++;
    }

    return result;
}
