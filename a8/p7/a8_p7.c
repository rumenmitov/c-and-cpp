/* 
   CH-230-A 
   a8_p7.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // open files
    FILE* f_1 = fopen("text1.txt", "r");
    if (!f_1) {
        fprintf(stderr, "Input file could not be opened.\n");
        exit(1);
    }

    FILE* f_2 = fopen("text2.txt", "r");
    if (!f_2) {
        fprintf(stderr, "Input file could not be opened.\n");
        exit(1);
    }

    FILE* f_res = fopen("merge.txt", "a");
    if (!f_res) {
        fprintf(stderr, "Output file could not be opened.\n");
        exit(1);
    }

    // get input line by line
    char buf1[1024];
    char buf2[1024];

    // print results to file
    int f1_EOF = 0;
    int f2_EOF = 0;
    while (!f1_EOF || !f2_EOF) {

        // if EOF has been reached for a file, focus only on other file

        if (!f1_EOF) {
            if (fgets(buf1, sizeof(buf1), f_1)) fprintf(f_res, "%s", buf1);
            else f1_EOF = 1;
        }

        if (!f2_EOF) {
            if (fgets(buf2, sizeof(buf2), f_2)) fprintf(f_res, "%s", buf2);
            else f2_EOF = 1;
        }
    }

    // close files
    fclose(f_1);
    fclose(f_2);
    fclose(f_res);

    return 0;
}
