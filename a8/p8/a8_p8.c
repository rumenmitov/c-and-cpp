/* 
   CH-230-A 
   a8_p8.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    // get filename
    char filename[255];
    fgets(filename, sizeof(filename), stdin);
    filename[strlen(filename)-1] = '\0';

    // open file
    FILE* fp = fopen(filename, "r");

    // separators to check for
#define NUM_SEPARATORS 8
    const char Separators[NUM_SEPARATORS] = {
        ' ',
        ',',
        '?',
        '!',
        '.',
        '\t',
        '\r',
        '\n'
    };

    // count        → word count
    // ch           → current character
    // isWord       → false if the previous character was a separator
    uint count = 0;
    char ch;
    int isWord = 0;

    do {
        ch = fgetc(fp);

        // isSeparator → is the current character a separator
        int isSeparator = 0;
        for (int i = 0; i < NUM_SEPARATORS; ++i) {
            if (ch == Separators[i]) {
                if (isWord) {
                    ++count;
                    isWord = 0;
                }

                isSeparator = 1;
                break;
            }
        }

        if (!isSeparator) isWord = 1;

    } while (ch != EOF);

    // print result
    printf("The file contains %d words.\n", count);

    // close file
    fclose(fp);


    return 0;
}
