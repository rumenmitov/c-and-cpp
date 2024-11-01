/* 
   CH-230-A 
   a8_p5.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // open files
    FILE* f_input = fopen("./chars.txt", "r");
    if (!f_input) {
        fprintf(stderr, "Could not open input file!\n");
        exit(1);
    }

    FILE* f_output = fopen("./codesum.txt", "w");
    if (!f_output) {
        fprintf(stderr, "Could not open output file!\n");
        exit(1);
    }

    // get inputs and print result to file
    char ch1 = fgetc(f_input);
    char ch2 = fgetc(f_input);

    /* NOTE
     * I did not know whether special characters (like '\n') were desired.
     * As special characters have ASCII codes
     * I assumed that they were desired. 
     */

    fprintf(f_output, "%d", ch1 + ch2);

    // close files
    fclose(f_input);
    fclose(f_output);

    return 0;
}
