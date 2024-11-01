/* 
   CH-230-A 
   a2_p10.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main(void) {

    // getting valid user input
    int n;
    while (!(n > 0)) {
        printf("Please enter a positive non-zero integer: ");
        scanf("%i", &n);
    }

    // loop over the days n-times
    // loop must instantiate at 1, because we start from 'day 1'
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("1 day = 24 hours\n");
            continue;
        }

        printf("%d days = %d hours\n", i, i * 24);
    }

    return 0;
}
