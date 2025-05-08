#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int wykonywanie(int p1, int p2, char operacja);
int suma(int p1, int p2);
int roznica(int p1, int p2);
int iloczyn(int p1, int p2);
int iloraz(int p1, int p2);

int main(int argc, char *argv[]) {
    if (argc < 4 || (argc- 1) % 2 == 0) {
        printf("Prawidłowe użycie: %s liczba1 operacja liczba2 [operacja liczba3 ...]\n", argv[0]);
        return 1;
    }
    char pierwsza = argv[2][0];
    int result = wykonywanie(atoi(argv[1]), atoi(argv[3]), pierwsza);
    for (int i = 4; i < argc; i += 2) {
        char operacja = argv[i][0];
        int liczba = atoi(argv[i + 1]);
        result = wykonywanie(result, liczba, operacja);
    }
    printf("Wynik końcowy: %d\n", result);
    return 0;
}

int wykonywanie(int p1, int p2, char operacja){
    int wynik;
    switch(operacja){
        case '+': 
            int sum = suma(p1, p2);
            return sum;
            break;
        case '-':
            int roz = roznica(p1, p2);
            return roz;
            break;
        case '$': 
                int ilocz = iloczyn(p1, p2);
                return ilocz;
                break;
        case '/': 
                int ilora = iloraz(p1, p2);
                if (ilora == 0)
                    exit(1);
                return ilora;
                break;
        case '&': 
            wynik = (p1 & p2);
            printf("%d & %d = %d\n", p1, p2, wynik);
            return wynik;
            break;
        case '|': 
            wynik = (p1 | p2);
            printf("%d | %d = %d\n", p1, p2, wynik);
            return wynik;
            break;
        case '^': 
            wynik = (p1 ^ p2);
            printf("%d ^ %d = %d\n", p1, p2, wynik);
            return wynik;
            break;
        case '<': 
            wynik = (p1 << p2);
            printf("%d < %d = %d\n", p1, p2, wynik);
            return wynik;
            break;
        case '>': 
            wynik = (p1 >> p2);
            printf("%d > %d = %d\n", p1, p2, wynik);
            return wynik;
            break;
        default: 
            printf("Podana operacja nie jest obsługiwana. Spróbuj ponownie.\n");
            exit(1);
    }
    return 0;
}

int suma(int p1, int p2){
    int suma = p1 + p2;
    printf("%d + %d = %d\n", p1, p2, suma);
    return suma;
}

int roznica(int p1, int p2){
    int roznica = p1 - p2;
    printf("%d - %d = %d\n", p1, p2, roznica);
    return roznica;
}

int iloczyn(int p1, int p2){
    int iloczyn = p1 * p2;
    printf("%d $ %d = %d\n",p1, p2, iloczyn);
    return iloczyn;
}           

int iloraz(int p1, int p2){
    int iloraz;
    if (p1 == 0 && p2 == 0){
        printf("Symbol nieoznaczony 0/0\n");
        return 0;
    }
    if(p2 == 0){
        printf("Nie można dzielić przez 0!\n");
        return 0;
    }
    iloraz = p1 / p2;
    printf("%d / %d = %d\n",p1, p2, iloraz);
    return iloraz;
}
