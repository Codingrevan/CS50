#include <stdio.h>
#define N 10

void swap_all(void*, void*, int n);

int main(void){
	double first = 1.23, second = 4.56;
	int tab1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int tab2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	printf("PRZED: double1 = %lf, double2 = %lf\n", first, second);
	swap_all(&first, &second, sizeof(double));
	printf("PO: double1 = %lf, double2 = %lf\n", first, second);
	printf("PRZED:\n");
	for(int i = 0; i < N; i++)
		printf("tab1[%d] = %d\n", i, tab1[i]);
	printf("\n");
	for(int i = 0; i < N; i++)
		printf("tab2[%d] = %d\n", i, tab2[i]);
	printf("\nPO:\n");
	swap_all(tab1, tab2, sizeof(int)*N);
	for(int i = 0; i < N; i++)
		printf("tab1[%d] = %d\n", i, tab1[i]);
	printf("\n");
	for(int i = 0; i < N; i++)
		printf("tab2[%d] = %d\n", i, tab2[i]);
	return 0;
}

void swap_all(void* a, void* b, int n){
	char* first = a;
	char* second = b;
	for(int i = 0; i < n; i++){
		char tmp = *first;
		*first = *second;
		*second = tmp;
		first++;
		second++;
	}
}
