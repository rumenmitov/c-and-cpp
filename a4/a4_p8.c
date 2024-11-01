/* 
   CH-230-A 
   a4_p8.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>

void printMatrix(int matrix[30][30], int n);
void printDiagonal(int matrix[30][30], int n);

int main(void) {

    int matrix[30][30];

    // get input
    char buf[255];

    int n;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    // add inputs to matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fgets(buf, sizeof(buf), stdin);
            sscanf(buf, "%d", &matrix[i][j]);
        }
    }

    // print results
    printMatrix(matrix, n);
    printDiagonal(matrix, n);

    return 0;
}

void printMatrix(int matrix[30][30], int n) {
    printf("The entered matrix is:\n");

    // loop through each cell and print integer
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printDiagonal(int matrix[30][30], int n) {
    printf("Under the secondary diagonal:\n");

    /*
     * i starts at index 1 because main diagonal starts from matrix[0][0],
     * hence we can skip the first row.
     * The column, j, should start from the element after the main diagonal 
     * i.e. j = (n - 1) - i + 1 = n - i
     * j should loop until the end of the row.
     */
    for (int i = 1; i < n; ++i) {
        for (int j = n - i; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");
}
