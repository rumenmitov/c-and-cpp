/* 
   CH-230-A 
   a2_p2.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main(void) {

    char letter;

    // reading from stdin
    scanf("%c", &letter);

    // printing to stdout
    printf("character=%c\n", letter);
    printf("decimal=%i\n", letter);
    printf("octal=%o\n", letter);
    printf("hexadecimal=%x\n", letter);
    return 0;
}
