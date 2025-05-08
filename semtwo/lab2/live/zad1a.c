#include <stdio.h>
#define N 50

int find_min_ind(int*, int);

int main(void){
	int tab_A[]={3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};
	int minind = find_min_ind(tab_A,  N);
	printf("tab[%d] = %d - minimalna wartość\n", minind, tab_A[minind]);
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


