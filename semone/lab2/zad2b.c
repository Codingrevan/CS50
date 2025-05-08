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
    for (int i = 0; i <= (n-1); i++){
        znaki = znaki + 2;
    }
    int gwiazdki = 1;
    int spacje = znaki - 1;
    for (int i = 0; i <= (n-1); i++){
        for (int j = 1; j <= (spacje/2) - 1; j++){
            printf(" ");
        }
        for (int w = 1; w <= gwiazdki; w++){
            printf("*");
        }
        for (int j = 1; j <= (spacje/2) - 1; j++){
            printf(" ");
        }
        spacje = spacje - 2;
        gwiazdki = gwiazdki + 2;
        printf("\n");
    }
    return 0;
}