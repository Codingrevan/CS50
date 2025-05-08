#include <stdio.h>

void swap(int* a, int* b);
int* find_min_wsk(int* , int );

int main(void){
    int n = 50;
    int tab_A[] = {3, 5, 33, 1, 7, 9, 55, 1, 11, 22, 12, 6, 8, 4, 44, 6, 42, 2, 8, 26, 64, 80, 22, 12, 6, 8, 4, 44, 6, 42, 2, 16, 5, 33, 1, 7, 9, 55, 1, 11, 22, 34, 78, 11, 21, 9, 12, 5, 3, 9};
    int* p = NULL;
    for(int i = 1; i <= n / 10; i++){
        p = tab_A + (i - 1)*10;
        int* min = find_min_wsk(p, 10);
        printf("zakres %d - %d --> ", (i - 1)*10, (i - 1)*10 + 9);
        for(int j = 0; j < 10; j++){
            printf("tab[%d] = %d, ", j + (i - 1) * 10, *(p + j));
        }
        printf("\n");
        printf("element minimalny wartosc = %d, adres = %p, indeks = %d\n", *min, min, (int)(min - tab_A));
    }
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