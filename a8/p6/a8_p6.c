/* 
   CH-230-A 
   a8_p6.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    // get filenames
    char filename1[255], filename2[255];

    fgets(filename1, sizeof(filename1), stdin);
    filename1[strlen(filename1)-1] = '\0';

    fgets(filename2, sizeof(filename2), stdin);
    filename2[strlen(filename2)-1] = '\0';

    // open files
    FILE* f_input1 = fopen(filename1, "r");
    if (!f_input1) {
        fprintf(stderr, "Could not open input file.\n");
        exit(1);
    }

    FILE* f_input2 = fopen(filename2, "r");
    if (!f_input2) {
        fprintf(stderr, "Could not open input file.\n");
        exit(1);
    }

    FILE* f_res = fopen("results.txt", "w");
    if (!f_input2) {
        fprintf(stderr, "Could not open output file.\n");
        exit(1);
    }

    // get inputs
    double d1, d2;

    char buf[255];

    fgets(buf, sizeof(buf), f_input1);
    sscanf(buf, "%lf", &d1);

    fgets(buf, sizeof(buf), f_input2);
    sscanf(buf, "%lf", &d2);

    // print results in file
    fprintf(f_res, "sum=%lf\n", d1 + d2);
    fprintf(f_res, "difference=%lf\n", d1 - d2);
    fprintf(f_res, "product=%lf\n", d1 * d2);
    fprintf(f_res, "division=%lf\n", d1 / d2);

    // close files
    fclose(f_input1);
    fclose(f_input2);
    fclose(f_res);

    return 0;
}
