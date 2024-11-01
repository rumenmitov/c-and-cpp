/* 
   CH-230-A 
   a5_p7.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    // get user input
    char str1[100], str2[100];

    fgets(str1, sizeof(str1), stdin);
    str1[strlen(str1) - 1] = '\0';

    fgets(str2, sizeof(str2), stdin);
    str2[strlen(str2) - 1] = '\0';

    // initializing finalStr
    int finalStrSize = strlen(str1) + strlen(str2);
    char* finalStr = (char*) malloc(finalStrSize * sizeof(char));

    // concat finalStr
    strcpy(finalStr, str1);
    strcat(finalStr, str2);

    // print result
    printf("Result of concatenation: %s\n", finalStr);

    // free memory
    free(finalStr);
    finalStr = NULL;

    return 0;
}
