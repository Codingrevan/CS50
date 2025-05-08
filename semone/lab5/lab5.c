#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>

double d_rand(double min, double max) {
    double r = (double)rand() / RAND_MAX;
    return r * (max- min) + min;
}

int i_rand(int min, int max){
    return rand() % (max - min + 1) + min;
}

void zadanie1();
void mnozenie(int n, int *A, int* B);
void zadanie2();
void maxWektorow(int* v1, int* v2, int* wynik, int n);
void zadanie3();
double *f_min(double *tab, int n);
void zadanie4();
double *f_sub(int n, double *tab1, double *tab2, double *tab3);
void zadanie5();
long long unsigned int potega(unsigned int a, unsigned int b);
void zadanie6();
long long unsigned int nwd(unsigned int a, unsigned int b);
void zadanie7();
void negate(int *a, int i_start, int i_end);

int main() {
    srand(time(NULL));
    while (1){
        printf("\n");
        printf("Wybierz zadanie 1-7, 0 aby zakończyć:\n");
        printf("\n");
        printf("1 - zadanie 1\n");
        printf("2 - zadanie 2\n");
        printf("3 - zadanie 3\n");
        printf("4 - zadanie 4\n");
        printf("5 - zadanie 5\n");
        printf("6 - zadanie 6\n");
        printf("7 - zadanie 7\n");
        printf("\n");
        int var;
        printf("Podaj co chcesz zrobić: ");
        scanf("%d", &var);
        printf("\n");
        switch (var){
            case 1: zadanie1(); break;
            case 2: zadanie2(); break;
            case 3: zadanie3(); break;
            case 4: zadanie4(); break;
            case 5: zadanie5(); break;
            case 6: zadanie6(); break;
            case 7: zadanie7(); break;
            case 0: 
                    printf("Koniec programu.\n"); 
                    return 0;
            default: 
                    printf("Podałeś nieprawidłową opcje! Spróbuj ponownie.\n");
        }
    }
    return 0;
}

void zadanie1(){
    printf("Wywołano funkcję dla zadania 1:\n");
    int n = 3;
    int A[n][n], B[n][n];
    int losowa;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            losowa = i_rand(0,10);
            A[i][j] = losowa;
        }
    }
    printf("\n");
    printf("Macierz A jest postaci:\n");
    for (int i = 0; i < n; i++){
        printf("{");
        for (int j = 0; j < n; j++)
            j != 2 ? printf("%i, ", A[i][j]) : printf("%i}\n", A[i][j]);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            losowa = i_rand(0,10);
            B[i][j] = losowa;
        }
    }
    printf("\n");
    printf("Macierz B jest postaci:\n");
    for (int i = 0; i < n; i++){
        printf("{");
        for (int j = 0; j < n; j++)
            j != 2 ? printf("%i, ", B[i][j]) : printf("%i}\n", B[i][j]);
    }
    printf("\n");
    mnozenie(n, (int *)A, (int *)B);
}

void mnozenie(int n, int* A, int* B){
    int* tmpA = A;
    int* tmpB = B;
    int C[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int chwilowa = 0;
            for (int w = 0; w < n; w++){
                chwilowa = chwilowa + (*tmpA)*(*tmpB);
                tmpA = tmpA + 1;
                tmpB = tmpB + n;
            }
            C[i][j] = chwilowa;
            tmpA = A + i*n;
            tmpB = B + j + 1;
        }
        tmpA = A + (i+1)*n;
        tmpB = B;
    }
    printf("Macierz C jest postaci:\n");
    for (int i = 0; i < n; i++){
        printf("{");
        for (int j = 0; j < n; j++)
            j != 2 ? printf("%i, ", C[i][j]) : printf("%i}\n", C[i][j]);
    }
}

