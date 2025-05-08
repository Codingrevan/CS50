#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7

int rand_i(int a, int b){
        return (a + rand() % (b - a + 1));
}

void wypisz_i(int *poczatek, int *koniec);
int** find_min_wsk_wsk(int* tab[N], int n);
void swap(int* a, int* b);
void swap_pointer(int** a, int** b);
void swap_all(void *a, void *b, size_t rozmiar);

int main(void){
    srand(time(NULL));
    int n = N;
    int TAB[n];
    int* TAB_P[n];
    for(int i = 0; i < n; i++){
        TAB[i] = rand_i(1, 100);
        TAB_P[i] = TAB + i;
    }
    int** WSK = NULL;
    int** MIN = NULL;
    WSK = MIN = TAB_P;
    printf("TAB --> ");
    wypisz_i(*WSK, *WSK + n);
    printf("\n");
    for(int j = 0; j < n; j++)
        printf("TAB_P[%d] = %p\n", j, *WSK + j);
    MIN = find_min_wsk_wsk(TAB_P, n);
    printf("\nminimum = %d indeks = %d adres = %p\n\n", **MIN, (int)(*MIN - *TAB_P), *MIN);
    swap(*WSK, *MIN);
    printf("TAB --> ");
    wypisz_i(*WSK, *WSK + n);
    printf("\n");
    for(int j = 0; j < n; j++)
        printf("TAB_P[%d] = %p\n", j, *WSK + j);
    MIN = TAB_P + n - 1;
    swap_pointer(WSK, MIN);
    printf("\nTAB przez wskaznik --> ");
    for(int i = 0; i < n; i++)
        printf ("%4d ", *TAB_P[i]);
    printf("\n\n");
    for(int j = 0; j < n; j++)
        printf("TAB_P[%d] = %p\n", j, TAB_P[j]);
    printf("\nTAB przez identyfikator TAB --> ");
    wypisz_i(TAB, TAB + n);
    swap_all((void *)WSK, (void *)MIN, sizeof(int*));
    printf("\nTAB przez wskaznik --> ");
    for(int i = 0; i < n; i++)
        printf ("%4d ", *TAB_P[i]);
    printf("\n\n");
    for(int j = 0; j < n; j++)
        printf("TAB_P[%d] = %p\n", j, TAB_P[j]);
    printf("\nTAB przez identyfikator TAB --> ");
    wypisz_i(TAB, TAB + n);
    return 0;
}

void wypisz_i(int *poczatek, int *koniec){
    while (poczatek < koniec)
        printf ("%4d ", *poczatek++);
    printf ("\n");
    return;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void swap_pointer(int** a, int** b){
    int* tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void swap_all(void *a, void *b, size_t rozmiar){
    char *pa = a;
    char *pb = b;
    char temp;
    for(int i = 0; i < rozmiar; i++){
        temp = *pa;
        *pa = *pb;
        *pb = temp;
        pa++;
        pb++;
    }
    return;
}

int** find_min_wsk_wsk(int* tab[N], int n){
    int min = 0;
    for(int i = 1; i < n; i++){
        if(*tab[i] < *tab[min])
            min = i;
    }
    return &tab[min];
}
