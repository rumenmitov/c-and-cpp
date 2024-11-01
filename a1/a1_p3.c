/* 
   CH-230-A 
   a1_p3.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main() {
    float result; /* The result of the division */
    int a = 5;
    float b = 13.5;
    result = a / b;
    printf("The result is %f\n", result);
    return 0;
}

/*
 * Library not declared correctly, missing "#".
 * Comment was declared with the wrong "*" symbol.
 * Variable "b" should be of type "double".
 * Wrong format specifier used in printf function.
*/
