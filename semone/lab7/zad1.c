#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
    if (argc < 3){
        printf("Prawidłowe użycie: %s x współczynniki...\n", argv[0]);
        return 1;
    }
    int n = argc;
    char **idruk = argv;
    idruk += 2;
    char **check = idruk;
    int suma = 0;
    int wykladnikdruk = argc - 3;
    int chwilowa;
    char **xowa = argv;
    xowa++;
    printf("Wartość zostanie obliczona dla x = %d\n", atoi(*xowa));
    printf("Wielomian jest postaci: W(x) = ");
    while (*idruk != NULL){
        if (idruk != check)
            printf(" + ");
        printf("%dx^%d", atoi(*idruk), wykladnikdruk);
        wykladnikdruk--;
        idruk++;
    }
    printf("\n");
    char **i = argv;
    i += argc - 1;
    int wykladnik = 0;
    while (i >= argv + 2){
        chwilowa = atoi(*i) * pow(atoi(*xowa), wykladnik);
        suma += chwilowa;
        wykladnik++;
        i--;
    }
    printf("Wynik to: %d\n", suma);
    return 0;
}