void zadanie2(){
    printf("Wywołano funkcję do zadania 2:\n");
    printf("\n");
    int n; 
    while(1){
        printf("Podaj ilu wymiarowe mają być wektory: ");
        scanf("%d", &n);
        if (!(n % 1 == 0) || (n < INT_MIN) || (n > INT_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else
            break;
    }
    printf("\n");
    int v1[n], v2[n];
    int* tmpv1 = v1;
    int* tmpv2 = v2;
    printf("Wektor 1: [");
    for (int i = 0; i < n; i++){
        *tmpv1 = i_rand(0,10);
        if(i != (n -1))
            printf("%d, ", *tmpv1);
        else
            printf("%d]\n", *tmpv1);
        tmpv1++;
    }
    printf("Wektor 2: [");
    for (int i = 0; i < n; i++){
        *tmpv2 = i_rand(0,10);
        if(i != (n - 1))
            printf("%d, ", *tmpv2);
        else
            printf("%d]\n", *tmpv2);
        tmpv2++;
    }
    int wynik[n];
    maxWektorow(v1, v2, wynik, n);
    int *tmpw = wynik;
    printf("Wynik: [");
    for (int i = 0; i < n; i++){
        if(i != (n - 1))
            printf("%d, ", *tmpw);
        else
            printf("%d]\n", *tmpw);
        tmpw++;
    }
}

void maxWektorow(int* v1, int* v2, int* wynik, int n){
    int* tmpv1 = v1;
    int* tmpv2 = v2;
    int* tmpvw = wynik;
    for (int i = 0; i < n; i++){
        if(*tmpv1 > *tmpv2)
            *wynik = *tmpv1;
        else
            *wynik = *tmpv2;
        tmpv1++;
        tmpv2++;
        wynik++;
    }
}

void zadanie3(){
    printf("Wywołano funkcję do zadania 3:\n");
    printf("\n");
    int n = 10;
    double tab[n];
    double* tmp = tab;
    for (int i = 0; i < n; i++){
        *tmp = d_rand(0.0,1.0);
        printf("tab[%d] = %lf, adres elementu: %p\n", i, *tmp, tmp);
        tmp++;
    }
    double *min = f_min(tab, n);
    printf("Minimum: tab[%d] = %lf, adres elementu: %p\n", min - tab, *min, min);
}

double *f_min(double *tab, int n){
    double* tmp = tab;
    double* min = tab;
    tmp++;
    for (int i = 0; i < (n-1); i++){
        if(*min > *tmp)
            min = tmp;
        tmp++;
    }
    return min;
}

void zadanie4(){
    printf("Wywołano funkcję do zadania 4:\n");
    printf("\n");
    int n = 10;
    double tab1[n], tab2[n], tab3[n];
    double* tmp1 = tab1;
    for (int i = 0; i < n; i++){
        *tmp1 = d_rand(-2.0,2.0);
        printf("tab[%d] = %lf, adres elementu: %p\n", i, *tmp1, tmp1);
        tmp1++;
    }
    printf("\n");
    double* tmp2 = tab2;
    for (int i = 0; i < n; i++){
        *tmp2 = d_rand(-2.0,2.0);
        printf("tab[%d] = %lf, adres elementu: %p\n", i, *tmp2, tmp2);
        tmp2++;
    }
    printf("\n");
    double *min = f_sub(n, tab1, tab2, tab3);
    double* tmp3 = tab3;
    for (int i = 0; i < n; i++){
        printf("tab[%d] = %lf, adres elementu: %p\n", i, *tmp3, tmp3);
        tmp3++;
    }
    printf("Minimum: tab[%d] = %lf, adres elementu: %p\n", min - tab3, *min, min);
}

double *f_sub(int n, double *tab1, double *tab2, double *tab3){
    double* tmp1 = tab1;
    double* tmp2 = tab2;
    double* tmp3 = tab3;
    for (int i = 0; i < n; i++){
        *tmp3 = *tmp1 - *tmp2;
        tmp1++;
        tmp2++;
        tmp3++;
    }
    double* min = f_min(tab3, n);
    return min;
}

void zadanie5(){
    printf("Wywołano funkcję do zadania 5:\n");
    printf("\n");
    unsigned int a;
    unsigned int b;
    while(1){
        printf("Podaj podstawę potęgi: ");
        scanf("%d", &a);
        if (!(a % 1 == 0) || (a < 0) || (a > INT_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else
            break;
    }
    while(1){
        printf("Podaj wykładnik liczbę: ");
        scanf("%d", &b);
        if (!(b % 1 == 0) || (b < 0) || (b > INT_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else
            break;
    }
    if (a == 0 || b == 0){
        printf("0^0 to symbol nieoznaczony!\n");
        goto end;
    }
    long long unsigned int wynik = potega(a,b);
    printf("Wynik: %llu\n", wynik);
    end:
}

long long unsigned int potega(unsigned int a, unsigned int b){
    static int wywolaniep = 0;
    wywolaniep++;
    printf("Wywołanie nr: %d\n", wywolaniep);
    if (b == 0)
        return 1;
    else
        return a * potega(a, b - 1);
}

void zadanie6(){
    printf("Wywołano funkcję do zadania 6:\n");
    printf("\n");
    unsigned int a;
    unsigned int b;
    while(1){
        printf("Podaj pierwszą liczbę: ");
        scanf("%d", &a);
        if (!(a % 1 == 0) || (a < 0) || (a > INT_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else
            break;
    }
    while(1){
        printf("Podaj drugą liczbę: ");
        scanf("%d", &b);
        if (!(b % 1 == 0) || (b < 0) || (b > INT_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else
            break;
    }
    long long unsigned int wynik = nwd(a, b);
    printf("Wynik: %llu\n", wynik);
}

long long unsigned int nwd(unsigned int a, unsigned int b){
    static int wywolanien = 0;
    wywolanien++;
    printf("Wywołanie nr: %d\n", wywolanien);
    if (b == 0)
        return a;
    else
        return nwd(b, a % b);
}

void zadanie7(){
    printf("Wywołano funkcję dla zadania 7:\n");
    printf("\n");
    int liczba;
    while(1){
        printf("Podaj liczbę całkowitą: ");
        scanf("%d", &liczba);
        if (!(liczba % 1 == 0) || (liczba > INT_MAX) || (liczba < INT_MIN)){
            printf("Podałeś nieprawidłową wartość! Spróbuj jeszcze raz.\n");
            continue;
        }
        else{
            break;
        }
    }
    printf("\n");
    printf("Liczba przed negacją to: %d\n", liczba); 
    printf("\n");
    negate(&liczba, 0, 3); 
    printf("Liczba po negacji to: %d\n", liczba);
    printf("\n");
    negate(&liczba, -1, sizeof(liczba)); 
    negate(&liczba, 2, 1); 
    negate(&liczba, 1, sizeof(int) * CHAR_BIT);
}

void negate(int *a, int i_start, int i_end){
    if (i_start < 0 || i_end < 0 || i_end < i_start || i_end >= sizeof(int) * CHAR_BIT){ 
        printf("Błędne numery bitów.\n");
        printf("\n"); 
        return; 
    }
    unsigned int mask = 0; 
    for (int i = i_start; i <= i_end; i++)
        mask |= (1 << i); 
    printf("Maska bitowa: 0x%X\n", mask);
    printf("\n");
    *a ^= mask;
}