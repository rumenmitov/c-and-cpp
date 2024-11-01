/* 
   CH-230-A 
   a5_p8.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols);
void destroyMatrix(int** M, int rows);
void printMatrix(int** M, int rows, int cols);
int** getMatrixMultiplication(int** m1, int** m2, int n, int m, int p);

int main(void) {

    // get user input
    char buf[255];

    printf("Enter number of rows for Matrix A: ");
    int n;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    printf("Enter number of columns for Matrix A (same as rows for Matrix B): ");
    int m;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &m);

    printf("Enter number of columns for Matrix B: ");
    int p;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &p);

    // allocate matrices
    int** m1 = (int**) malloc(n * sizeof(int*));
    int** m2 = (int**) malloc(m * sizeof(int*));

    // get rest of data from user
    printf("Enter values for Matrix A:\n");
    m1 = createMatrix(n, m);
    printf("\n");

    printf("Enter values for Matrix B:\n");
    m2 = createMatrix(m, p);
    printf("\n");

    // print matrices A and B
    printf("Matrix A:\n");
    printMatrix(m1, n, m);

    printf("Matrix B:\n");
    printMatrix(m2, m, p);

    // calculate and print final matrix
    int** m3 = (int**) malloc(n * sizeof(int*));
    m3 = getMatrixMultiplication(m1, m2, n, m, p);

    printf("The multiplication result AxB:\n");
    printMatrix(m3, n, p);

    // free memory
    destroyMatrix(m1, n);
    destroyMatrix(m2, m);
    destroyMatrix(m3, n);

    return 0;
}

int** createMatrix(int rows, int cols) {
    // get user input and put it into matrix M
    int** M = (int**) malloc(rows * sizeof(int*));

    char buf[255]; 

    for (int i = 0; i < rows; ++i) {
        int* row = (int*) malloc(cols * sizeof(int));

        for (int j = 0; j < cols; ++j) {
            printf("Enter value for [%d][%d]\n", i, j);
            fgets(buf, sizeof(buf), stdin);
            sscanf(buf, "%d", &row[j]);
        }

        M[i] = row;
    }

    return M;
}

void destroyMatrix(int** M, int rows) {
    // first free arrays inside matrix, M, then free M
    for (int i = 0; i < rows; ++i) {
        free(M[i]);
        M[i] = NULL;
    }

    free(M);
    M = NULL;
}

void printMatrix(int** M, int rows, int cols) {
    // cycle thru each element of the matrix and print it
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int** getMatrixMultiplication(int** m1, int** m2, int n, int m, int p) {
    /* 
     * NOTE: Resulting matrix, ans, will have dimensions of n x p
     * since dimension of matrix A is n x m,
     * and dimension of matrix B is m x p.
     */
    int** ans = (int**) malloc(n * sizeof(int*));

    // cycle thru all rows of matrix, ans
    for (int i = 0; i < n; ++i) {
        int* row = (int*) malloc(p * sizeof(int));

        // cycle thru all columns of matrix, ans
        for (int j = 0; j < p; ++j) {
            /*
             * NOTE: Whenever you start a new element, the first
             * component will be the first element of row A_i multiplied by
             * the first element of column B_j.
             */
            row[j] = m1[i][0] * m2[0][j];

                for (int k = 1; k < m; ++k) {
                    /*
                     * We must then progress horizontally thru A_i
                     * multiply the element with the vertical progression
                     * of B_j. 
                     *
                     * We then add this product to the element of our
                     * resulting matrix, ans.
                     */
                    row[j] += m1[i][k] * m2[k][j];
            }
        }
        // append row to the matrix, ans, and move on to next row
        ans[i] = row;
    }

    return ans;
}
