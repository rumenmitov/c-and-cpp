#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    FILE* fp = fopen("output.txt", "rb");

    char buf[64];

    size_t bytes_read = 0;

    while ((bytes_read = fread(buf, sizeof(char), 1, fp)) > 0) {
        printf("%c", *buf);
    }

    fclose(fp);
    return 0;
}
