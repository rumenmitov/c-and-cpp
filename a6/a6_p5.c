/* 
   CH-230-A 
   a6_p5.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

void reverseBin(unsigned char ch);

#include <stdio.h>

int main(void) {

    // get user input 
    char buf[255];

    unsigned char ch;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &ch);

    // print result
    printf("The decimal representation is: %d\n", ch);
    reverseBin(ch);

    return 0;
}

void reverseBin(unsigned char ch) {

    printf("The backwards binary representation is: ");

    // need to determine how many digits to print
    int size = 0;
    int num = ch;

    do {
        ++size;
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = (num - 1) / 2;
        }
    } while (num != 0);

    // iterate thru all digits starting and print the digit
    for (int i = 0; i < size; ++i) {
        int mask = 1 << i;

        if (ch & mask) {
            printf("1");
        } else {
            printf("0");
        }
    }

    printf("\n");
}
