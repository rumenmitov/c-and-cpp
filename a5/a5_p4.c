/* 
   CH-230-A 
   a5_p4.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

void divby5(float arr[], int size);

int main(void) {

    // get user input
    char buf[255];

    int n;
    printf("How many elements should the array have? ");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    // allocate array
    float* arr = (float*) malloc(n * sizeof(float));

    for (int i = 0; i < n; ++i) {
        printf("Enter float: ");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%f", &arr[i]);
    }

    // print before function
    printf("Before:\n");
    for (int i = 0; i < n; ++i) {
        printf("%.3f ", arr[i]);
    }
    printf("\n");

    // call function
    divby5(arr, n);

    // print after function
    printf("After:\n");
    for (int i = 0; i < n; ++i) {
        printf("%.3f ", arr[i]);
    }
    printf("\n");

    // free memory
    free(arr);
    arr = NULL;

    return 0;
}

void divby5(float arr[], int size) {
    // pointer arithmetic to loop thru array
    const float* finalArr = arr + size;
    while (arr < finalArr) {
        // change the variable stored at i-th position
        *arr /= 5;
        ++arr;
    }
}
