/* 
   CH-230-A 
   a3_p5.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

// prototypes of utility functions
double sum(double arr[100], int arr_length);

double toFahrenheit(double num);

double findMean(double arr[100], int arr_length);


int main(void) {

    // handling user input
    char buf[255];

    printf("Enter character: ");
    char c;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &c);

    int n;
    printf("Enter integer: ");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    double temp_arr[n];


    // max array length is 100
    for (int i = 0; i < n; ++i) {

        printf("Enter double: ");
        double num;
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%lf", &num);

        // adding element to array
        temp_arr[i] = num; 
    }
        
    // handling different cases
    switch(c) {
        case 's':
            printf("The sum of all temperatures is %lf °C\n", 
                    sum(temp_arr, n));
            break;
        case 'p':
            for (int i = 0; i < n; ++i) {
                printf("%lf °C\n", temp_arr[i]);
            }
            break;
        case 't':
            for (int i = 0; i < n; ++i) {
                printf("%lf °F\n", toFahrenheit(temp_arr[i]));
            }
            break;
        default:
            printf("The arithmetic mean is %lf °C\n", 
                    findMean(temp_arr, n));
            break;
    }

    return 0;
}

// defining utility functions
double sum(double arr[100], int arr_length) {
    double ans = 0;
    for (int i = 0; i < arr_length; ++i) {
        ans += arr[i];
    }

    return ans;
}

double toFahrenheit(double num) {
    return 9 * num / 5 + 32;
}

double findMean(double arr[100], int arr_length) {
    if (arr_length == 0) {
        return (double) 0;
    } else {
        return sum(arr, arr_length) / arr_length;
    }
}
