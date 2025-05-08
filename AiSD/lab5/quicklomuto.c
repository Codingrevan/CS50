#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

void swap(int* a, int* b);
void quicksort(int* A, int low, int high);
int partition(int* A, int low, int high);

int main(void){
    srand(time(NULL));
    int n = N;
    int tab[n];
    for(int i = 0; i < n; i++)
        tab[i] = rand_i(1, n);
    clock_t start = clock();
    quicksort(tab, 0, n - 1);
    clock_t stop = clock();
    printf("%d %lf\n", n, (double)(stop - start) / CLOCKS_PER_SEC);
    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(int* A, int low, int high){
    int pivot = A[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(A[j] < pivot){
            i++;
            swap(A + i, A + j);
        }
    }
    swap(A + i + 1, A + high);
    return i + 1;
}
 
void quicksort(int* A, int low, int high){
    if(low < high){
        int pi = partition(A, low, high);
        quicksort(A, low , pi - 1);
        quicksort(A, pi + 1, high);
    }
}
