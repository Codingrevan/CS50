#include <stdio.h>

int main(void){
    double eps;
    printf("Podaj dokladnosc: ");
    scanf("%lf", &eps);
    if ((eps <= 0 || eps >= 1.0)){
        printf("Podales nieprawidlowa wartosc!\n");
        return 1;
    }
    double suma = 0.0;
    double wyraz;
    int counter = 1;
    int licznik = 1;
    while ((1.0 / counter) >= eps){
        wyraz = (1.0 / counter);
        printf("Wyraz %d to %f\n",licznik,wyraz);
        suma = suma + wyraz;
        counter++;
        licznik++;
    }
    printf("Suma szeregu jest rowna: %lf\n", suma);
    return 0;
}