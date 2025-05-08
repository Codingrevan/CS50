#include <stdio.h>
#include <stdlib.h>

double sum1(double p1, double p2);
void sum2(double p1, double p2, double* sum22);

int main(int argc, char* argv[]){
    if (argc < 3 || argc > 3){
        printf("Nieprawidłowe użycie!\n");
        printf("Podaj kolejno dwie liczby typu double\n");
        return 1;
    }
    double p1 = atof(argv[1]);
    double p2 = atof(argv[2]);
    printf("Pierwsza liczba to: %.2f\n", p1);
    printf("Druga liczba to: %.2f\n", p2);
    double sum11 = sum1(p1, p2);
    double sum22;
    sum2(p1, p2, &sum22);
    printf("(1 funkcja) Suma podanych liczb wynosi: %.2f\n", sum11);
    printf("(2 funkcja) Suma podanych liczb wynosi: %.2f\n", sum22);
    return 0;
}

double sum1(double p1, double p2){
    return p1 + p2;
}

void sum2(double p1, double p2, double* sum22){
    double wynik = p1 + p2;
    *sum22 = wynik;
}