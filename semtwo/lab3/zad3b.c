#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 5

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

int main(void){
    srand(time(NULL));
    int TAB[N][M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            TAB[i][j] = rand_i(-10,10);
            printf("TAB[%d][%d] = %d, ", i, j, TAB[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int (*wsk)[M];
    wsk = TAB + 2;
    wsk -= 2;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j+=2)
            wsk[i][j] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            printf("TAB[%d][%d] = %d, ", i, j, TAB[i][j]);
        printf("\n");
    }
    return 0;
}

