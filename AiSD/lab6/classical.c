#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

void classical_multiply(int n, int A[n][n], int B[n][n], int result[n][n]);

int main() {
    srand(time(NULL));
    int n = N;
    int A[n][n];
    int B[n][n];
    int result[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = rand_i(1, n);
            B[i][j] = rand_i(1, n);
        }
    }
    classical_multiply(n, A, B, result);
    printf("Mnożenie macierzy metodą klasyczną:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
    return 0;
}

void classical_multiply(int n, int A[n][n], int B[n][n], int result[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result[i][j] = 0;
            for(int k=0; k<n; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }
}