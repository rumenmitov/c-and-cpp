/* 
   CH-230-A 
   a5_p6.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

int count(float* arr, int n);

int main(void) {

    // get user input
    char buf[255];

    printf("Enter size of array: ");
    int n;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    // alloc array
    float* arr = (float*) malloc(n * sizeof(float));

    for (int i = 0; i < n; ++i) {
        printf("Enter float: ");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%f", &arr[i]);
    }

    // print result
    printf("Before the first negative value: %d elements\n", count(arr, n));

    // free array
    free(arr);
    arr = NULL;

    return 0;
}

int count(float* arr, int n) {
    // initialize starting point
    float* ptr = arr;

    // loop thru until negative element and then exit loop
    float* finalElement = arr + n;
    while (arr < finalElement) {
        if (*arr < 0) break;

        ++arr;
    }

    // return difference of where the loop exited and starting point
    return arr - ptr;
}
