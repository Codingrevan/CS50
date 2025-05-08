#include <stdio.h>
#include <stdlib.h>

void swap_all(void *a, void *b, size_t rozmiar);
void swap_tab(int *A, int *B, int n);
void swap_rows(int n, int (*TAB)[n], int x, int y);
void print_tab2d_all(int y,int a[][y], int x);

int main(void){
	int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}};
	int tab_22 [5][2] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
	printf("Przed zamianą swap_tab\n");
	print_tab2d_all(2, tab_22, 5);
	printf("\nPo zamianie swap_tab\n");
	swap_tab(tab_22[0] + 2, tab_22[0] + 4, 2);
	print_tab2d_all(2, tab_22, 5);
	printf("\nPrzed zmianą swap_rows\n");
	print_tab2d_all(5, tab_1, 4);
	swap_rows(5, tab_1, 1, 3);
	printf("\nPo zamianie swap_rows\n");
	print_tab2d_all(5, tab_1, 4);
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

void swap_tab(int *A, int *B, int n){
	swap_all(A, B, n * sizeof(n));
}

;
void swap_rows(int n, int (*TAB)[n], int x, int y){
	int (*ptr1)[n] = TAB + x;
	int (*ptr2)[n] = TAB + y;
	swap_all(ptr1, ptr2, n * sizeof(n));
}
