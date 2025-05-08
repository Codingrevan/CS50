#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void set_tab_d(double *first, double *last, double min, double max);
double *my_alloc(int i_min, int i_max);
void my_free(double **my_tab, int i_min);

double rand_d(double a, double b){
        double r = (double)rand() / RAND_MAX;
        return r * (b - a) + a;
}

int main(void){
	srand(time(NULL));
	int i_min = -2, i_max = 4;
	int rozmiar = (i_max - i_min + 1);
	double* tab = my_alloc(i_min, i_max);
	set_tab_d(tab, tab + rozmiar, 8.8, 8.8);
	printf("Pierwsze ustawienie wartości:\n");
	for(int i = i_min; i < i_max; i++)
		printf("tab[%d] = %lf, adres: %p\n", i , tab[i], tab + i + i_min);
	printf("\nDrugie ustawienie wartości:\n");
	set_tab_d(tab + 1, tab + rozmiar - 1, -10.0, 10.0);
	for(int i = -2; i < i_max; i++)
		printf("tab[%d] = %lf, adres: %p\n", i, tab[i], tab + i + i_min);
	my_free(&tab, (i_max - i_min + 1));
	my_free(&tab, (i_max - i_min + 1));
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

void set_tab_d(double *first, double *last, double min, double max){
    while (first < last){
        *--last = rand_d(min, max);
    }
  	return;
}

double *my_alloc(int i_min, int i_max){
	if(i_min > i_max){
		printf("Podałeś niepoprawny zakres indeksów!\n");
		exit(1);
		}
	double* tab = malloc((i_max - i_min + 1) * sizeof(double));
	if(!tab){
		printf("Za mało pamięci na stercie!\n");
		exit(1);
	}
	return tab - i_min;
}

void my_free(double **my_tab, int i_min){
	if(*my_tab != NULL)
		free(*my_tab);
	*my_tab = NULL;
}
