/* 
   CH-230-A 
   a7_p1.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

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
