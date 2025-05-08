#include <stdio.h>
#define N 50

void swap(int* a, int* b);
int find_min_ind(int* tab_A, int n);
void print_ten(int tab[], int* wsk);
void sort(int*, int*);
void wypisz_i(int* poczatek, int* koniec);

int main(void){
	int tab_A[]={3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};
	for(int i = 0; i < N / 10; i++)
		sort(tab_A + (i * 10), tab_A + ((i + 1) * 10));
	wypisz_i(tab_A, tab_A + N);
	return 0;
}


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int find_min_ind(int* tab_A, int n){
	int* min = tab_A;
	int* p = NULL;
	for(p = tab_A; p < tab_A + n; p++){
		if(*p < *min)
			min = p;
	}
	return (int)(min - tab_A);
}

void sort(int* tab_A, int* tab_Aend){
	while(tab_A < tab_Aend){
		int min = find_min_ind(tab_A, (int)(tab_Aend - tab_A));
		swap(tab_A, tab_A + min);
		tab_A++;
	}
}


void wypisz_i(int* poczatek, int* koniec){
	while(poczatek < koniec)
		printf("%4d ",  *poczatek++);
	printf("\n");
	return;
}
