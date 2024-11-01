/* 
   CH-230-A 
   a5_p1.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

void printTriangle(int n, char ch);

int main(void) {

    // get user input
    char buf[255];

    int n = 0;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%i", &n);

    char ch;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%c", &ch);

    // display result
    printTriangle(n, ch);

    return 0;
}

void printTriangle(int n, char ch) {
    // tracks how many symbols per line
    int tracker = n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < tracker; ++j) {
            printf("%c", ch);
        }
        printf("\n");
        // decrease tracker by 1
        --tracker;
    }
}
