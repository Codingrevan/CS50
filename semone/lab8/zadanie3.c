#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max){
    return rand() % (max - min + 1) + min;
}

float funkcja1(int x);
void funkcja2(int x, float* wynik2);

int main(int argc, char* argv[]){
    srand(time(NULL));
    if (argc < 2 || argc > 2){
        printf("Nieprawidłowe użycie!\n");
        printf("Podaj liczbę typu integer\n");
        return 1;
    }
    int x = atoi(argv[1]);
    printf("Podana liczba to: %d\n", x);
    printf("\n");
    float wynik1 = funkcja1(x);
    printf("Wynik wywołania pierwszej funkcji to: %.2f\n", wynik1);
    printf("\n");
    float wynik2;
    funkcja2(x, &wynik2);
    printf("Wynik wywołania drugiej funkcji to: %.2f\n", wynik2);
    return 0;
}

float funkcja1(int x){
    printf("1 funkcja:\n");
    int A = i_rand(-100, 100);
    int B = i_rand(-100, 100);
    int Z = i_rand(-100, 100);
    printf("A = %d\n", A);
    printf("B = %d\n", B);
    printf("Z = %d\n", Z);
    int wynik = 0;
    if (A > B)
        wynik = (A >= x && x >= B) ? (Z != 0 && x % Z == 0) ? 2137 : 5*x - 7 : 0;
    else
        wynik = (B >= x && x >= A) ? (Z != 0 && x % Z == 0) ? 2137 : 5*x - 7 : 0;
    float koniec;
    if (wynik == 2137)
        koniec = wynik / 100.0;
    else
        koniec = (float)wynik;
    return koniec;
}

void funkcja2(int x, float* wynik2){
    printf("2 funkcja:\n");
    int A = i_rand(-100, 100);
    int B = i_rand(-100, 100);
    int Z = i_rand(-100, 100);
    printf("A = %d\n", A);
    printf("B = %d\n", B);
    printf("Z = %d\n", Z);
    int wynik = 0;
    if (A > B)
        wynik = (A >= x && x >= B) ? (Z != 0 && x % Z == 0) ? 2137 : 5*x - 7 : 0;
    else
        wynik = (B >= x && x >= A) ? (Z != 0 && x % Z == 0) ? 2137 : 5*x - 7 : 0;
    float koniec;
    if (wynik == 2137)
        koniec = wynik / 100.0;
    else
        koniec = (float)wynik;
    *wynik2 = koniec;
}