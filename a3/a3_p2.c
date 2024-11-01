/* 
   CH-230-A 
   a3_p2.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main(void) {

    // getting inputs
    printf("Enter lowercase character: ");
    char ch;
    scanf("%c", &ch);

    printf("Enter integer: ");
    int n;
    scanf("%d", &n);

    // loop over previous characters until ch-n
    for (int i = ch; i >= ch - n; --i) {
        printf("%c\n", i);
    }
    return 0;
}
