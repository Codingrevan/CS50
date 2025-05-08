#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>

float f_rand(float min, float max) {
    float r = (float)rand() / RAND_MAX;
    return r * (max - min) + min;
}

double d_rand(double min, double max) {
    double r = (double)rand() / RAND_MAX;
    return r * (max- min) + min;
}

int i_rand(int min, int max){
    return rand() % (max - min + 1) + min;
}

void zadanie1();
void zadanie2();
void and_pointer(int *first, int *second, int *result);
void or_pointer(int *first, int *second, int *result);
void xor_pointer(int *first, int *second, int *result);
void not_pointer(int *first, int *result);
void zadanie3();
void swap(double* a, double* b);
void zadanie4();
void zadanie5();
float tabsrednia(float *tab, int n);
float tabmax(float *tab, int n);
float tabmin(float *tab, int n);
double tabiloczyn(float *tab, int n);
double tabiloraz(float *tab, int n);
void zadanie6();
void zliczanie(int *tab, int n);
void zadanie7();
void zadanie8();
void add_pointer(int *pierwsza, int *druga);
void substract_pointer(int *pierwsza, int *druga);
void multiply_pointer(int *pierwsza, int *druga);
void divide_pointer(int *pierwsza, int *druga);

int main() {
    srand(time(NULL));
    while (1){
        printf("\n");
        printf("Wybierz zadanie 1-8, 0 aby zakończyć:\n");
        printf("\n");
        printf("1 - zadanie 1\n");
        printf("2 - zadanie 2\n");
        printf("3 - zadanie 3\n");
        printf("4 - zadanie 4\n");
        printf("5 - zadanie 5\n");
        printf("6 - zadanie 6\n");
        printf("7 - zadanie 7\n");
        printf("8 - zadanie 8\n");
        printf("\n");
        int var;
        printf("Podaj co chcesz zrobić: ");
        scanf("%d", &var);
        printf("\n");
        switch (var){
            case 1: 
                    zadanie1(); 
                    break;
            case 2: 
                    zadanie2(); 
                    break;
            case 3: 
                    zadanie3(); 
                    break;
            case 4: 
                    zadanie4(); 
                    break;
            case 5: 
                    zadanie5(); 
                    break;
            case 6: 
                    zadanie6(); 
                    break;
            case 7: 
                    zadanie7(); 
                    break;
            case 8: 
                    zadanie8(); 
                    break;
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
    printf("\n");
    double pierwsza;
    long long druga;
    char trzecia;
    while (1){
        printf("Podaj wartość typu double: ");
        scanf("%lf", &pierwsza);
        if ((pierwsza < DBL_MIN) || (pierwsza > DBL_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else{
            break;
        }
    }
    while(1){
        printf("Podaj wartość typu long long: ");
        scanf("%jd", &druga);
        if ((druga < LONG_LONG_MIN) || (druga > LONG_LONG_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else{
            break;
        }
    }
    while (1){
        printf("Podaj wartość typu char: ");
        scanf(" %c", &trzecia);
        if ((trzecia < CHAR_MIN) || (trzecia > CHAR_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else{
            break;
        }
    }
    double* p1 = &pierwsza;
    long long* p2 = &druga;
    char* p3 = &trzecia;
    printf("\n");
    printf("Wartość zmiennej typu double to: %lf a jej adres to %p\n", pierwsza, p1);
    printf("Wartość zmiennej typu long long to: %jd a jej adres to %p\n", druga, p2);
    printf("Wartość zmiennej typu char to: %c a jej adres to %p\n", trzecia, p3);
    double npierwsza;
    long long ndruga;
    char ntrzecia;
    printf("\n");
    while (1){
        printf("Podaj nową wartość typu double: ");
        scanf("%lf", &npierwsza);
        if ((npierwsza < DBL_MIN) || (npierwsza > DBL_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else{
            break;
        }
    }
    while(1){
        printf("Podaj nową wartość typu long long: ");
        scanf("%jd", &ndruga);
        if ((ndruga < LONG_LONG_MIN) || (ndruga > LONG_LONG_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else{
            break;
        }
    }
    while (1){
        printf("Podaj nową wartość typu char: ");
        scanf(" %c", &ntrzecia);
        if ((ntrzecia < CHAR_MIN) || (ntrzecia > CHAR_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else{
            break;
        }
    }
    printf("\n");
    p1 = &npierwsza;
    p2 = &ndruga;
    p3 = &ntrzecia;
    pierwsza = *p1;
    druga = *p2;
    trzecia = *p3;
    printf("Wartość zmiennej typu double to: %lf a jej adres to %p\n", pierwsza, &pierwsza);
    printf("Wartość zmiennej typu long long to: %jd a jej adres to %p\n", druga, &druga);
    printf("Wartość zmiennej typu char to: %c a jej adres to %p\n", trzecia, &trzecia);
    printf("\n");
}

void zadanie2(){
    printf("Wywołano funkcję dla zadania 2:\n");
    printf("\n");
    while (1){
        printf("\n");
        printf("Wybierz zadanie 1-4, 0 aby zakończyć:\n");
        printf("\n");
        printf("1 - operacja AND\n");
        printf("2 - operacja OR\n");
        printf("3 - operacja XOR\n");
        printf("4 - operacja NOT\n");
        printf("\n");
        int var;
        printf("Podaj co chcesz zrobić: ");
        scanf("%d", &var);
        printf("\n");  
        switch(var){
            case 1: 
                    int andfirst, andsecond, andresult;
                    while(1){
                        printf("Podaj pierwszą wartość logiczną: ");
                        scanf("%d", &andfirst);
                        if (andfirst != 1 && andfirst != 0){
                            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie\n");
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    while(1){
                        printf("Podaj pierwszą wartość logiczną: ");
                        scanf("%d", &andsecond);
                        if (andsecond != 1 && andsecond != 0){
                            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie\n");
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    and_pointer(&andfirst, &andsecond, &andresult); 
                    printf("\n");
                    printf("Wynik to %d\n", andresult);
                    break;
            case 2: 
                    int orfirst, orsecond, orresult;
                    while(1){
                        printf("Podaj pierwszą wartość logiczną: ");
                        scanf("%d", &orfirst);
                        if (orfirst != 1 && orfirst != 0){
                            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie\n");
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    while(1){
                        printf("Podaj pierwszą wartość logiczną: ");
                        scanf("%d", &orsecond);
                        if (orsecond != 1 && orsecond != 0){
                            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie\n");
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    or_pointer(&orfirst, &orsecond, &orresult); 
                    printf("\n");
                    printf("Wynik to %d\n", orresult);
                    break;
            case 3: 
                    int xorfirst, xorsecond, xorresult;
                    while(1){
                        printf("Podaj pierwszą wartość logiczną: ");
                        scanf("%d", &xorfirst);
                        if (xorfirst != 1 && xorfirst != 0){
                            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie\n");
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    while(1){
                        printf("Podaj pierwszą wartość logiczną: ");
                        scanf("%d", &xorsecond);
                        if (xorsecond != 1 && xorsecond != 0){
                            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie\n");
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    xor_pointer(&xorfirst, &xorsecond, &xorresult); 
                    printf("\n");
                    printf("Wynik to %d\n", xorresult);
                    break;
            case 4: 
                    int notfirst, notresult;
                    while(1){
                        printf("Podaj pierwszą wartość logiczną: ");
                        scanf("%d", &notfirst);
                        if (notfirst != 1 && notfirst != 0){
                            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie\n");
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    not_pointer(&notfirst, &notresult); 
                    printf("\n");
                    printf("Wynik to %d\n", notresult);
                    break;
            case 0: 
                    printf("Koniec programu.\n"); 
                    goto zadanie2end;
            default: 
                    printf("Podałeś nieprawidłową opcje! Spróbuj ponownie.\n");
        }
    }
    zadanie2end:
        printf("\n");
}

void and_pointer(int *first, int *second, int *result){
    *result=(*first&&*second) ? 1 : 0;
}

void or_pointer(int *first, int *second, int *result){
    *result=(*first||*second) ? 1 : 0;
}

void xor_pointer(int *first, int *second, int *result){
    *result=(*first!=*second) ? 1 : 0;
}

void not_pointer(int *first, int *result){
    *result=(!*first) ? 1 : 0;
}

void zadanie3(){
    printf("Wywołano funkcję dla zadania 3:\n");
    printf("\n");
    double pierwsza, druga;
    while (1){
        printf("Podaj pierwszą wartość typu double: ");
        scanf("%lf", &pierwsza);
        if ((pierwsza < DBL_MIN) || (pierwsza > DBL_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else{
            break;
        }
    }
    while (1){
        printf("Podaj drugą wartość typu double: ");
        scanf("%lf", &druga);
        if ((druga < DBL_MIN) || (druga > DBL_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else{
            break;
        }
    }
    swap(&pierwsza,&druga);
    printf("\n");
    printf("Po zamianianie pierwsza z wprowadzonych to: %lf a druga to: %lf\n",pierwsza,druga);
    printf("\n");
}

void swap (double* a, double* b){
    double tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void zadanie4(){
    printf("Wywołano funkcję dla zadania 4:\n");
    printf("\n");
    int n = 10;
    double tab[n];
    double losowa;
    for (int i = 0; i < n; i++){
        losowa = d_rand(-100.0,100.0);
        tab[i] = losowa;
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("Element %d tablicy to %lf\n", i+1, tab[i]);
    }
    printf("\n");
    int check = 1;
    for (int i = 1; i < n; i++){
        if (check == 1){
            check = 0;
            for (int j = 0; j < (n - i); j++){
                if (tab[j+1] < tab[j]){
                    check = 1;
                    swap(&tab[j+1],&tab[j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        printf("Po zmianach %d element tablicy to: %lf\n", i+1, tab[i]);
    }
    printf("\n");
}

void zadanie5(){
    printf("Wywołano funkcję dla zadania 5:\n");
    int n = 10;
    printf("\n");
    float tab[n];
    float losowa;
    for (int i = 0; i < n; i++){
        losowa = f_rand(-100.0, 100.0);
        tab[i] = losowa;
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("Element %d tablicy to %f\n", i+1, tab[i]);
    }
    printf("\n");
    float srednia = tabsrednia(tab, n);
    float max = tabmax(tab, n);
    float min = tabmin(tab, n);
    double iloczyn = tabiloczyn(tab, n);
    double iloraz = tabiloraz(tab, n);
    printf("Średnia wartość elementów w tablicy wynosi: %f\n", srednia);
    printf("Maksymalna wartość w tablicy to: %f\n", max);
    printf("Minimalna wartość w tablicy to: %f\n", min);
    printf("Iloczyn elementów w tablicy wynosi: %lf\n", iloczyn);
    if (iloraz == 0){
        printf("Ilorazu elementów tablicy nie da się policzyć, ponieważ jeden z nich jest równy zero!\n");
    }
    else{
        printf("Iloraz elementów tablicy jest równy: %lf\n", iloraz);
    }
    printf("\n");
}

float tabsrednia(float *tab, int n){
    float suma = 0.0;
    for (int i = 0; i < n; i++){
        suma = suma + tab[i];
    }
    float srednia = ((float)suma) / ((float)n);
    return srednia;
}

float tabmax(float *tab, int n){
    float max = -200.0;
    for (int i = 0; i < n; i++){
        if (tab[i] > max){
            max = tab[i];
        }
    }
    return max;
}

float tabmin(float *tab, int n){
    float min = 200.0;
    for (int i = 0; i < n; i++){
        if (tab[i] < min){
            min = tab[i];
        }
    }
    return min;
}

double tabiloczyn(float *tab, int n){
    double iloczyn = 1.0;
    for (int i = 0; i < n; i++){
        iloczyn = iloczyn * (tab[i]);
    }
    return iloczyn;
    
}
double tabiloraz(float *tab, int n){
    double iloraz = ((double)(tab[0]));
    for (int i = 1; i < (n - 1); i++){
        iloraz = iloraz / (tab[i]);
    }
    return iloraz;
    
}

void zadanie6(){
    printf("Wywołano funkcję dla zadania 6:\n");
    printf("\n");
    int n = 10;
    printf("\n");
    int tab[n];
    int losowa;
    for (int i = 0; i < n; i++){
        losowa = i_rand(-100,100);
        tab[i] = losowa;
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("Element %d tablicy to %d\n", i+1, tab[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (tab[min] > tab[j]){
                min = j;
            }
        }
        int tmp = tab[i];
        tab[i] = tab[min];
        tab[min] = tmp;
    }
    for (int i = 0; i < n; i++){
        printf("Po posortowaniu %d element tablicy to: %d\n", i+1, tab[i]);
    }
    printf("\n");
}

void zadanie7(){
    printf("Wywołano funkcję dla zadania 7:\n");
    printf("\n");
    int n = 10;
    int tab[n];
    int losowa;
    for (int i = 0; i < n; i++){
        losowa = i_rand(-100,100);
        tab[i] = losowa;
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("Element %d tablicy to %d\n", i+1, tab[i]);
    }
    printf("\n");
    zliczanie(tab, n);
}

void zliczanie(int *tab, int n){
    int counter = 1;
    for (int i = 1; i <= (n - 1); i++){
        for (int j = 0; j <= (i - 1); j++){
            if (tab[j] == tab[i]){
                break;
            }
            if (j == (i - 1)){
                counter++;
            }
        }
    }
    int unikalne[counter];
    int wartosci[counter];
    unikalne[0] = tab[0];
    int licznik = 1;
    for (int i = 1; i <= (n - 1); i++){
    for (int j = 0; j <= (i - 1); j++){
            if (tab[j] == tab[i]){
                break;
            }
            if (j == (i - 1)){
                unikalne[licznik] = tab[i];
                licznik++;
            }
        }
    }
    int ile = 0;
    for (int i = 0; i < counter; i++){
        for (int j = 0; j < n; j++){
            if (unikalne[i] == tab[j]){
                ile++;
            } 
        }
        wartosci[i] = ile;
        ile = 0;
    }
    for (int i = 0; i < counter; i++){
        printf("Wartość: %d -> liczba wystąpień: %d\n", unikalne[i], wartosci[i]);
    }
    printf("\n");
}

void zadanie8(){
    printf("Wywołano funkcję dla zadania 8:\n");
    printf("\n");
    int pierwsza, druga;
    while (1){
        printf("Podaj wartość pierwszej liczby: ");
        scanf("%d", &pierwsza);
        if (!(pierwsza % 1 == 0) || (pierwsza < INT_MIN) || (pierwsza > INT_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else{
            break;
        }
    }
    while (1){
        printf("Podaj wartość drugiej liczby: ");
        scanf("%d", &druga);
        if (!(druga % 1 == 0) || (druga < INT_MIN) || (druga > INT_MAX)){
            printf("Podałeś nieprawidłową wartość! Spróbuj ponownie.\n");
            continue;
        }
        else{
            break;
        }
    }
    printf("\n");
    int var; 
    while(1){
        printf("0 - wyjście z programu\n");
        printf("1 - dodwanie\n");
        printf("2 - odejmowanie\n");
        printf("3 - mnożenie\n");
        printf("4 - dzielenie\n");
        printf("\n");
        printf("Podaj co chcesz zrobić: ");
        scanf("%d", &var);
        printf("\n");
        switch (var){
            case 0: goto zadanie8end;
                    break;
            case 1: add_pointer(&pierwsza, &druga);
                    break;
            case 2: substract_pointer(&pierwsza, &druga);
                    break;
            case 3: multiply_pointer(&pierwsza, &druga);
                    break;
            case 4: divide_pointer(&pierwsza, &druga);
                    break;
            default: printf("Podałeś nieprawidłową opcję! Spróbuj ponownie.\n");
        }
    }
    zadanie8end:
        printf("\n");
}

void add_pointer(int *pierwsza, int *druga){
    int suma = *pierwsza + *druga;
    printf("Suma podanych liczb wynosi: %d\n", suma);
    printf("\n");
}

void substract_pointer(int *pierwsza, int *druga){
    int roznica = *pierwsza - *druga;
    printf("Różnica podanych liczb wynosi: %d\n", roznica);
    printf("\n");
}

void multiply_pointer(int *pierwsza, int *druga){
    int iloczyn = *pierwsza * *druga;
    printf("Iloczyn podanych liczb wynosi: %d\n", iloczyn);
    printf("\n");
}

void divide_pointer(int *pierwsza, int *druga){
    float iloraz = *druga == 0 ? 0.0 : (((float)(*pierwsza))/((float)(*druga)));
    if (iloraz == 0.0){
        printf("Nie wolno dzielic przez 0!\n");
    }
    else{
        printf("Iloraz podanych liczb wynosi: %f\n", iloraz);
    }
    printf("\n");
}
