#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 5

void swap(int (*abc)[COL]);
void transp(int (*tab)[COL], int row, int col);
void przekatne(int (*tab)[COL], int row, int col);

int main(void){
    int abc[ROW][COL];
    int (*ptr)[COL];
    for(ptr = abc; ptr < abc + ROW; ptr++){
        for(int i = 0; i < ROW; i++){
            (*ptr)[i] = i;
            printf("TAB[%d][%d] = %d, ", (int)(ptr - abc), i, i);
        }
        printf("\n");
    }
    printf("\n");
    transp(abc, ROW, COL);
    for(ptr = abc; ptr < abc + ROW; ptr++){
        for(int i = 0; i < ROW; i++)
            printf("TAB[%d][%d] = %d, ", (int)(ptr - abc), i, abc[(int)(ptr - abc)][i]);
        printf("\n");
    }
    printf("\n");
    przekatne(abc, ROW, COL);
    return 0;
}

void transp(int (*tab)[COL], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = i + 1; j < col; j++){
            int tmp = *(*tab + i * col + j);
            *(*tab + i * col + j) = *(*tab + j * row + i);
            *(*tab + j * row + i) = tmp;
        }
    }
}

void przekatne(int (*tab)[COL], int row, int col){
    printf("Wartości nad pierwszą przekątną (od lewej):\n");
    for (int i = 0; i < row - 1; i++)
        printf("%d ", *(*tab + i * col + (i + 1)));
    printf("\n");
    printf("Wartości nad drugą przekątną (od lewej):\n");
    for (int i = 0; i < row - 1; i++)
        printf("%d ", *(*tab + i * col + (col - i - 1)));
    printf("\n");
}