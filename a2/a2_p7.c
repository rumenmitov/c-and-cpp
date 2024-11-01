/* 
   CH-230-A 
   a2_p7.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main(void) {

    int i = 8;
    // added scope so that while loop includes i--
    while (i >= 4) {
        printf("i is %d\n", i);
        i--;
    }
    printf("That's it.\n");
    return 0;
}
