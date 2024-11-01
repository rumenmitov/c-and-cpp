/* 
   CH-230-A 
   a3_p10.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

// function prototypes
float product(float a, float b);
void productbyref(float a, float b, float* p);
void modifybyref(float* a, float* b);

int main(void) {

    // user input
    float a, b;
    char line_buf[255];

    printf("Enter float: ");
    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%f", &a);

    printf("Enter 2nd float: ");
    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%f", &b);

    // product of two floats
    printf("product=%f\n", product(a, b));

    // initializing pointer for one float
    float* p = (float*) malloc(sizeof(float));
    productbyref(a, b, p);
    /*
     * productbyref function does the same thing as the product function but 
     * uses references
     */
    printf("product by ref=%f\n", *p);
    // freeing pointer
    free(p);

    // modifying the values of a and b by their references
    modifybyref(&a, &b);
    printf("After modifying values: a=%f, b=%f\n", a, b);

    return 0;
}

float product(float a, float b) {
    return a * b;
}

void productbyref(float a, float b, float* p) {
    /* 
     * dereferencing pointer, no need for return since we will read from the 
     * pointer address
     */
    *p = a * b;
    return;
}

void modifybyref(float* a, float* b) {
    /* 
     * changing values by dereferencing pointers,
     * no need for return (see above)
     */
    *a += 3;
    *b += 11;
    return;
}
