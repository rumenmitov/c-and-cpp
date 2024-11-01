/* 
   CH-230-A 
   a5_p2.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

void divby5(float arr[], int size);

int main(void) {

    // initialize array
    float arr[6] = {5.5, 6.5, 7.75, 8.0, 9.6, 10.36};

    // print before function
    printf("Before:\n");
    for (int i = 0; i < 6; ++i) {
        printf("%.3f ", arr[i]);
    }
    printf("\n");

    // call function
    divby5(arr, 6);

    // print after function
    printf("After:\n");
    for (int i = 0; i < 6; ++i) {
        printf("%.3f ", arr[i]);
    }
    printf("\n");

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
