/* 
   CH-230-A 
   a2_p1.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {

    char line_buf[255];

    // declaring variables
    double double1, double2;
    int num1, num2;
    char letter1, letter2;

    // reading from stdin
    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%lf", &double1);
    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%lf", &double2);

    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%d", &num1);
    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%d", &num2);

    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%c", &letter1);
    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%c", &letter2);

    // computing and printing to stdout
    printf("sum of doubles=%lf\n", double1 + double2);
    printf("difference of doubles=%lf\n", double1 - double2);
    printf("square=%lf\n", double1 * double1);

    printf("sum of integers=%d\n", num1 + num2);
    printf("product of integers=%d\n", num1 * num2);

    printf("sum of chars=%i\n", letter1 + letter2);
    printf("product of chars=%i\n", letter1 * letter2);
    printf("sum of chars=%c\n", letter1 + letter2);
    printf("product of chars=%c\n", letter1 * letter2);

    return 0;
}
