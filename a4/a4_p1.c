/* 
   CH-230-A 
   a4_p1.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <math.h>

int main(void) {

    // user input
    char buf[255];

    float lower_bound;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%f", &lower_bound);

    float upper_bound;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%f", &upper_bound);

    float step;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%f", &step);


    // looping for all step-values between the lower and upper bound
    for(float x = lower_bound; x <= upper_bound; x += step) {
        // printing x, area from x, and circumference from x
        printf("%f %f %f\n", x, x * x * M_PI, 2 * M_PI * x);
    }


    return 0;
}
