#include <stdio.h>

void swap(int* a, int* b);
int* find_min_wsk(int* , int);
void sort(int*, int*);

int main(void){
    int n = 50;
    int tab_A[] = {3, 5, 33, 1, 7, 9, 55, 1, 11, 22, 12, 6, 8, 4, 44, 6, 42, 2, 8, 26, 64, 80, 22, 12, 6, 8, 4, 44, 6, 42, 2, 16, 5, 33, 1, 7, 9, 55, 1, 11, 22, 34, 78, 11, 21, 9, 12, 5, 3, 9};
    sort(tab_A, tab_A + n);
    for(int i = 0; i < n; i++)
        printf("tab[%d] = %d\n", i, tab_A[i]);
    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int* find_min_wsk(int* tab_A, int n){
    int* min = tab_A;
    int* p = NULL;
    for(p = tab_A; p < tab_A + n; p++){
        if(*p < *min)
            min = p;
    }
    return min;
}

void sort(int* tab_A, int* end){
    int *min = NULL;
    while(tab_A < end){
        min = find_min_wsk(tab_A, (int)(end - tab_A));
        swap(tab_A, min);
        tab_A++;
    }
}