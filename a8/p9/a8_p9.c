/* 
   CH-230-A 
   a8_p9.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeOutput(FILE* fp, FILE* f_res);

int main(void) {

    // get inputs
    char buf[255];

    int n;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    setvbuf(stdout, NULL, _IOFBF, 2048);

    // open output file
    FILE* f_res = fopen("output.txt", "wb");
    if (!f_res) {
        fprintf(stderr, "Could not open output file.\n");
        exit(1);
    }

    char intro_text[64];
    sprintf(intro_text, 
            "Concating the content of %d files...\nThe result is:\n", n);

    printf("%s", intro_text);
    fwrite(intro_text, sizeof(char), strlen(intro_text), f_res);

    // iterate thru all files and get filenames
    for (int i = 0; i < n; ++i) {

        // get file name and open file
        char fname[255];
        fgets(fname, sizeof(fname), stdin);
        fname[strlen(fname)-1]='\0';

        FILE* fp = fopen(fname, "rb");
        if (!fp) {
            fprintf(stderr, "Could not open input file: %s.\n", fname);
            exit(1);
        }

        writeOutput(fp, f_res);

        fclose(fp);
    }

    const char* closing_text = "The result was written into output.txt\n";
    printf("%s", closing_text);
    fwrite(closing_text, sizeof(char), strlen(closing_text), f_res);


    // close output file
    fclose(f_res);

    return 0;
}

void writeOutput(FILE* fp, FILE* f_res) {
    // get total file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // initialize 64-byte buffer
#define BUF_SIZE 64
    char buffer[BUF_SIZE];

    size_t total_bytes_read = 0; 
    size_t bytes_written = 0;

    // iterate over each byte (= 1 chunk) and read it
    for (int j = 0; j < file_size; ++j) {
        total_bytes_read += 
            fread(&buffer[j % BUF_SIZE], sizeof(char), 1, fp);

        /*
         * since one ASCII char is stored in one byte,
         * and we are reading one chunk (i.e. byte = char) at a time
         * we can just format print the character
         */
        printf("%c", buffer[j % BUF_SIZE]);

        // we want to check if our buffer is full
        if (total_bytes_read % BUF_SIZE == 0) {
            bytes_written += fwrite(buffer, sizeof(char), BUF_SIZE,
                    f_res);
        }
    }
    printf("\n");


    // write the remaining bytes to file
    size_t rem = file_size - bytes_written;
    if (rem != 0) {
        bytes_written += fwrite(buffer, sizeof(char), rem, f_res);
    }

    fwrite("\n", sizeof(char), 1, f_res);

}
