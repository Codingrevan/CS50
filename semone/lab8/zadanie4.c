#include <stdio.h>
#include <stdlib.h>

int add31 (int a, int b, int c, int d, int e); 
void add32 (int a, int b, int c, int d, int e, int* sum2);

int main(int argc, char* argv[]){
    if (argc < 6 || argc > 6){
        printf("Nieprawidłowe użycie!\n");
        printf("Podaj kolejno 5 liczb typu integer\n");
        return 1;
    }
    int a = atoi(argv[1]);
    printf("Pierwsza liczba to: %d\n", a);
    int b = atoi(argv[2]);
    printf("Druga liczba to: %d\n", b);
    int c = atoi(argv[3]);
    printf("Trzecia liczba to: %d\n", c);
    int d = atoi(argv[4]);
    printf("Czwarta liczba to: %d\n", d);
    int e = atoi(argv[5]);
    printf("Piąta liczba to: %d\n", e);
    int sum1 = add31(a, b, c, d, e);
    int sum2;
    add32(a, b, c, d, e, &sum2);
    printf("(1 funkcja) Suma podanych liczb wynosi: %d\n", sum1);
    printf("(2 funkcja) Suma podanych liczb wynosi: %d\n", sum2);
    return 0;
}

int add31 (int a, int b, int c, int d, int e){
    int n = 5;
    int tab[] = {a, b, c, d, e};
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += tab[i];
    return sum;

}

void add32 (int a, int b, int c, int d, int e, int* sum2){
    int n = 5;
    int tab[] = {a, b, c, d, e};
    int sum = 0;
    int i = 0;
    do{
        sum += tab[i];
        i++;
    }while(i < n);
    *sum2 = sum;
}