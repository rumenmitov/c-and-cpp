/* 
   CH-230-A 
   a5_p10.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

void recursionPrint(int n);

int main(void) {

    // get input
    char buf[255];

    printf("Enter positive integer: ");
    int n;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    // call recursive function
    recursionPrint(n);

    return 0;
}

void recursionPrint(int n) {
    printf("Number is %d\n", n);

    if (n == 1) {
        return;
    } else {
        recursionPrint(n - 1);
    }
}
