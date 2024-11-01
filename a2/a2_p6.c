/* 
   CH-230-A 
   a2_p6.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main(void) {

    double x, y;

    printf("Enter 1st double: ");
    scanf("%lf", &x);

    printf("Enter 2nd double: ");
    scanf("%lf", &y);

    // instantiating pointers
    double* ptr_one = &x;
    double* ptr_two = &x;
    double* ptr_three = &y;

    // ptr_one == ptr_two != ptr_three
    printf("ptr_one=%p\n", ptr_one);
    printf("ptr_two=%p\n", ptr_two);
    printf("ptr_three=%p\n", ptr_three);

    return 0;
}
