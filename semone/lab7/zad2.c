#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
    if (argc < 4){
        printf("Prawidłowe użycie: %s pierwsza_liczba druga_liczba operacja\n", argv[0]);
        return 1;
    }
    int n = argc;
    int p1 = atoi(argv[n - 3]);
    printf("Pierwsza liczba: %d\n", p1);
    int p2 = atoi(argv[n - 1]);
    printf("Druga liczba: %d\n", p2);
    char* operacja = argv[n - 2];
    printf("Operacja: %c\n", *operacja);
    int wynik;
    switch (*operacja){
        case '&': 
            wynik = (p1 & p2);
            break;
        case '|': 
            wynik = (p1 | p2);
            break;
        case '^': 
            wynik = (p1 ^ p2);
            break;
        default: 
            printf("Podana operacja nie jest obsługiwana. Spróbuj ponownie.\n");
            return 1;
    }
    printf("Wynik to: %d\n", wynik);
    return 0;
}