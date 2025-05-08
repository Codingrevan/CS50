#include <stdio.h>
#include <stdlib.h>

int main(void){
    double X[4],(*Y)[6], *(*Z)[8], *A, **B;
    A = &X[0];
    A = Y[0];
    A = *Z[0];
    B = (double **)(X + 0);
    B = (double**)Y[0];
    B = Z[0];
    return 0;
}