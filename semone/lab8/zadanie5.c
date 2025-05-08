#include <stdio.h>
#include <stdlib.h>

double potega1(double x, int n); 
void potega2(double x, int n, double* potega); 

int main(int argc, char* argv[]){
    if (argc < 3 || argc > 3){
        printf("Nieprawidłowe użycie!\n");
        printf("Podaj kolejno liczbę rzeczywistą oraz liczbę typu integer\n");
        return 1;
    }
    double x = atof(argv[1]);
    int n = atoi(argv[2]);
    printf("Podstawa potęgi: %.2f\n", x);
    printf("Wykładnik potęgi: %d\n", n);
    double wynik1 = potega1(x, n);
    printf("(1 funkcja) wynik to: %.5f\n", wynik1);
    double wynik2;
    potega2(x, n, &wynik2);
    printf("(2 funkcja) wynik to: %.5f\n", wynik2);
    return 0;
}

double potega1(double x, int n){
    double wynik1 = 1.0;
    int i = 0;
    if (n == 0)
        return 1.0;
    int absn = (n < 0) ? -n : n;
    do{
        wynik1 *= x;
        i++;
    }while(i < absn);
    if(n < 0)
        wynik1 = 1.0 / wynik1;
    return wynik1;
}

void potega2(double x, int n, double* potega){
    if(n == 0){
        *potega = 1.0;
        return;
    }
    if(n < 0){
        potega2(x, -n, potega);
        *potega = 1.0 / *potega;
        return;
    }
    double tmp;
    potega2(x, n / 2, &tmp);
    if(n % 2 == 0)
        *potega = tmp * tmp;
    else
        *potega = x * tmp * tmp;
}
