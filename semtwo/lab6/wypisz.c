#include <stdio.h>
#include <stdlib.h>

void wypisz (double* tab, int n){
    for(int i  = 0; i < n; i++)
        printf("%lf, ", tab[i]);
    printf("\n");
}

int main(void){
    double tab_1[] ={1.9, 3.8};
    double tab_2[23] ={41.9, -63.8};
    wypisz(tab_1, sizeof(tab_1)/sizeof(tab_1[0]));
    wypisz(tab_2,sizeof(tab_2)/sizeof(tab_2[0]));
    return 0;
}
