/* 
   CH-230-A 
   a6_p9.c
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
struct List* insertEl(struct List* myList);
struct List* reverse(struct List* myList);
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
            case 'i':
                // insert element at index
                myList = insertEl(myList);
                break;
            case 'R':
                // reverse list
                myList = reverse(myList);
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

struct List* insertEl(struct List* myList) {
    
    // get user input
    char buf[255];

    int index, num;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &index);

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &num);

    // handle wrong input edge case
    if (index < 0) {
        printf("Invalid position!\n");
        return myList;
    }


    // create new element
    struct List* newEl = (struct List*) malloc(sizeof(struct List));
    if (!newEl) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newEl->value = num;

    // handle 0-th element edge case and uninitialized list edge case
    if (index == 0) {
        if (!myList) {
            return newEl;
        } else {
            newEl->next = myList;
            return newEl;
        }
    } else {
        if (!myList) {
            printf("Invalid position!\n");
            return NULL;
        }
    }

    // create cursor pointer and cycle thru linked list
    struct List* ptr = myList;

    // loop until the element before the desired index
    for (int i = 0; i < index-1; ++i) {
        /*
         * if next element is NULL we have yet to reach 
         * the element before the desired index, print error message
         */
        if (ptr->next == NULL && i < index - 1) {
            printf("Invalid position!\n");
            return myList;
        }

        ptr = ptr->next;
    }

    // add new element
    newEl->next = ptr->next;
    ptr->next = newEl;

    return myList;
}

struct List* reverse(struct List* myList) {
    // initialize pointer for end-node and handle edge case
    struct List* ptr_end = myList;

    if (!ptr_end) return myList;

    // find length of list, and set swp variable to last node's value
    int len = 1;
    int swp = ptr_end->value;
    do {
        ptr_end = ptr_end->next;
        ++len;
    } while (ptr_end->next);

    // swap first and last values
    myList->value = ptr_end->value;
    ptr_end->value = swp;

    // reset end pointer to second element
    ptr_end = myList->next;

    /* 
     * loop in thru all nodes in pairs (tracked by i and j) until 
     * midpoint is reached
     */
    for (int i = 1, j = len-1; i < j; ++i, --j) {
        /*
         * this pointer will keep track of the element in the first half 
         * of the list
         */
        struct List* ptr_start = myList;

        int k = 0;
        while (k < i) {
            ptr_start = ptr_start->next;
            ++k;
        }

        /* set pointer that will keep track of the element in the second half 
         * of the list
         */
        ptr_end = ptr_start;

        while (k < j - i) {
            ptr_end = ptr_end->next;
            ++k;
        }

        swp = ptr_start->value;
        ptr_start->value = ptr_end->value;
        ptr_end->value = swp;

    }

    return myList;
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
