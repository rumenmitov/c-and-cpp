/* 
   CH-230-A 
   a5_p5.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double result;
    int position;
} ResultAndPosition;

double getScalar(double* v1, double* v2, int n);
ResultAndPosition getSmallest(double *v, int n);
ResultAndPosition getLargest(double *v, int n);

int main(void) {

    // get user input
    char buf[255];

    int n;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);

    // allocate vectors
    double* vec1 = (double*) malloc(sizeof(double) * n);
    double* vec2 = (double*) malloc(sizeof(double) * n);

    // assign doubles to vectors
    for (int i = 0; i < n; ++i) {
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%lf", &vec1[i]);
    }

    for (int i = 0; i < n; ++i) {
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%lf", &vec2[i]);
    }

    // call and store functions
    ResultAndPosition vec1_small = getSmallest(vec1, n);
    ResultAndPosition vec1_large = getLargest(vec1, n);
    ResultAndPosition vec2_small = getSmallest(vec2, n);
    ResultAndPosition vec2_large = getLargest(vec2, n);

    // print results
    printf("Scalar product=%lf\n", getScalar(vec1, vec2, n));

    printf("The smallest = %lf\n", vec1_small.result);
    printf("Position of smallest = %d\n", vec1_small.position);

    printf("The largest = %lf\n", vec1_large.result);
    printf("Position of largest = %d\n", vec1_large.position);

    printf("The smallest = %lf\n", vec2_small.result);
    printf("Position of smallest = %d\n", vec2_small.position);

    printf("The largest = %lf\n", vec2_large.result);
    printf("Position of largest = %d\n", vec2_large.position);

    // free memory
    free(vec1);
    vec1 = NULL;
    free(vec2);
    vec2 = NULL;

    return 0;
}

double getScalar(double* v1, double* v2, int n) {
    // calculate sum of v_1_i * v_2_j
    double result = (*v1) * (*v2);

    for (int i = 1; i < n; ++i) {
        result += (v1[i] * v2[i]);
    }

    return result;
}

ResultAndPosition getSmallest(double *v, int n) {
    // find smallest and remember position
    ResultAndPosition ans;

    ans.result = *v;
    ans.position = 0;

    for (int i = 1; i < n; ++i) {
        if (v[i] < ans.result) {
            ans.result = v[i];
            ans.position = i;
        }
    }

    return ans;
}

ResultAndPosition getLargest(double *v, int n) {
    // find largest and remember position
    ResultAndPosition ans;

    ans.result = *v;
    ans.position = 0;

    for (int i = 1; i < n; ++i) {
        if (v[i] > ans.result) {
            ans.result = v[i];
            ans.position = i;
        }
    }

    return ans;
}
