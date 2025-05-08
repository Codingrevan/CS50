#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <string.h>

int i_rand(int min, int max){
    return rand() % (max - min + 1) + min;
}

void zadanie1();
char *my_strchr(const char *str, int ch);
void zadanie2();
void funkcja2(char * lancuch);
void zadanie3();
void dzieleniewektorow(int n, int* v1, int* v2);
void zadanie4();
void funkcja4(char * lancuch);
void zadanie5();
int binarna_na_dziesietna(const char *binarna); 
void zadanie6();
void add_pointer(int *pierwsza, int *druga, int *wynik);
void substract_pointer(int *pierwsza, int *druga, int *wynik);
void multiply_pointer(int *pierwsza, int *druga, double *wynik);
void divide_pointer(int *pierwsza, int *druga, float *wynik);
void power_pointer(int *pierwsza, int *druga, double *wynik);
void dziesietna_na_binarna(int liczba, char *binarna);
void zadanie7();
void dziesietna_na_osemkowa(int liczba, char *osemkowa);
void zadanie8();
void substractOfDigits(int n, int* sum); 

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
            case 1: zadanie1(); break;
            case 2: zadanie2(); break;
            case 3: zadanie3(); break;
            case 4: zadanie4(); break;
            case 5: zadanie5(); break;
            case 6: zadanie6(); break;
            case 7: zadanie7(); break;
            case 8: zadanie8(); break;
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
    char str[100];
    printf("Podaj ciąg znaków, w którym chcesz znaleźć dany znak: ");
    scanf("%99s", &str);
    printf("\n");
    char ch;
    printf("Podaj znak, który chcesz znaleźć: ");
    scanf(" %c", &ch);
    printf("\n");
    char* wynik = my_strchr(str, ch);
    if (wynik == NULL)
        printf("Podany znak nie został znaleziony!\n");
    else
        printf("Podany znak znajduje się na %d miejsu licząc od początku!\n", (wynik - str) + 1);
}

char *my_strchr(const char *str, int ch){
    while (*str != '\0'){
        if (*str == ch)
            return (char* )str;
        str++; 
    }
    return NULL;
}

void zadanie2(){
    printf("Wywołano funkcję dla zadania 2:\n");
    printf("\n");
    char str[] = "To jest TESTOWY lancuch";
    printf("PRZED: %s\n", str);
    funkcja2(str);
    printf("PO: %s\n", str);
}

void funkcja2(char * lancuch){
    int n = strlen(lancuch);
    char *lewy = lancuch;
    char *prawy = lancuch + n - 1;
    while (lewy < prawy){
        while (lewy < prawy && isupper(*lewy))
            lewy++;
        while (lewy < prawy && islower(*prawy))
            prawy--;
        if (lewy < prawy){
            char tmp = *lewy;
            *lewy = *prawy;
            *prawy = tmp;
            lewy++;
            prawy--;
        }
    }
}

