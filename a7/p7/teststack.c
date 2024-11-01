/* 
   CH-230-A 
   a7_p7.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

#include "stack.h"

int main(void) {

    // create stack
    struct stack myStack = { .count = 0, .array = {} };

    // get user input
    char buf[255];

    char command;

    int isQuit = 0;
    do {
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%c", &command);

        // run desired command
        switch (command) {
            case 's':
                push(&myStack);
                break;
            case 'p':
                pop(&myStack);
                break;
            case 'e':
                empty(&myStack);
                break;
            case 'q':
                isQuit = 1;
                break;
            default:
                break;


        }
    } while (!isQuit);

    printf("Quit\n");

    return 0;
}
