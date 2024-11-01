/* 
   CH-230-A 
   a4_p9.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

int prodminmax(int arr[], int n);

int main(void) {

    // get input
    char buf[255];

    printf("Enter size of array: ");
    int n;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        printf("Enter integer: ");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &arr[i]);
    }

    // print result
    printf("The product is %d", prodminmax(arr, n));

    // free memory
    free(arr);

    return 0;
}

int prodminmax(int arr[], int n) {
    int max, min;

    // handle edge cases
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return arr[0];
    }

    // initialise max and min variables
    if (arr[0] > arr [1]) {
        max = arr[0];
        min = arr[1];
    } else {
        max = arr[1];
        min = arr[0];
    }

    // loop through array
    for (int i = 0; i < n; ++i) {
        // using guard clauses to update max and min
        if (arr[i] > max) {
            max = arr[i];
            continue;
        }

        if (arr[i] < min) {
            min = arr[i];
            continue;
        }
    }

    // return result
    return max * min;
}
