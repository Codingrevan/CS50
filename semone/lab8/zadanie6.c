#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max){
    return rand() % (max - min + 1) + min;
}

int funkcja1(int op, int a, int b);
void funkcja2(int op, int a, int b, int* wynik2);

int main(int argc, char* argv[]){
    srand(time(NULL));
    if (argc < 2 || argc > 2){
        printf("Nieprawidłowo użyłeś programu!\n");
        printf("Prawidłowe użycie: %s:\n", argv[0]);
        printf("Operacja do wykonania\n");
        return 1;
    }
    char op = argv[1][0];
    int a = i_rand(-100, 100);
    int b = i_rand(-100, 100);
    printf("Pierwsza liczba: %d\n", a);
    printf("Druga liczba: %d\n", b);
    printf("Operacja: %c\n", op);
    printf("\n");
    int wynik1 = funkcja1(op, a, b);
    int wynik2;
    funkcja2(op, a, b, &wynik2);
    if(b != 0 && (op == '+' || op == '-' || op == '/' || op == '$')){
        printf("(1 funkcja) Wynik: %d %c %d = %d\n", a, op, b, wynik1);
        printf("(2 funkcja) Wynik: %d %c %d = %d\n", a, op, b, wynik2);
    }
    else if(b == 0 && (op == '+' || op == '-' || op == '/' || op == '$')){
        printf("Nie wolno dzielić przez 0!\n");
        printf("Nie wolno dzielić przez 0!\n");
    }
    return 0;
}

int funkcja1(int op, int a, int b){
    int wynik1;
    switch(op){
        case '+':
            wynik1 = a + b;
            break;
        case '-':
            wynik1 = a - b;
            break;
        case '/':
            wynik1 = (b != 0) ? a / b : 0;
            break;
        case '$':
            wynik1 = a * b;
            break;
        default:
            printf("Podana operacja nie jest obsługiwana!\n");
            wynik1 = 0;
            break;
    }
    return wynik1;
}

void funkcja2(int op, int a, int b, int* wynik2){
    int wynik;
    switch(op){
        case '+':
            wynik = a + b;
            break;
        case '-':
            wynik = a - b;
            break;
        case '/':
            wynik = (b != 0) ? a / b : 0;
            break;
        case '$':
            wynik = a * b;
            break;
        default:
            printf("Podana operacja nie jest obsługiwana!\n");
            wynik = 0;
            break;
    }
    *wynik2 = wynik;
}