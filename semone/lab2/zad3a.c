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
    do{
        znaki = znaki + 2;
        i++;
    }while (i <= (n-2));
    int gwiazdki = znaki;
    int spacje = 0;
    i = 0;
    int j = 0;
    int counter = 0;
    do{
        
        do{
            if (counter != 0)
                printf(" ");
            j++;
        }while (j <= (spacje/2) - 1);
        j = 0;
        do{
            printf("*");
            j++;
        }while (j <= (gwiazdki - 1));
        j = 0;
        do{
            if (counter != 0)
                printf(" ");
            j++;
        }while (j <= (spacje/2) - 1);
        j = 0;
        spacje = spacje + 2;
        gwiazdki = gwiazdki - 2;
        printf("\n");
        i++;
        counter++;
    }while (i <= (n-1));
}