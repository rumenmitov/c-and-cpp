/* 
   CH-230-A 
   a4_p10.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void proddivpowinv(float a, float b, float* prod, float* div, float* pwr,
        float* invb);

int main(void) {
    
    // get user input
    char buf[255];

    float a, b;
    
    printf("Enter float: ");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%f", &a);

    printf("Enter float: ");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%f", &b);

    // apply operations
    float* prod = (float*) malloc(sizeof(float));
    float* div = (float*) malloc(sizeof(float));
    float* pwr = (float*) malloc(sizeof(float));
    float* invb = (float*) malloc(sizeof(float));

    proddivpowinv(a, b, prod, div, pwr, invb);

    // print results
    printf("Product is %f\n", *prod);
    printf("Division is %f\n", *div);
    printf("Exponential is %f\n", *pwr);
    printf("Inverse is %f\n", *invb);

    return 0;
}

void proddivpowinv(float a, float b, float* prod, float* div, float* pwr,
        float* invb) {

    // dereference pointers before assigning values
    *prod = a * b;
    *div = a / b;
    *pwr = pow(a, b);
    *invb = 1 / b;
}
