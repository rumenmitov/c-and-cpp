/* 
   CH-230-A 
   a5_p11.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int isPrime(int x, int n);

int main(void) {

    // get input
    char buf[255];

    int x;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &x);

    // print result
    printf("%d is%s prime\n", x, (isPrime(x, x - 1) ? "" : " not"));

    return 0;
}

int isPrime(int x, int n) {
    // define base cases
    if (x == 1) {
        return 0;
    }

    if (x == 2) {
        return 1;
    }

    // check if x is divisible by n-th predecessor
    if (x % n != 0) {
        /*
         * if x is not divisible by n, try with predecessor of n.
         * Worst case, induction goes until n = 1 and we know
         * that any number modulo 1 gives 0
         */
        return isPrime(x, n - 1);
    } else {
        // return 0 if x has a divisor that is not 1
        if (n == 1) return 1;

        return 0;
    }
}
