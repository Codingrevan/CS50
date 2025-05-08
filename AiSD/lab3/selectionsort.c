#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


void swap(int* a, int* b);
int* find_min_wsk(int* tab_A, int n);
void sort(int* tab, int n);

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

int main(void){
    srand(time(NULL));
    int tab[N];
    printf("PRZED:\n");
    for(int i = 0; i < N; i++){
        tab[i] = rand_i(1, N);
        printf("tab[%d] = %d\n", i, tab[i]);
    }
    sort(tab, N);
    printf("\nPO:\n");
    for(int i = 0; i < N; i++)
        printf("tab[%d] = %d\n", i, tab[i]);
    return 0;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
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

void sort(int* tab, int n){
    int *min = NULL;
    int *tmp = tab;
    while(tmp < tab + n){
        min = find_min_wsk(tmp, (int)(tab + n - tmp));
        swap(tmp, min);
        tmp++;
    }
}