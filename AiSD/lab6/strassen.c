#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]);
void add(int n, int A[n][n], int B[n][n], int C[n][n]);
void subtract(int n, int A[n][n], int B[n][n], int C[n][n]);

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
    strassen(n, A, B, result);
    printf("Mnożenie macierzy metodą Stassena:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
    return 0;
}

void add(int n, int A[n][n], int B[n][n], int C[n][n]){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[n][n], int B[n][n], int C[n][n]){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]){
    if(n == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int half = n/2;
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];
    int P1[half][half], P2[half][half], P3[half][half], P4[half][half],
        P5[half][half], P6[half][half], P7[half][half];
    int temp1[half][half], temp2[half][half];
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    for(int i=0; i<half; i++){
        for(int j=0; j<half; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+half];
            A21[i][j] = A[i+half][j];
            A22[i][j] = A[i+half][j+half];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+half];
            B21[i][j] = B[i+half][j];
            B22[i][j] = B[i+half][j+half];
        }
    }
    subtract(half, B12, B22, temp1);
    strassen(half, A11, temp1, P1);
    add(half, A11, A12, temp1);
    strassen(half, temp1, B22, P2);
    add(half, A21, A22, temp1);
    strassen(half, temp1, B11, P3);
    subtract(half, B21, B11, temp1);
    strassen(half, A22, temp1, P4);
    add(half, A11, A22, temp1);
    add(half, B11, B22, temp2);
    strassen(half, temp1, temp2, P5);
    subtract(half, A12, A22, temp1);
    add(half, B21, B22, temp2);
    strassen(half, temp1, temp2, P6);
    subtract(half, A11, A21, temp1);
    add(half, B11, B12, temp2);
    strassen(half, temp1, temp2, P7);
    add(half, P5, P4, temp1);
    subtract(half, temp1, P2, temp2);
    add(half, temp2, P6, C11);
    add(half, P1, P2, C12);
    add(half, P3, P4, C21);
    add(half, P5, P1, temp1);
    subtract(half, temp1, P3, temp2);
    subtract(half, temp2, P7, C22); 
    for(int i = 0; i < half; i++){
        for(int j = 0; j < half; j++){
            C[i][j] = C11[i][j];
            C[i][j+half] = C12[i][j];
            C[i+half][j] = C21[i][j];
            C[i+half][j+half] = C22[i][j];
        }
    }
}