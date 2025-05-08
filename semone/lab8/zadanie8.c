#include <stdio.h>
#include <stdlib.h>

double T(int n);

int main(int argc, char* argv[]){
    if (argc < 2 || argc > 2){
        printf("Nieprawidłowe użycie!\n");
        printf("Podaj dodatnią liczbę typu integer\n");
        return 1;
    }
    int n = atoi(argv[1]);
    if (n < 0){
        printf("Wprowadziłeś nieprawidłową wartość! Spróbuj ponownie.\n");
        return 1;
    }
    printf("Wprowadzona liczba to: %d\n", n);
    printf("Równanie rekurencyjne jest postaci:\n");
    printf("T(0) = 1\n");
    printf("T(1) = 1\n");
    printf("T(n) = 0.5 * T(n-2) * 9 * T(n-1) + 2 dla n >= 2\n");
    double wynik = T(n);
    printf("T(%d) = %.5f\n", n, wynik);
    return 0;
}

double T(int n){
    if (n == 0)
        return 1.0;
    else if (n == 1)
        return 1.0;
    else
        return 0.5 * T(n - 2) * 9 * T(n - 1) + 2;
}