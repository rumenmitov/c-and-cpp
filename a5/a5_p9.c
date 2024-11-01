/* 
   CH-230-A 
   a5_p9.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

int*** createMatrix(int x, int y, int z);
void printSections(int*** M, int x, int y, int z);
void destroyMatrix(int*** M, int z, int x);

int main(void) {

    // get inputs
    char buf[255];

    // x is rows, y is columns, z is depth
    int x, y, z;

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &x);

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &y);

    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &z);

    // create 3x3 matrix
    int*** M = (int***) malloc(sizeof(int**) * z);
    M = createMatrix(x, y, z);

    // print result
    printSections(M, x, y, z);

    // free memory
    destroyMatrix(M, z, x);

    return 0;
}

int*** createMatrix(int x, int y, int z) {

    // allocate memory for matrix, M
    int*** M = (int***) malloc(sizeof(int**) * z);

    for (int i = 0; i < z; ++i) {
        int** grid = (int**) malloc(sizeof(int*) * x);

        for (int j = 0; j < x; ++j) {
            int* row = (int*) malloc(sizeof(int) * y);

            grid[j] = row;
        }

        M[i] = grid;
    }

    // collect all the elements from user and put them in a list
    int* input_arr = (int*) malloc(x * y * z * sizeof(int));
    for (int c = 0; c < x * y * z; ++c) {
        
        char buf[255];
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &input_arr[c]);
    }

    // now iterate thru the matrix, doing first columns, then rows, then depth
    int c = 0;
    for (int k = 0; k < y; ++k) {
        for (int j = 0; j < x; ++j) {
            for (int i = 0; i < z; ++i) {

                // put elements in matrix from user list
                M[i][j][k] = input_arr[c];
                ++c;
            }
        }
    }

    // deallocate memory of input array
    free(input_arr);
    input_arr = NULL;

    return M;
}

void printSections(int*** M, int x, int y, int z) {

    // iterate thru martix, M, doing first depth, then columns, then rows
    for (int i = 0; i < z; ++i) {
        printf("Section %d:\n", i + 1);

        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < x; ++k) {
                printf("%d ", M[i][k][j]);
            }

            printf("\n");
        }
    }
}

void destroyMatrix(int*** M, int z, int x) {

    // iterate over depth
    for (int i = 0; i < z; ++i) {
        
        // iterate over rows
        for (int j = 0; j < x; ++j) {
            free(M[i][j]);
            M[i][j] = NULL;
        }

        free(M[i]);
        M[i] = NULL;
    }

    free(M);
    M = NULL;
}
