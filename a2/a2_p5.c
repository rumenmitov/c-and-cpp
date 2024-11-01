/* 
   CH-230-A 
   a2_p5.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/
#include <stdio.h>

int main(void) {

    int a;
    printf("Enter integer: ");
    scanf("%i", &a);
    printf("Your integer is %i\n", a);

    int* ptr_a = &a;
    printf("Address of integer is %p\n", ptr_a);

    // adding 5 to variable 'a' through dereferencing pointer 
    *ptr_a += 5;
    printf("Integer plus 5 equals %i\n", *ptr_a);
    return 0;
}
