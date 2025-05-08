#include <stdio.h>
#define N 50

int find_min_ind(int* tab_A, int n);
void print_ten(int tab[], int* wsk);

int main(void){
	int tab_A[]={3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};
	print_ten(tab_A, tab_A+20);
	return 0;
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

void print_ten(int tab[], int* wsk){
	int* p = NULL;
	int min = find_min_ind(wsk, 10);
	printf("zakres %d - %d --> ", (int)(wsk - tab), (int)(wsk - tab + 9));
	for(p = wsk; p < wsk + 10; p++)
		printf("tab[%d] = %d, ", (int)(p - tab), *p);
	printf("\nelement minimalny wartosc = %d, adres = %p, indeks = %d\n", tab[(int)(wsk - tab) + min], &(tab[(int)(wsk - tab) + min]), (int)(wsk - tab) + min);
}


