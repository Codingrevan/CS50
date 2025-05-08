#include <stdio.h>
#include <stdlib.h>

double max1(double, double); 
void max2(double, double, double *);

int main(int argc, char* argv[]){
    if (argc < 3 || argc > 3){
        printf("Nieprawidłowe użycie!\n");
        printf("Podaj dwie liczby typu double\n");
        return 1;
    }
    double p1 = atof(argv[1]);
    double p2 = atof(argv[2]);
    printf("Pierwsza z podanych liczb to: %.2f\n", p1);
    printf("Druga z podanych liczb to: %.2f\n", p2);
    double max11 = max1(p1, p2);
    double max22;
    max2(p1, p2, &max22);
    printf("(1 funkcja) Max podanych liczb to: %.2f\n", max11);
    printf("(2 funkcja) Max podanych liczb to: %.2f\n", max22);
    if (p1 > p2){
        int n = abs((int)p1 - (int)p2);
        for (int i = 0; i < n; i++)
            (i + 1 == n) ? printf("%d\n", (int)p2 + i + 1) : printf("%d, ", (int)p2 + i + 1);
    }
    else{
        int n = abs((int)p1 - (int)p2);
        for (int i = 0; i < n; i++)
            (i + 1 == n) ? printf("%d\n", (int)p1 + i + 1) : printf("%d, ", (int)p1 + i + 1);
    }
    return 0;
}

double max1(double p1, double p2){
    double wynik = (p1 > p2) ? p1 : p2;
    return wynik;
}

void max2(double p1, double p2, double* max22){
    double wynik = (p1 > p2) ? p1 : p2;
    *max22 = wynik;
}