/* 
   CH-230-A 
   a6_p2.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

// comapare the last bit of num with 1 to determine least significant bit
#define LEAST_SIG_BIT(num) ((num) & 1)

int main(void) {

    // get user input
    char buf[255];

    unsigned char ch;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &ch);

    // print results
    printf("The decimal representation is: %i\n", ch);
    printf("The least significant bit is: %i\n", LEAST_SIG_BIT(ch));
    return 0;
}
