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
    int (*ptr)[M];
    for(ptr = TAB; ptr < TAB + N; ptr++){
        for(int i = 0; i < N; i++){
            (*ptr)[i] = rand_i(-10,10);
            printf("TAB[%d][%d] = %d, ", (int)(ptr - TAB), i, (*ptr)[i]);
        }
        printf("\n");
    }
    printf("\n");
    int (*wsk)[M];
    wsk = TAB + 2;
    wsk -= 2;
    for(; wsk < TAB + N; wsk++)
        for(int i = 0; i < N; i+=2)
            (*wsk)[i] = 0;
    for(ptr = TAB; ptr < TAB + N; ptr++){
        for(int i = 0; i < N; i++)
            printf("TAB[%d][%d] = %d, ", (int)(ptr - TAB), i, TAB[(int)(ptr - TAB)][i]);
        printf("\n");
    }
    return 0;
}

