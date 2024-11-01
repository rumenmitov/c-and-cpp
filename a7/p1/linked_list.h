/* 
   CH-230-A 
   linked_list.h
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

/*
 * Linked List
 * -----------
 *  struct List -- self-referencial struct pointing to itself and next node
 *                 in the list
 *
 *  append -- add new element to the end of the list
 *  
 *  prepend -- add new element in the beginning
 *
 *  removeEl -- remove first element
 *
 *  printList -- prints list
 *
 *  destroyList -- frees memory of the list
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct List {
    int value;
    struct List* next;
};

struct List* append(struct List* myList);
struct List* prepend(struct List* myList);
struct List* removeEl(struct List* myList);
void printList(struct List* myList);
void destroyList(struct List* myList);

#endif
