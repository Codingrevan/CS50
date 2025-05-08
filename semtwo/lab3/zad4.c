#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

void swap(int *a, int *b);

int main(void){
    srand(time(NULL));
    int n = rand_i(10, 20);
    int tab[n];
    for(int i = 0; i < n; i++){
        tab[i] = rand_i(1,9);
        printf("tab[%d] = %d, ", i, tab[i]);
    }
    printf("\n");
    int i = 0;
    for (int j = 0; j < n; j++){
        if (tab[j] % 2 == 0){
            swap(&tab[i], &tab[j]);
            i++;
        }
    }
    for(int i = 0; i < n; i++)
        printf("tab[%d] = %d, ", i, tab[i]);
    return 0;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}