void zadanie3(){
    printf("Wywołano funkcję dla zadania 3:\n");
    printf("\n");
    int n;
    while(1){
        printf("Podaj ilu wymiarowe mają być wektory: ");
        scanf("%d", &n);
        if (!(n % 1 == 0) || (n < 0) || (n > INT_MAX)){
            printf("Podałeś nieprawidłową wartość, spróbuj ponownie!\n");
            continue;
        }
        else{
            break;
        }
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
    printf("\n");
    dzieleniewektorow(n, v1, v2);
}

void dzieleniewektorow(int n, int* v1, int* v2){
    float wynik[n];
    int counter = 0;
    float* tmpw = wynik;
    for (int i = 0; i < n; i++){
        if (*v2 != 0){
            *tmpw  = (float)(*v1) / (float)(*v2);
        }
        else{
            counter++;
            printf("Zmieniono wartości między tablicami!\n");
            *tmpw = (float)((*v1) + 1) / (float)((*v2) + 1);
        }
        v1++;
        v2++;
        tmpw++;
    }
    printf("W sumie dokonano %d zmian\n", counter);
    printf("\n");
    printf("Wynik: [");
    float* tmpd = wynik;
    for (int i = 0; i < n; i++){
        if(i != (n - 1))
            printf("%.2f, ", *tmpd);
        else
            printf("%.2f]\n", *tmpd);
        tmpd++;
    }
}

void zadanie4(){
    printf("Wywołano funkcję dla zadania 4:\n");
    printf("\n");
    char str[] = "To jest TESTOWY\t\nlancuch";
    printf("PRZED: %s\n", str);
    funkcja4(str);
    printf("PO: %s\n", str);
}

void funkcja4(char * lancuch){
    int n = strlen(lancuch);
    char *tmp = lancuch;
    while (*tmp != '\0'){
        if (isspace(*tmp)){
            char* move = tmp;
            for (int i = 0; i < n - (tmp - lancuch); i++){
                *move = *(move + 1);
                move++;
            }
        }
        else
            tmp++;
    }
}

void zadanie5(){
    printf("Wywołano funkcję dla zadania 5:\n");
    printf("\n");
    char binarna[33];
    printf("Podaj liczbę binarną do zamiany na dziesiętną: ");
    scanf("%32s", binarna);
    int wynik = binarna_na_dziesietna(binarna);
    printf("Podana liczba w postaci dziesiętnej to: %d\n", wynik);
}

int binarna_na_dziesietna(const char *binarna){
    int dziesietna = 0;
    int len = strlen(binarna);
    for (int i = 0; i < len; i++){
        if (binarna[len - i - 1] == '1') 
            dziesietna += pow(2, i);
    } 
    return dziesietna;
}

void zadanie6(){
    printf("Wywołano funkcję dla zadania 6:\n");
    printf("\n");
    int p1;
    while(1){
        printf("Podaj pierwszą liczbę dziesiętną: ");
        scanf("%d", &p1);
        if (!(p1 % 1 == 0) || (p1 < 0) || (p1 > INT_MAX)){
            printf("Podałeś nieprawidłową opcje! Spróbuj ponownie.");
            continue;
        }
        else{
            break;
        }
    }
    char b1[33];
    dziesietna_na_binarna(p1, b1);
    printf("Pierwsza liczba binarna: %s\n", b1);
    int p2;
    while(1){
        printf("Podaj drugą liczbę dziesiętną: ");
        scanf("%d", &p2);
        if (!(p2 % 1 == 0) || (p2 < 0) || (p2 > INT_MAX)){
            printf("Podałeś nieprawidłową opcje! Spróbuj ponownie.");
            continue;
        }
        else{
            break;
        }
    }
    char b2[33];
    dziesietna_na_binarna(p2, b2);
    printf("Druga liczba binarna: %s\n", b2);
    int suma;
    add_pointer(&p1, &p2, &suma);
    char sum[33];
    dziesietna_na_binarna(suma, sum);
    printf("Suma: %d (binarnie: %s)\n", suma, sum);
    int roznica;
    substract_pointer(&p1, &p2, &roznica);
    printf("Odejmowanie: %d - %d = %d\n", p1, p2, roznica);
    if (roznica < 0)
        roznica = 0;
    char roz[33];
    dziesietna_na_binarna(roznica, roz);
    printf("Różnica binarnie: %s\n", roz);
    double iloczyn;
    multiply_pointer(&p1, &p2, &iloczyn);
    char ilocz[33];
    dziesietna_na_binarna((int)iloczyn, ilocz);
    printf("Iloczyn: %lf (binarnie: %s)\n",iloczyn, ilocz);
    float iloraz;
    char ilora[33];
    divide_pointer(&p1, &p2, &iloraz);
    if (iloraz != 0.0){
        dziesietna_na_binarna((int)iloraz, ilora);
        printf("Iloraz: %f (binarnie: %s)\n",iloraz, ilora);
    }
    else
        printf("Nie wolno dzielić przez 0!\n");
    double potega;
    char pot[33];
    power_pointer(&p1, &p2, &potega);
    if (potega != 0.0){
        dziesietna_na_binarna((int)potega, pot);
        printf("Potęga: %lf (binarnie: %s)\n",potega, pot);
    }
    else 
        printf("0^0 to symbol nieoznaczony!\n");
}

void add_pointer(int *pierwsza, int *druga, int *wynik){
    *wynik = *pierwsza + *druga;
}

void substract_pointer(int *pierwsza, int *druga, int *wynik){
    *wynik = *pierwsza - *druga;
}

void multiply_pointer(int *pierwsza, int *druga, double *wynik){
    *wynik = *pierwsza * *druga;
}

void divide_pointer(int *pierwsza, int *druga, float *wynik){
    *wynik = *druga == 0 ? 0.0 : (((float)(*pierwsza))/((float)(*druga)));
}

void power_pointer(int *pierwsza, int *druga, double *wynik){
    if (*pierwsza == 0 && *druga != 0)
        *wynik = 1.0;
    if (*pierwsza == 0 && *druga == 0)
        *wynik = 0.0;
    else
        *wynik = pow(*pierwsza, *druga);
}

void dziesietna_na_binarna(int liczba, char *binarna){
    int i = 0; 
    if (liczba == 0){
        binarna[i] = '0';
        i++;
        goto binary;
    }
    while(liczba > 0){
        binarna[i] = (liczba % 2) + '0';
        liczba /= 2; 
        i++; 
    }
    binary:
    binarna[i] = '\0';
    int len = i; 
    for (int j = 0; j < len / 2; j++){ 
        char tmp = binarna[j]; 
        binarna[j] = binarna[len - j - 1]; 
        binarna[len - j - 1] = tmp;
    }
}

void zadanie7(){
   printf("Wywołano funkcję dla zadania 7:\n");
    printf("\n");
    int p1;
    while(1){
        printf("Podaj pierwszą liczbę dziesiętną: ");
        scanf("%d", &p1);
        if (!(p1 % 1 == 0) || (p1 < 0) || (p1 > INT_MAX)){
            printf("Podałeś nieprawidłową opcje! Spróbuj ponownie.");
            continue;
        }
        else{
            break;
        }
    }
    char b1[12];
    dziesietna_na_osemkowa(p1, b1);
    printf("Pierwsza liczba ósemkowa: %s\n", b1);
    int p2;
    while(1){
        printf("Podaj drugą liczbę dziesiętną: ");
        scanf("%d", &p2);
        if (!(p2 % 1 == 0) || (p2 < 0) || (p2 > INT_MAX)){
            printf("Podałeś nieprawidłową opcje! Spróbuj ponownie.");
            continue;
        }
        else{
            break;
        }
    }
    char b2[12];
    dziesietna_na_osemkowa(p2, b2);
    printf("Druga liczba ósemkowa: %s\n", b2);
    int suma;
    add_pointer(&p1, &p2, &suma);
    char sum[12];
    dziesietna_na_osemkowa(suma, sum);
    printf("Suma: %d (ósemkowo: %s)\n", suma, sum);
    int roznica;
    substract_pointer(&p1, &p2, &roznica);
    printf("Odejmowanie: %d - %d = %d\n", p1, p2, roznica);
    if (roznica < 0)
        roznica = 0;
    char roz[12];
    dziesietna_na_osemkowa(roznica, roz);
    printf("Różnica ósemkowo: %s\n", roz);
    double iloczyn;
    multiply_pointer(&p1, &p2, &iloczyn);
    char ilocz[12];
    dziesietna_na_osemkowa((int)iloczyn, ilocz);
    printf("Iloczyn: %lf (ósemkowo: %s)\n",iloczyn, ilocz);
    float iloraz;
    char ilora[12];
    divide_pointer(&p1, &p2, &iloraz);
    if (iloraz != 0.0){
        dziesietna_na_osemkowa((int)iloraz, ilora);
        printf("Iloraz: %f (ósemkowo: %s)\n",iloraz, ilora);
    }
    else
        printf("Nie wolno dzielić przez 0!\n");
    double potega;
    char pot[12];
    power_pointer(&p1, &p2, &potega);
    if (potega != 0.0){
        dziesietna_na_osemkowa((int)potega, pot);
        printf("Potęga: %lf (ósemkowo: %s)\n",potega, pot);
    }
    else 
        printf("0^0 to symbol nieoznaczony!\n");
}

void dziesietna_na_osemkowa(int liczba, char *osemkowa){
    int i = 0; 
    if (liczba == 0){
        osemkowa[i] = '0';
        i++;
        goto osem;
    }
    while (liczba > 0){ 
        osemkowa[i] = (liczba % 8) + '0';
        liczba /= 8;
        i++;
    }
    osem:
    osemkowa[i] = '\0';
    int len = i;
    for (int j = 0; j < len / 2; j++){
        char tmp = osemkowa[j];
        osemkowa[j] = osemkowa[len - j - 1];
        osemkowa[len - j - 1] = tmp;
    }
}

void zadanie8(){
    printf("Wywołano funkcję dla zadania 8:\n");
    printf("\n");
    int n;
    while(1){
        printf("Podaj liczbę, której różnicę cyfr chcesz obliczyć: ");
        scanf("%d", &n);
        if (!(n % 1 == 0) || (n < 0) || (n > INT_MAX)){
            printf("Podałeś nieprawidłową wartość, spróbuj ponownie!\n");
            continue;
        }
        else{
            break;
        }
    }
    int sum = 0;
    substractOfDigits(n, &sum);
    printf("\n");
    printf("Różnica cyfr liczby %d jest równa: %d\n", n, sum);
}   

void substractOfDigits(int n, int* sum){
    if (n > 9){
        *sum = *sum - (n % 10);
        n = (n - (n % 10)) / 10;
        substractOfDigits(n, sum);
    }
    else{
        *sum = *sum + n;
    }
}

