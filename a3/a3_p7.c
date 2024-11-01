/* 
   CH-230-A 
   a3_p7.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

void print_form(int n, int m, char c);

int main(void) {

    int n;
    scanf("%d", &n);

    int m;
    scanf(" %d", &m);

    char c;
    scanf(" %c", &c);

    print_form(n, m, c);

    return 0;
}

void print_form(int n, int m, char c) {
    // the first for loop is for the rows i.e. height of trapezoid
    for (int i = 0; i < n; ++i) {
        /* 
         * second for loop is for the rows, each row should have m + i - 1
         * chars
         */
        for (int j = 0; j < m + i; ++j) {
            printf("%c", c);
        }
        // start new row
        printf("\n");
    }
}
