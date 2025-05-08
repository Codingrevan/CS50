#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>

int main(void) {
    int prezenty;
    printf("🎅  Ile prezentów przygotował Mikołaj (int): ");
    scanf("%d", &prezenty);
    if ((prezenty % 1 != 0) || (prezenty < INT_MIN) || (prezenty > INT_MAX)){
        printf("Podales wartosc ktora nie jest typu integer!\n");
        return 1;
    }
    printf("🎁  Wprowadzone dane: %d\n", prezenty);
    printf("🎁  Rozmiar zmiennej: %zu bajty\n", sizeof(int));
    printf("🎁  Zakres: od %d do %d\n", INT_MIN, INT_MAX);
    printf("\n");

    float waga;
    printf("🎅  Podaj wagę jednego prezentu w kilogramach (float): ");
    scanf("%f", &waga);
    if ((waga < FLT_MIN) || (waga > FLT_MAX)){
        printf("Podales wartosc ktora nie jest typu float!\n");
        return 1;
    }
    printf("🎁  Wprowadzone dane: %.2f kg\n", waga);
    printf("🎁  Rozmiar zmiennej: %zu bajty\n", sizeof(float));
    printf("🎁  Zakres: od %e do %e\n", FLT_MIN, FLT_MAX);
    printf("\n");

    double objetosc;
    printf("🎅  Podaj objętość jednego prezentu w m3 (double): ");
    scanf("%lf", &objetosc);
    if ((objetosc < DBL_MIN) || (objetosc > DBL_MAX)){
        printf("Podales wartosc ktora nie jest typu double!\n");
        return 1;
    }
    printf("🎁  Wprowadzone dane: %.2f m3\n", objetosc);
    printf("🎁  Rozmiar zmiennej: %zu bajty\n", sizeof(double));
    printf("🎁  Zakres: od %e do %e\n", DBL_MIN, DBL_MAX);
    printf("\n");

    char kategoria;
    printf("🎅  Podaj kategorię prezentu (char, np. A-zabawki, B-książki): ");
    scanf(" %c", &kategoria);
    if ((objetosc < CHAR_MIN) || (objetosc > CHAR_MAX)){
        printf("Podales wartosc ktora nie jest typu double!\n");
        return 1;
    }
    printf("🎁  Wprowadzone dane: %c\n", kategoria);
    printf("🎁  Rozmiar zmiennej: %zu bajt\n", sizeof(char));
    printf("🎁  Zakres: od %d do %d\n", CHAR_MIN, CHAR_MAX);
    printf("\n");

    int gotowy;
    printf("🎅  Czy prezent jest gotowy do dostarczenia? (0 - nie, 1 - tak): ");
    scanf("%d", &gotowy);
    if (gotowy == 1)
        printf("🎁  Wprowadzone dane: Gotowy\n");
    if (gotowy == 0)
        printf("🎁  Wprowadzone dane: Nie gotowy\n");
    if ((gotowy != 0) || (gotowy != 1)){
        printf("Podales nieprawidlowa wartosc rozna od 0 lub 1!\n");
        return 1;
    }
    printf("🎁  Rozmiar zmiennej: %zu bajty\n", sizeof(int));
    printf("🎁  Zakres: 0 (false) lub 1 (true)\n");
    return 0;
}

