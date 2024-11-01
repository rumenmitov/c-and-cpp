/* 
   CH-230-A 
   a7_p5.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

int sortAsc(const void* e1, const void* e2);
int sortDes(const void* e1, const void* e2);

int main(void) {

    // get user input
    char buf[255];

    int n;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%i", &n);

    int* arr = (int*) malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; ++i) {
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%i", &arr[i]);
    }

    char command;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &command);

    while (command != 'e') {
        // run desired algorithm and print results
        if (command == 'a') qsort(arr, n, sizeof(int), (*sortAsc));
        else qsort(arr, n, sizeof(int), (*sortDes));

        for (int i = 0; i < n; ++i) {
            printf("%i ", arr[i]);
        }

        printf("\n");

        // get new command
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%c", &command);
    }

    // free memory
    free(arr);
    arr = NULL;

    return 0;
}

int sortAsc(const void* e1, const void* e2) {
    // cast to int pointers and check if first element > second element
    int* el1 = (int*) e1;
    int* el2 = (int*) e2;
    return *el1 - *el2;
}

int sortDes(const void* e1, const void* e2) {
    // cast to int pointers and check if second element > first element
    int* el1 = (int*) e1;
    int* el2 = (int*) e2;
    return *el2 - *el1;
}
