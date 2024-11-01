/* 
   CH-230-A 
   a3_p8.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

// funciton prototypes
float sum(float arr[], int len);
float average(float arr[], int len);

int main(void) {

    float arr[10];
    /* 
     * i is also the final length of the array that is why it is declared
     * outside the for loop
     */
    int i;
    for (i = 0; i < 10; ++i) {
        // getting user input, breaking at -99.0
        char buf[255];
        float input;
        printf("Enter number: ");
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%f", &input);

        if (input == -99.0) {
            break;
        } 

        arr[i] = input;
    }

    // printing results
    printf("Sum is %f\n", sum(arr, i));
    printf("Average is %f\n", average(arr,i));
    
    return 0;
}

// function declarations
float sum(float arr[], int len) {
    float sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }

    return sum;
}

float average(float arr[], int len) {
    return sum(arr, len) / len;
}
