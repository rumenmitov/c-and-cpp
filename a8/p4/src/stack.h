/* 
   CH-230-A 
   a8_p4.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef STACK_H
#define STACK_H
// using 16-bit integers
#define CONTAINER_SIZE 16

struct stack {
    unsigned int count;
    int array[CONTAINER_SIZE];
};

void push(struct stack* myStack, int item);
void empty(struct stack* myStack);
int isEmpty(struct stack* myStack);
#endif
