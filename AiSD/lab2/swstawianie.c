#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_i(int a, int b){
	return (a + rand() % (b - a + 1));
}

int main(void){
	srand(time(NULL));
	int n = 10000;
	for(int w = 0; w < 10; w++){
		clock_t start = clock();
		int tab[n];
		for(int i = 0; i < n; i++)
			tab[i] = rand_i(1,n);
		int i, key;
		for(int j = 1; j < n; j++){
			key = tab[j];
			i = j - 1;
			while(i > -1 && tab[i] > key){
				tab[i + 1] = tab[i];
				i--;
			}
			tab[i + 1] = key;
		}
		clock_t stop = clock();
		printf("%d %lf\n", n, (double)(stop - start) / CLOCKS_PER_SEC);
		n += 10000;
	}
}
