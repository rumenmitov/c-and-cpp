/* 
   CH-230-A 
   a3_p11.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <string.h>

int main(void) {

    // user unput
    char one[255], two[255];
    fgets(one, sizeof(one), stdin);
    one[strlen(one)-1] = '\0';
    fgets(two, sizeof(two), stdin);
    two[strlen(two)-1] = '\0';

    char ch;
    char line_buf[255];
    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%c", &ch);

    // length of strings
    printf("length1=%i\n", (int) strlen(one));
    printf("length2=%i\n", (int) strlen(two));
    
    // concatenation
    char concat_str[255];
    // copying string one, so that I can use it for the string comparison later
    strcpy(concat_str, one);
    strcat(concat_str, two);
    printf("concatenation=%s\n", concat_str);

    // copying string
    char copy[255];
    strcpy(copy, two);
    printf("copy=%s\n", copy);
    
    // comparing strings
    if (strcmp(one, two) < 0) {
        printf("one is smaller than two\n");
    } else if (strcmp(one, two) > 0) {
        printf("one is larger than two\n");
    } else {
        printf("one is equal to two\n");
    }

    /* 
     * finding the position of the character,
     * if it exists we want to subtract the start of the string
     * in order to get the position. We do this because elements in an
     * array are located one after another, so we can perform pointer 
     * arithmetic to find the distance between the start of the string and 
     * the position of the character
     */
    char* pos_of_char = strchr(two, ch);
    if (pos_of_char) {
        printf("position=%ld\n", pos_of_char - two);
    } else {
        printf("The character is not in the string\n");
    }

    return 0;
}
