/* 
   CH-230-A 
   a6_p8.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

// types and prototypes
struct List {
    int value;
    struct List* next;
};

struct List* append(struct List* myList);
struct List* prepend(struct List* myList);
struct List* removeEl(struct List* myList);
void printList(struct List* myList);
void destroyList(struct List* myList);


int main(void) {

    // declaring list
    struct List* myList = (struct List*) malloc(sizeof(struct List));
    if (myList == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    myList = NULL;

    // get user input
    char buf[255];

    int isQuit = 0;
    while (!isQuit) {
        char input;
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%c", &input);

        switch(input) {
            case 'a':
                // insert end of list
                myList = append(myList);
                break;
            case 'b':
                // insert beginning of list
                myList = prepend(myList);
                break;
            case 'r':
                // remove first element
                myList = removeEl(myList);
                break;
            case 'p':
                // print list
                printList(myList);
                break;
            case 'q':
                isQuit = 1;
                break;
            default:
                break;
        }
    }

    // free memory
    destroyList(myList);

    return 0;
}

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
