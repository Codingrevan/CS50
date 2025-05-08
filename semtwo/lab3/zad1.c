#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 5
#define COL 4

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

void wypisz_i (int *poczatek, int *koniec){
    while (poczatek < koniec)
        printf ("%4d ", *poczatek++);
    printf ("\n");
    return;
}

int suma(int *tab, int n);
int find_min_wsk(int *T_F, int *T_L);

int main(void){
    srand(time(NULL));
    int tab[ROW][COL];
    int *ptr = NULL;
    for(ptr = tab[0]; ptr <= tab[0] + ROW * COL; ptr++)
        *ptr = rand_i(-10,10);
    wypisz_i(tab[0], tab[0] + ROW * COL);
    int suma_all = suma(tab[0], ROW * COL);
    printf("Suma_all = %d\n", suma_all);
    int suma_1 = suma(tab[0], ROW * COL / 2);
    printf("Suma_1 = %d\n", suma_1);
    int suma_2 = suma(tab[0] + ROW * COL / 2, ROW * COL / 2);
    printf("Suma_2 = %d\n", suma_2);
    int min1 = find_min_wsk(tab[0], tab[0] + ROW * COL / 2);
    int min2 = find_min_wsk(tab[0] + ROW * COL / 2, tab[0] + ROW * COL);
    printf("Najmniejsza wartość w pierwszej połowie to %d o adresie: %p\n", *(tab[0] + min1), tab[0] + min1);
    printf("Najmniejsza wartość w drugiej połowie to %d o adresie: %p\n", *(tab[0] + ROW * COL / 2 + min2), tab[0] + ROW * COL / 2 + min2);
    int row1 = min1 / COL;
    int col1 = min1 % COL;
    printf("abc[%d][%d] = %d\n", row1, col1, *(tab[0] + min1));
    int row2 = (min2 + ROW * COL / 2) / COL;
    int col2 = (min2 + ROW * COL / 2) % COL;
    printf("abc[%d][%d] = %d\n", row2, col2, *(tab[0] + ROW * COL / 2 + min2));
    return 0;
}

int suma(int *tab, int n){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += *(tab + i);
    return sum;
}

int find_min_wsk(int *T_F, int *T_L){
    int min = 0;
    for(int i = 1; i < (int)(T_L - T_F); i++)
        if(T_F[min] > T_F[i]) 
            min = i;
    return min;
}