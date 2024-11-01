/* 
   CH-230-A 
   a6_p6.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

void printBin(unsigned char ch);

int main(void) {

    // get user input 
    char buf[255];

    unsigned char ch;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &ch);

    // print result
    printf("The decimal representation is: %d\n", ch);
    printBin(ch);

    return 0;
}

void printBin(unsigned char ch) {

    printf("The backwards binary representation is: ");

    // iterate thru 8 digits and print in the right order
    for (int i = 7; i >= 0; --i) {
        int mask = 1 << i;

        if (ch & mask) {
            printf("1");
        } else {
            printf("0");
        }
    }

    printf("\n");
}
