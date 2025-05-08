#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    int gracz;
    printf("1 = kamien, 2 = papier, 3 = nozyce\n");
    printf("Podaj jaka wartosc wybierasz: ");
    scanf("%d", &gracz);
    switch (gracz){
        case 1:
        printf("Wybrales kamien\n");
        break;
        case 2:
        printf("Wybrales papier\n");
        break;
        case 3:
        printf("Wybrales nozyce\n");
        break;
        default:
        printf("Podales nieprawidlowa wartosc!\n");
        return 1;
    }
    time_t czas;
    srand((unsigned int)time(&czas));
    int komputer = 1 + rand()%(3-1+1);
    printf("Wylosowana wartosc to: %d\n", komputer);
    switch (komputer){
    case 1:
        printf("Komputer wybral kamien\n");
        break;
    case 2:
        printf("Komputer wybral papier\n");
        break;
    case 3:
        printf("Komputer wybral nozyce\n");
        break;
    }
    if (gracz == komputer)
        printf("Remis!\n");
    if (gracz == 1 && komputer == 2)
        printf("Przegrales!\n");
    if (gracz == 1 && komputer == 3)
        printf("Wygrales!\n");
    if (gracz == 2 && komputer == 1)
        printf("Wygrales!\n");
    if (gracz == 2 && komputer == 3)
        printf("Przegrales!\n");
    if (gracz == 3 && komputer == 1)
        printf("Przegrales!\n");
    if (gracz == 3 && komputer == 2)
        printf("Wygrales!\n");
    return 0;
}