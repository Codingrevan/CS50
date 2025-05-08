#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 4


int rand_i(int a, int b){
        return (a + rand() % (b - a + 1));
}

double* tab_avg(int row, int tab[][row]);
void wypisz_i (int *poczatek, int *koniec);
void wypisz_d (double *poczatek, double *koniec);
void set_tab_i(int *first, int *last, int min, int max);
void print_tab2d_all(int y,int a[][y], int x);

int main(void){
	srand(time(NULL));
	int TAB[N][M];
	set_tab_i(TAB[0], TAB[0] + N * M, -5, 5);
	int (*ptr)[M] = TAB;
	for(int i = 0; i < N; i++)
		print_tab2d_all(M, ptr++, 1);
	double* wynik = tab_avg(M, TAB);
	wypisz_d(wynik, wynik + N);
	free(wynik);
	wynik = NULL;
	return 0;
}

void print_tab2d_all(int y,int a[][y], int x){
	int i, j;
    for (i = 0; i < x; i++){
    	for (j = 0; j < y; j++)
        	printf ("%3d", a[i][j]);
        printf ("\n");
    }
    return;
}

void set_tab_i(int *first, int *last, int min, int max){
    while (first < last){
        *--last = rand_i(min, max);
    }
    return;
}

int suma_i (int *tab, int len){
	int ss = 0.0;
    for (int i = 0; i < len; i++)
    	ss+= tab[i];
    return ss;
}

void wypisz_i (int *poczatek, int *koniec){
	while (poczatek < koniec)
    	printf ("%4d ", *poczatek++);
    printf ("\n");
    return;
}

void wypisz_d (double *poczatek, double *koniec){
	while (poczatek < koniec)
    	printf ("%6.2g ", *poczatek++);
    printf ("\n");
    return;
}

double* tab_avg(int row, int tab[][row]){
	double* wynik = malloc(N * sizeof(double));
	if(!wynik){
		printf("Za mało pamięci na stercie!\n");
		exit(1);
	}
	double average;
	for(int i = 0; i < N; i++){
		average = (double)suma_i(tab[i], row) / M;
		wynik[i] = average;
	}
	return wynik;
}
