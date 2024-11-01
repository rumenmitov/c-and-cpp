/* 
   CH-230-A 
   a3_p9.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

// function prototype
double sum25(double v[], int n);

int main(void) {

    /*
     * user input, must be done with fgets + sscanf because otherwise 
     * carriage return skips the first iteration of the for loop below
     */
    int n;
    char line_buf[255];
    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%d", &n);

    // declare array and collect n values from user
    double arr[n];
    for (int i = 0; i < n; ++i) {
       char line_buf[255];
       fgets(line_buf, sizeof(line_buf), stdin);
       sscanf(line_buf, "%lf", &arr[i]);
    } 

    // if the array does not have 6 elements, print error value (i.e. -111)
    if (n < 6) {
        printf("One or both positions are invalid\n");
        return -111;
    }

    // if user input is corrrect print the sum
    printf("sum=%lf\n", (double) sum25(arr, n));
    return 0;
}

double sum25(double v[], int n) {
    // sum elements 2 and 5 by accessing them from the array
    return v[2] + v[5];
}
