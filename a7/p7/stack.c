/* 
   CH-230-A 
   a7_p7.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

#include "stack.h"

void push(struct stack* myStack) {
    // check if stack is full
    if (myStack->count >= CONTAINER_SIZE) {
        printf("Pushing Stack Overflow\n");
        return;
    }

    // get element
    char buf[255];
    int el;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%i", &el);

    // push element
    myStack->array[myStack->count] = el;
    myStack->count++;
    printf("Pushing %d\n", el);
}

void pop(struct stack* myStack) {
    // check if stack is empty, else pop element
    if (isEmpty(myStack)) {
        printf("Popping Stack Underflow\n");
        return;
    }

    printf("Popping %d\n", myStack->array[(myStack->count) - 1]);
    myStack->array[(myStack->count) - 1] = 0;
    myStack->count--;
}

void empty(struct stack* myStack) {
    // check if stack is empty, else empty it
    if (isEmpty(myStack)) {
        printf("\n");
        return;
    }

    printf("Emptying Stack ");
    do {
        printf("%d ", myStack->array[(myStack->count) - 1]);
        myStack->array[(myStack->count) - 1] = 0;
        myStack->count--;
    } while (myStack->count > 0);

    printf("\n");
}

int isEmpty(struct stack* myStack) {
    return myStack->count == 0;
}

