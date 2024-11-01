/* 
   CH-230-A 
   a4_p3.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float geometric_mean(float arr[], int num);
float max(float arr[], int num); 
float least(float arr[], int num);
float sum(float arr[], int num);

int main(void) {

    // user input
    char buf[255];
    float userInput;

    // dynamically allocated array to store inputs
    float* arr = (float*) malloc(sizeof(float)); 

    int i;
    for (i = 0; i < 15; ++i) {
        printf("Please enter float: ");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%f", &userInput);

        if (userInput < 0) break;

        // adding more memory to array
        arr = (float*) realloc(arr, (i + 1) * sizeof(float));
        arr[i] = userInput;
    }

    char userOperation;
    printf("Please enter character: ");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &userOperation);

    switch (userOperation) {
        case 'm':
            // computing geometric mean
            printf("geometric mean is %f\n", geometric_mean(arr, i));
            break;
        case 'h':
            // prints highest number in the array
            printf("highest number is %f\n", max(arr, i));
            break;
        case 'l':
            // prints smallest number in the array
            printf("smallest number is %f\n", least(arr, i));
            break;
        case 's':
            // prints the sum of all elements
            printf("sum is %f\n", sum(arr, i));
            break;
        default:
            break;
    }

    free(arr);
    return 0;
}

float geometric_mean(float arr[], int num) {
    // edge case when num = 0
    if (num == 0) return (float) 0;
    float product = 1;
    for (int i = 0; i < num; ++i) {
        product *= arr[i];
    }

    return pow(product, 1.0 / num);
}

float max(float arr[], int num) {
    float result = *arr;

    // loop thru array to find max
    for (int i = 0; i < num; ++i) {
        if (result < arr[i]) result = arr[i];
    }

    return result;
}

float least(float arr[], int num) {
    float result = *arr;

    // loop thru array to find lowest element
    for (int i = 0; i < num; ++i) {
        if (result > arr[i]) result = arr[i];
    }

    return result;
}

float sum(float arr[], int num) {
    float sum = 0;

    // loop through array to and add elements to sum
    for (int i = 0; i < num; ++i) {
        sum += arr[i];
    }

    return sum;
}
