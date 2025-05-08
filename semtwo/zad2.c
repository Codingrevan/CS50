#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void proc_1(void* base, size_t num, size_t width);
int modcmpr(const void* a, const void* b);
int max(int *tab, int len);
void proc_2(void* base, size_t num, size_t width);
int maxcmpr(const void* a, const void* b);
int row1 = 3;
int row2 = 4;

int main(void){
	int tab_A[3][6] = {{1,-4,1,2,11,55},{12,2,32,2},{72,1,-32,2}};
	int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
	int col1 = 6;
	size_t liczba1 = col1;
	size_t width1 = sizeof(int);
	printf("Przed sortowaniem tab_A\n");
	for(int i = 0; i < row1; i++){
		printf("wiersz %d --> ", i);
		for(int j = 0; j < col1; j++)
			printf("%d ", tab_A[i][j]);
		printf("\n");
	}
	proc_1(tab_A, liczba1, width1);
	printf("\nPosortowana tab_A\n");
	for(int i = 0; i < row1; i++){
		printf("wiersz %d --> ", i);
		for(int j = 0; j < col1; j++)
			printf("%d ", tab_A[i][j]);
		printf("\n");
	}

	int col2 = 3;
	size_t liczba2 = row2;
	size_t width2 = sizeof(int) * col2;
	printf("\nPrzed sortowaniem tab_B\n");
	for(int i = 0; i < row2; i++){
		printf("wiersz %d --> ", i);
		for(int j = 0; j < col2; j++)
			printf("%d ", tab_B[i][j]);
		printf("\n");
	}
	proc_2(tab_B, liczba2, width2);
	printf("\nPosortowana tab_B\n");
	for(int i = 0; i < row2; i++){
		printf("wiersz %d --> ", i);
		for(int j = 0; j < col2; j++)
			printf("%d ", tab_B[i][j]);
		printf("\n");
	}
	return 0;
}

void proc_1(void* base, size_t num, size_t width){
	for(int i  = 0; i < row1; i++){
		qsort(base, num, width, modcmpr);
		base += width * num;
	}
}

void proc_2(void* base, size_t num, size_t width){
	qsort(base, num, width, maxcmpr);
}

int modcmpr(const void* a, const void* b){
	int x =  *(const int*)a % 2;
	int y =  *(const int*)b % 2;
	return x - y;
}

int max(int *tab, int len){
	int ind = 0;
    for (int i = 1; i < len; i++)
    	if (tab[ind] < tab[i])
   			ind = i;
    return ind;
}

int maxcmpr(const void* a, const void* b){
	int max1 = ((int*)a)[max((int*)a, row2)];
	int max2 = ((int*)b)[max((int*)b, row2)];
	if(max1 < max2)
		return -1;
	else if(max1 > max2)
		return 1;
	return 0;
}
