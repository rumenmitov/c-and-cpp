/* 
   CH-230-A 
   a7_p7.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#ifndef STACK_H
#define STACK_H
#define CONTAINER_SIZE 12

struct stack {
    unsigned int count;
    int array[CONTAINER_SIZE];
};

void push(struct stack* myStack);
void pop(struct stack* myStack);
void empty(struct stack* myStack);
int isEmpty(struct stack* myStack);
#endif
