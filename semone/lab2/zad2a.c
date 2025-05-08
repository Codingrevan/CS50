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
    while (i <= (n-1)){
        znaki = znaki + 2;
        i++;
    }
    int gwiazdki = 1;
    int spacje = znaki - 1;
    int i = 0;
    int j = 1;
    while (i <= (n-1)){
        while (j <= (spacje/2) - 1){
            printf(" ");
            j++;
        }
        j = 1;
        while (j <= gwiazdki){
            printf("*");
            j++;
        }
        j = 1;
        while (j <= (spacje/2) - 1){
            printf(" ");
            j++;
        }
        j = 1;
        spacje = spacje - 2;
        gwiazdki = gwiazdki + 2;
        printf("\n");
        i++;
    }
    return 0;
}