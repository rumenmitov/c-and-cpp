/* 
   CH-230-A 
   a6_p4.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

int scalarProd(int* v1, int* v2, int dim);

int main(void) {

    // get user input
    char buf[255];

    int dim;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%i", &dim);

    int* v1 = (int*) malloc(dim * sizeof(int));
    if (v1 == NULL) {
        printf("Memory allocation failed!"); 
        exit(1);
    }

    int* v2 = (int*) malloc(dim * sizeof(int));
    if (v2 == NULL) {
        printf("Memory allocation failed!"); 
        exit(1);
    }

    // get vector elements
    for (int i = 0; i < dim; ++i) {
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &v1[i]);
    }

    for (int i = 0; i < dim; ++i) {
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d", &v2[i]);
    }

    
    // print results
    printf("The scalar product is: %d\n", scalarProd(v1, v2, dim));

    // clean up
    free(v1);
    v1 = NULL;
    free(v2);
    v2 = NULL;

    return 0;
}

int scalarProd(int* v1, int* v2, int dim) {
    int ans = 0;

    #ifdef DEBUG
        printf("The intermediate product values are:\n");
    #endif

    for (int i = 0; i < dim; ++i) {
        int intermediate_value = v1[i] * v2[i];

        #ifdef DEBUG
            printf("%d\n", intermediate_value);
        #endif

        ans += intermediate_value;
    }

    return ans;
}
