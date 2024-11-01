/* 
   CH-230-A 
   a2_p4.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

int main(void) {

    float a, b, h;

    // reading input
    char line_buf[255];

    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%f", &a);
    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%f", &b);
    fgets(line_buf, sizeof(line_buf), stdin);
    sscanf(line_buf, "%f", &h);

    // computing and printing to stdout
    printf("square area=%f\n", a * a);
    printf("rectangle area=%f\n", a * b);
    printf("triangle area=%.6f\n",  (a * h) / 2);
    printf("trapezoid area=%.6f\n", h * (a + b)/ 2);
    return 0;
}
