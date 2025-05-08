#include <stdio.h>
#include <stdlib.h>

void zamien1(double*, double*); 
void zamien2(double, double);

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
    zamien2(p1, p2);
    zamien1(&p1, &p2);
    printf("(1 funkcja) Pierwsza liczba to: %.2f, a druga: %.2f\n", p1, p2);
    return 0;
}

void zamien1(double* p1, double* p2){
    double tmp = *p2;
    *p2 = *p1;
    *p1 = tmp;
}

void zamien2(double p1, double p2){
   	p1 += p2;
	p2 = p1 - p2;
	p1 -= p2;
    printf("(2 funkcja) Pierwsza liczba to: %.2f, a druga: %.2f\n", p1, p2);
}