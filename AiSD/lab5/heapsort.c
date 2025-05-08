#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

int parent(int n);
int left(int n);
int right(int n);
void swap(int* a, int* b);
void max_heapify(int* A, int i, int heap_size);
void build_max_heap(int* A, int length);
void heapsort(int* A, int lenght);

int main(void){
    srand(time(NULL));
    int n = N;
    int tab[n];
    for(int i = 0; i < n; i++)
        tab[i] = rand_i(1, n);
    clock_t start = clock();
    heapsort(tab, n);
    clock_t stop = clock();
    printf("%d %lf\n", n, (double)(stop - start) / CLOCKS_PER_SEC);
    return 0;
}

int parent(int n){
    return (n - 1) / 2;
}

int left(int n){
    return 2 * n + 1;
}

int right(int n){
    return 2 * n + 2;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void max_heapify(int* A, int i, int heap_size){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l < heap_size && A[l] > A[largest])
        largest = l;
    if(r < heap_size && A[r] > A[largest])
        largest = r;
    if(largest != i){
        swap(A + i, A + largest);
        max_heapify(A, largest, heap_size);
    }
}

void build_max_heap(int* A, int length){
    for(int i = (length / 2) - 1; i >= 0; i--)
        max_heapify(A, i, length);
}

void heapsort(int* A, int lenght){
    build_max_heap(A, lenght);
    for(int i = lenght - 1; i >= 1; i--){
        swap(A, A + i);
        max_heapify(A, 0, i);
    }
}