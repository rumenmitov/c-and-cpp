/* 
   CH-230-A 
   a6_p7.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int set3bits(unsigned ch, int bit1, int bit2, int bit3);

int main(void) {

    // get user input
    char buf[255];
    
    unsigned char ch;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &ch);

    int bit1, bit2, bit3;

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &bit1);

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &bit2);

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &bit3);

    // print results
    printf("The decimal representation is: %d\n", ch);
    printf("The binary representation is: %.8b\n", ch);
    printf("After setting the bits: %b\n", set3bits(ch, bit1, bit2, bit3));

    return 0;
}

int set3bits(unsigned ch, int bit1, int bit2, int bit3) {
    // create mask with bits that must be turned on
    int mask = (1 << bit1) + (1 << bit2) + (1 << bit3);

    // return the char with the correct bits set
    return ch |= mask;
}
