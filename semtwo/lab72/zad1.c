#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7

int rand_i(int a, int b){
	return (a + rand() % (b - a + 1));
}

void set_tab_i(int *first, int *last, int min, int max);
void print_p (int *table[], int len, char *table_name);
void wypisz_i(int *poczatek, int *koniec);
int** find_min_wsk_wsk(int* TAB_P[N], int n);
void swap_pointer(int** a, int** b);
void swap_all(void *a, void *b, size_t rozmiar);

int main(void){
	srand(time(NULL));
	int TAB[N];
	int* TAB_P[N];
	set_tab_i(TAB, TAB + N, 1, 100);
	for(int i  = 0; i < N; i++)
		TAB_P[i] = TAB + i;
	int** WSK;
	int** MIN;
	WSK = MIN = TAB_P;
	print_p(TAB_P, N, "TAB_P");
	printf("\nTAB --> ");
	wypisz_i(*WSK, *WSK + N);
	printf("\n");
	print_p(WSK, N, "TAB_P");
	printf("\n");
	MIN = find_min_wsk_wsk(TAB_P, N);
	printf("minimum = %d indeks = %d adres = %p\n", **MIN, (int)(*MIN - *WSK), *MIN);
    swap_all((void *)*WSK, (void *)*MIN, sizeof(int));
    printf("\nTAB --> ");
    for(int i = 0; i < N; i++)
        printf ("%4d ", *TAB_P[i]);
    printf("\n\n");
	print_p(WSK, N, "TAB_P");
	
    MIN = TAB_P + N - 1;
    swap_pointer(WSK, MIN);
    printf("\nTAB przez wskaznik --> ");
   	for(int i = 0; i < N; i++)
        printf ("%4d ", *TAB_P[i]);
    printf("\n\n");
    for(int j = 0; j < N; j++)
        printf("TAB_P[%d] = %p\n", j, TAB_P[j]);
    printf("\nTAB przez identyfikator TAB --> ");
    wypisz_i(TAB, TAB + N);
    
    swap_all((void *)WSK, (void *)MIN, sizeof(int*));
    printf("\nTAB przez wskaznik --> ");
    for(int i = 0; i < N; i++)
        printf ("%4d ", *TAB_P[i]);
    printf("\n\n");
    for(int j = 0; j < N; j++)
        printf("TAB_P[%d] = %p\n", j, TAB_P[j]);
    printf("\nTAB przez identyfikator TAB --> ");
    wypisz_i(TAB, TAB + N);
	return 0;
}

void set_tab_i(int *first, int *last, int min, int max){
    while (first < last){
        *--last = rand_i(min, max);
    }
    return;
}

void print_p(int *table[], int len, char *table_name){
	for(int i = 0; i < len; i++)
		printf("%s[%d] = %p\n", table_name, i, table[i]);
}

void wypisz_i(int *poczatek, int *koniec){
	while(poczatek < koniec)
    	printf ("%4d ", *poczatek++);
    printf ("\n");
    return;
}

int** find_min_wsk_wsk(int* TAB_P[N], int n){
	int min = 0;
	for(int i = 1; i < n; i++){
		if(*TAB_P[i] < *TAB_P[min])
			min = i;
	}
	int** minindex = &TAB_P[min];
	return minindex;
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
