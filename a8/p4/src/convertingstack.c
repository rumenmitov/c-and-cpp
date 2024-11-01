/* 
   CH-230-A 
   a8_p4.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdint.h>
#include <stdio.h>

#include "stack.h"

int main(void) {

    // create stack
    struct stack myStack = { .count = 0, .array = {} };

    // get user input
    char buf[255];

    uint16_t num;

    /*
     * NOTE forever-loop was removed due to the assumption that the 
     * program takes in only one input
     */

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%hi", &num);

    printf("The binary representation of %d is ", num);

    int rem;

    do {
        // get remainder and push it to stack
        rem = num % 2;
        push(&myStack, rem);

        // get next number
        num = (num - rem) / 2;
    } while (num != 0);

    // empty out the bits in reverse order to get the binary sequence
    empty(&myStack);

    return 0;
}
