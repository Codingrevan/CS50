#include <stdio.h> 

int main(void){
    int n;
    printf("Podaj wysokosc choinki: ");
    scanf("%d", &n);
    if (n <= 0){
        printf("Podales nieprawidlowa wartosc!\n");
        return 1;
    }
    int znaki = 1;
    int i = 0;
    while (i <= (n-2)){
        znaki = znaki + 2;
        i++;
    }
    int gwiazdki = znaki;
    int spacje = 0;
    i = 0;
    int j = 0;
    while (i <= (n-1)){
        while (j <= (spacje/2) - 1){
            printf(" ");
            j++;
        }
        j = 0;
        while (j <= (gwiazdki - 1)){
            printf("*");
            j++;
        }
        j = 0;
        while (j <= (spacje/2) - 1){
            printf(" ");
            j++;
        }
        j = 0;
        spacje = spacje + 2;
        gwiazdki = gwiazdki - 2;
        printf("\n");
        i++;
    }
}