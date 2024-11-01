/* 
   CH-230-A 
   linked_list.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/


#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


struct List* append(struct List* myList) {

    // get user input
    char buf[255];
    int num;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &num);

    // create new element
    struct List* newEl = (struct List*) malloc(sizeof(struct List));
    if (newEl == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newEl->value = num;
    newEl->next = NULL;

    // if linked list doesn't exist return node
    if (!myList) return newEl;

    // cycle thru entire list and append newEl
    struct List* ptr = myList;

    while (ptr->next) {
        ptr = ptr->next;
    }

    ptr->next = newEl;

    return myList;
}

struct List* prepend(struct List* myList) {

    // get user input
    char buf[255];
    int num;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &num);

    // create new element
    struct List* newEl = (struct List*) malloc(sizeof(struct List*));
    if (newEl == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // prepend new element
    newEl->value = num;
    newEl->next = myList;

    return newEl;

}

struct List* removeEl(struct List* myList) {
    // handle edge case
    if (!myList) return myList;

    // instantiate a marker for deletion
    struct List* marked = myList;

    myList = myList->next;

    // free marker
    free(marked);
    marked = NULL;

    return myList;
}

void printList(struct List* myList) {
    
    // cycle thru each node and print value
    while (myList) {
        printf("%d ", myList->value);
        myList = myList->next;
    }

    printf("\n");
}

void destroyList(struct List* myList) {
    // cycle thru list and free each node
    struct List* ptr = myList;

    while (ptr) {
        struct List* next_ptr = ptr->next;
        free(ptr);
        ptr = next_ptr;
    }

    ptr = NULL;
}

