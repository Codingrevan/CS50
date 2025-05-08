#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 4
void wypisz_i (int *poczatek, int *koniec) {
while (poczatek < koniec)
printf ("%4d ", *poczatek++);
printf ("\n");
return;}
int main(){
int tab_1[][COL]={1,2,3,4,5,6,7,8,9,10}; //ilosc wierszy zostanie wyznaczona na podstawie ilosci elementów
//długosc wiersza ZAWSZE MUSI BYC WPISANA - to wyznacza rozmiar pojedynczego elementu tablicy
//tablica dwuwymiarowa jest tablicą, której elementami sa wiersze, których długosc MUSI byc znana
int tab_2[ROW][COL]={1,2,3,4,5,6,7,8,9,10};
int var_2 = sizeof(tab_2)/sizeof(int);
//ilosc elementów typu integer w tablicy tab_2 - takich elementów jest ROW*COL
int var_1 = sizeof(tab_1)/sizeof(*tab_1);
//ilosc elementów w tablicy tab_1,
//traktując tablice tab_1 jako tablice jednowymiarowa o elementach-wierszach COL-elementowych -
// - takich elementów jest ROW
printf ("var_1 = %d\n", var_1);
printf ("var_2 = %d\n", var_2);
printf ("\ntab_1\n-wypisanie indeksami------------------\n");
for (int i = 0; i < var_1; i++){
for (int j=0; j < COL; j++)
printf ("tab_1[%d][%d] = %d \t", i, j, tab_1[i][j]);
printf ("\n");
}
printf ("\ntab_2\n-------------------\n");
for (int i = 0; i < ROW; i++){
for (int j=0; j < COL; j++)
printf ("tab_2[%d][%d] = %d \t", i, j, tab_2[i][j]);
printf ("\n");
}
printf ("\ntab_2\n-wypisanie wskaznikiem do integera------------------\n");
int *wsk = tab_1[0];
for (int i = 0; i < ROW*COL; i++)
printf ("i = %d tab_2[%d][%d] = %d \n", i, i/COL, i%COL, *wsk++);
printf ("\ntab_2\n-wypisanie wskaznikiem do wiersza------------------\n");
int (*pointer)[COL] = tab_2;
int j = 0; //bedzie liczył numer wiersza
while (pointer < tab_2 + ROW){
for (int i = 0; i < COL; i++)
printf ("tab_2[%d][%d] = %d ", j, i, (*pointer)[i]);
printf ("\n");
pointer++;
j++;
}
printf ("\ntab_2\n-wypisanie wskaznikiem do integera i procedura wypisz_i------------------\n");
int *wsk_1 = tab_1[0];
for (int i = 0; i < ROW; i++)
wypisz_i (wsk_1 + i*COL, wsk_1 + (i+1)*COL);
printf ("\ntab_2\n-wypisanie wskaznikiem do wiersza i procedura wypisz_i-----------------\n");
int (*pointer_1)[COL] = tab_2;
while (pointer_1 < tab_2 + ROW){
wypisz_i (*pointer_1, (*pointer_1) + COL);
printf ("\n");
pointer_1++;
}
}