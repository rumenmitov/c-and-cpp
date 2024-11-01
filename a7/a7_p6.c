/* 
   CH-230-A 
   a7_p6.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[30];
    int age;
};

void bubblesort(struct person* arr, int n,
        int (*compFunc1)(struct person, struct person),
        int (*compFunc2)(struct person, struct person));

void swap(struct person* e1, struct person* e2);
int sortByName(struct person p1, struct person p2);
int sortByAge(struct person p1, struct person p2);
void printList(struct person* arr, int n);

int main(void) {

    // get user input
    char buf[255];

    int n;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    struct person* arr = (struct person*) malloc(n * sizeof(struct person));
    if (!arr) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // populate array
    for (int i = 0; i < n; ++i) {
        struct person myGuy;

        fgets(myGuy.name, sizeof(myGuy.name), stdin);
        myGuy.name[strlen(myGuy.name)-1] = '\0';

        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &myGuy.age);

        arr[i] = myGuy;
    }

    // sort by name first and then print
    bubblesort(arr, n, (*sortByName), (*sortByAge));
    printList(arr, n);

    // sort by age first and then print
    bubblesort(arr, n, (*sortByAge), (*sortByName));
    printList(arr, n);

    // free memory
    free(arr);
    arr = NULL;

    return 0;
}

void bubblesort(struct person* arr, int n,
        int (*compFunc1)(struct person, struct person),
        int (*compFunc2)(struct person, struct person)) {

    // execute bubblesort algorithm
    if (n == 1) return;

    while (1) {
        int swapped = 0;
        for (int i = 1; i < n; ++i) {
            if (compFunc1(arr[i-1], arr[i]) > 0) {
                swap(&arr[i-1], &arr[i]);
                swapped = 1;
            } else if (compFunc1(arr[i-1], arr[i]) == 0) {
                if (compFunc2(arr[i-1], arr[i]) > 0) {
                    swap(&arr[i-1], &arr[i]);
                    swapped = 1;
                }
            }
        }

        if (!swapped) break;
    }
}

void swap(struct person* e1, struct person* e2) {
    struct person swp = *e1;
    *e1 = *e2;
    *e2 = swp;
}

int sortByName(struct person p1, struct person p2) {
    return strcmp(p1.name, p2.name);
}

int sortByAge(struct person p1, struct person p2) {
    return p1.age - p2.age;
}

void printList(struct person* arr, int n) {
    for (int i = 0; i < n; ++i, ++arr) {
        printf("{%s, %i}; ", arr->name, arr->age);
    }
    printf("\n");
}
