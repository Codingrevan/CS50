#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>

void razem(int *f_1, int *l_1, int *f_2, int *l_2, int *f);
void swap (int* a, int* b);
void sortowanie(int* tab, int n);

int i_rand(int min, int max){
    return rand() % (max - min + 1) + min;
}

int main(int argc, char* argv[]){
    srand(time(NULL));
    int n;
    while(1){
        printf("Podaj rozmiar drugiej tablicy: ");
        scanf("%d", &n);
        if (!(n % 1 == 0) || (n <= 0) || (n > INT_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else
            break;
    }
    int tab1[argc - 1];
    printf("tab1 = {");
    for (int i = 0; i < argc - 1; i++){
        tab1[i] = atoi(argv[i + 1]);
        if (i + 1 == argc - 1)
            printf("%d}\n", tab1[i]);
        else
            printf("%d,", tab1[i]);
    }
    int tab2[n];
    printf("tab2 = {");
    for (int i = 0; i < n; i++){
        tab2[i] = i_rand(0,100);
        if (i + 1 == n)
            printf("%d}\n", tab2[i]);
        else
            printf("%d,", tab2[i]);
    }
    printf("Posortowana tab1 = {");
    sortowanie(tab1, argc - 1);
    printf("Posortowana tab2 = {");
    sortowanie(tab2, n);
    int x = argc - 1;
    int tab3[x + n];
    for (int i = 0; i < n + x; i++){
        tab3[i] = 0;
    }
    razem(tab1, &n, tab2, &x, tab3);
    printf("tab3 = {");
    for (int i = 0; i < n + x; i++){
        if (i + 1 == n + x)
            printf("%d}\n", tab3[i]);
        else
            printf("%d,", tab3[i]);
    }
}

void razem(int *f_1, int *l_1, int *f_2, int *l_2, int *f){
    int* tab1 = f_1;
    int* tab2 = f_2;
    int n = *l_1;
    int x = *l_2;
    int count1 = 0;
    int count2 = 0;
    int* tab3 = f;
    for (int i = 0; i < n + x; i++){
        if (*tab1 < *tab2){
            *tab3 = *tab2;
            tab3++;
            tab2++;
            count2++;
        }
        else{
            *tab3 = *tab1;
            tab3++;
            tab1++;
            count1++;
        }
        if (count1 == n){
            for(int j = 0; j < n + x - count2; j++){
                *tab3 = *tab2;
                tab3++;
                tab2++;
            }
            goto finish;
        }
        if (count2 == x){
            for(int j = 0; j < n + x - count1; j++){
                *tab3 = *tab1;
                tab3++;
                tab1++;
            }
            goto finish;
        }
    }
    finish:
}

void sortowanie(int* tab, int n){
    int check = 1;
    for (int i = 1; i < n; i++){
        if (check == 1){
            check = 0;
            for (int j = 0; j < (n - i); j++){
                if (tab[j+1] > tab[j]){
                    check = 1;
                    swap(&tab[j+1],&tab[j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (i + 1 == n)
            printf("%d}\n", tab[i]);
        else
            printf("%d,", tab[i]);
    }
}

void swap (int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}