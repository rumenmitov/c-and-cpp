/* 
   CH-230-A 
   a7_p2.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

// type definitions + function prototypes
struct ListNode {
    char val;
    struct ListNode* next;
    struct ListNode* prev;

};

struct ListNode* prependEl(struct ListNode* headNode);
struct ListNode* removeCh(struct ListNode* headNode);
void printList(struct ListNode* headNode);
void printListReverse(struct ListNode* headNode);
void destroyList(struct ListNode* headNode);

int main(void) {
    
    struct ListNode* list = (struct ListNode*) malloc(sizeof(struct ListNode));
    if (!list) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int isQuit = 0;

    // get user input
    char buf[255];

    do {
        int input;
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &input);

        switch(input) {
            case 1:
                // prepend to list
                list = prependEl(list);
                break;
            case 2:
                // remove all occurences of character
                list = removeCh(list);
                break;
            case 3:
                // print current list
                printList(list);
                break;
            case 4:
                // print elements of list backwards
                printListReverse(list);
                break;
            case 5:
                // free memory and exit
                destroyList(list);
                isQuit = 1;
                break;
            default:
                break;
        }
    } while (!isQuit);

    return 0;
}

struct ListNode* prependEl(struct ListNode* headNode) {
    // get user input
    char buf[255];

    char ch;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &ch);

    // create new node
    struct ListNode* newNode = (struct ListNode*) 
        malloc(sizeof(struct ListNode));

    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    newNode->val = ch;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (headNode) {
        newNode->next = headNode;
        headNode->prev = newNode;
    }

    return newNode;
}

struct ListNode* removeCh(struct ListNode* headNode) {
    // get user input
    char buf[255];

    char ch;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &ch);

    // initialize cursor pointer and loop thru list checking for character
    if (!headNode) return NULL;
    struct ListNode* ptr = headNode;

    while (ptr) {

        struct ListNode* next = ptr->next;

        if (ptr->val == ch) {
            // remove node from list and free memory, then continue iterating
            struct ListNode* marked = ptr;

            // remove element from list and rejoin list
            if (next) next->prev = marked->prev;
            if (marked->prev) marked->prev->next = next;
            // if no previous element, then move the headNode to next element
            else headNode = next;

            // remove element
            free(marked);
            marked = NULL;
        }

        ptr = next;
    }

    return headNode;
}

void printList(struct ListNode* headNode) {
    // print each element
    while (headNode) {
        printf("%c ", headNode->val);
        headNode = headNode->next;
    }
    printf("\n");
}

void printListReverse(struct ListNode* headNode) {
    // set pointer to end of list
    if (headNode) {
        while (headNode->next) {
            headNode = headNode->next;
        }

        while (headNode->prev) {
            headNode = headNode->prev;
            printf("%c ", headNode->val);
        }
    }

    printf("\n");
}

void destroyList(struct ListNode* headNode) {
    // loop thru elements and and free memory
    struct ListNode* ptr = headNode;

    while (ptr) {
    struct ListNode* ptr_next = ptr->next;
        free(ptr);
        ptr = ptr_next;
    }
}
