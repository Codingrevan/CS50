#include <stdio.h>
#include <stdlib.h>

int suma_i (int *tab, int len);
void proc_1(int col, int (*tab)[col], int row);
void proc_2(int col, int (*tab)[col], int row);
void swap(int* a, int* b);
void quicksort(int* A, int low, int high);
int partition(int* A, int low, int high);

int main(void){
    int tab_A[3][6] = {{1, -4, 1, 2, 11},
                       {12, 2, 32, 2},
                       {72, 2, -32, 2}};
    int tab_B[4][3] = {{1, -24, 1},
                       {9, 32, 2},
                       {5, 64, 1},
                       {3, 32, 1}};
    proc_1(6, tab_A, 3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++)
            printf("tab_A[%d][%d] = %d ", i, j, tab_A[i][j]);
        printf("\n");
    }
    proc_2(4, tab_B, 3);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++)
            printf("tab_B[%d][%d] = %d ", i, j, tab_B[i][j]);
        printf("\n");
    }
    return 0;
}

void proc_1(int col, int (*tab)[col], int row){
    int *ptr = NULL;
    for(register int i = 0; i < row; i++){
        ptr = tab[i];
        quicksort(ptr, 0, col - 1);
    }
    ptr = NULL;
}

void proc_2(int col, int (*tab)[col], int row){
    int help[row];
    for(int i = 0; i < row; i++)
        help[i] = suma_i(tab[i], col);
    for (int i = 0; i < row - 1; i++){ 
        for (int j = 0; j < row - i - 1; j++){
            if (help[j] > help[j + 1]){
                int temp = help[j];
                help[j] = help[j + 1];
                help[j + 1] = temp;
                for(int k = 0; k < col; k++)
                    swap(tab[j] + k, tab[j + 1] + k);
            }
        }
    }
}

int suma_i (int *tab, int len){
    int ss = 0.0;
    for(int i = 0; i < len; i++)
        ss+= tab[i];
    return ss;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(int* A, int low, int high){
    int pivot = A[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(A[j] < pivot){
            i++;
            swap(A + i, A + j);
        }
    }
    swap(A + i + 1, A + high);
    return i + 1;
}
 
void quicksort(int* A, int low, int high){
    if(low < high){
        int pi = partition(A, low, high);
        quicksort(A, low , pi - 1);
        quicksort(A, pi + 1, high);
    }
}
