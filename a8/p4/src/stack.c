/* 
   CH-230-A 
   a8_p4.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

#include "stack.h"

void push(struct stack* myStack, int item) {
    // check if stack is full
    if (myStack->count >= CONTAINER_SIZE) {
        printf("Pushing Stack Overflow\n");
        return;
    }

    // push element
    myStack->array[myStack->count] = item;
    myStack->count++;
}

void empty(struct stack* myStack) {
    // check if stack is empty, else empty it
    if (isEmpty(myStack)) {
        printf("0\n");
        return;
    }

    do {
        printf("%d", myStack->array[(myStack->count) - 1]);
        myStack->array[(myStack->count) - 1] = 0;
        myStack->count--;
    } while (myStack->count > 0);

    printf(".\n");
}

int isEmpty(struct stack* myStack) {
    return myStack->count == 0;
}

