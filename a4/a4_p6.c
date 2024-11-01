/* 
   CH-230-A 
   a4_p6.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

int* findMax_1_and_2(int* arr, int len);

int main(void) {

    // get user input
    char buf[255];

    int n;
    printf("Enter amount of elements: ");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    // allocate array for inputs
    int* arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        printf("Enter integer: ");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &arr[i]);
    }

    // get and print result
    int* result = (int*) malloc(2 * sizeof(int));
    result = findMax_1_and_2(arr, n);

    printf("Greatest element in the array is %d\n", result[0]);
    printf("Second greatest is %d\n", result[1]);

    // free memory
    free(arr);
    free(result);

    return 0;
}

int* findMax_1_and_2(int* arr, int len) {
    int* result = (int*) malloc(2 * sizeof(int));

    // assign starting highest values
    if (*arr > *(arr + 1)) {
        result[0] = *arr;
        result[1] = *(arr + 1);
    } else {
        result[1] = *arr;
        result[0] = *(arr + 1);
    }

    /*
     * iterate through array, the greatest element should be result[0], 
     * second greatest should be result[1]
     */
    for (int i = 2; i < len; ++i) {
        if (arr[i] > result[0]) {
            result[1] = result[0];
            result[0] = arr[i];
            continue;
        }

        if (arr[i] > result[1]) result[1] = arr[i];
    }

    return result;
}
