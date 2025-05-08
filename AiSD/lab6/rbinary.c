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
int binarySearch(int* arr, int left, int right, int key);

int main() {
    srand(time(NULL));
    int n = N;
    int tab[n];
    for(int i = 0; i < n; i++)
        tab[i] = rand_i(1, n);
    quicksort(tab, 0, n - 1);
    int key;
    printf("Podaj liczbę z zakresu od %d do %d\n", 1, n);
    printf("Liczba: ");
    scanf("%d", &key);
    int result = binarySearch(tab, 0, n - 1, key);
    if (result == -1)
        printf("Podanej liczby nie ma w tablicy!\n");
    else
        printf("Podana liczba jest w tablicy, index = %d", result);
    return 0;
}

int binarySearch(int* arr, int left, int right, int key){
    if (right >= left){
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);
        return binarySearch(arr, mid + 1, right, key);
    }
    return -1;
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
