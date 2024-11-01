/* 
   CH-230-A 
   a3_p1.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main(void) {

    float x;
    scanf("%f", &x);

    int n;

    // make sure we get a valid n
    while (!(n > 0)) {
        scanf("%d", &n);
        if (!(n > 0)) {
            printf("Input is invalid, reenter value\n");
        }
    }

    // print x n-times
    for (int i = 0; i < n; ++i) {
        printf("%f\n", x);
    }

    return 0;
}
