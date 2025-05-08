#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 10

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

void merge(int* tab, int p, int q, int r);
void merge_sort(int *tab, int p, int r);

int main(void){
    srand(time(NULL));
    int tab[N];
    printf("PRZED:\n");
    for(int i = 0; i < N; i++){
        tab[i] = rand_i(1, N);
        printf("tab[%d] = %d\n", i, tab[i]);
    }
    merge_sort(tab, 0, N - 1);
    printf("\nPO:\n");
    for(int i = 0; i < N; i++){
        printf("tab[%d] = %d\n", i, tab[i]);
    }
    printf("\n");
    return 0;
}

void merge(int* tab, int p, int q, int r){
    int a = q - p + 1;
    int b = r - q;
    int L[a + 1];
    int R[b + 1];
    int i, j;
    for(i = 0; i < a; i++)
        L[i] = tab[p + i];
    for(j = 0; j < b; j++)
        R[j] = tab[q + j + 1];
    L[a] = INT_MAX;
    R[b] = INT_MAX;
    i = j = 0;
    for(int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            tab[k] = L[i];
            i++;
        }
        else{
            tab[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int* tab, int p, int r){
    int q;
    if(p < r){
        q = p + (r - p) / 2;
        merge_sort(tab, p, q);
        merge_sort(tab, q + 1, r);
        merge(tab, p, q, r);
    }
}