/* 
   CH-230-A 
   a6_p1.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

// create swp var with wanted type; then swap numbers
#define SWAP(n1, n2, type) { \
    type swp = n1; \
    n1 = n2; \
    n2 = swp; \
}

int main(void) {

    // get input from user
    char buf[255];

    int num1;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%i", &num1);

    int num2;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%i", &num2);


    double double1;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%lf", &double1);

    double double2;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%lf", &double2);

    SWAP(num1, num2, int);
    SWAP(double1, double2, double);

    printf("After swapping:\n");
    printf("%d\n%d\n", num1, num2);
    printf("%.6lf\n%.6lf\n", double1, double2);
    return 0;
}
