#include <stdio.h>
#include <math.h>

int main(void){
    int a, b;
    printf("Podaj pierwsza liczbe: ");
    scanf("%d",&a);
    printf("Podaj druga liczbe: ");
    scanf("%d", &b);
    printf("1 - dodawanie\n");
    printf("2 - odejmowanie\n");
    printf("3 - dzielenie\n");
    printf("4 - mnozenie\n");
    printf("5 - potegowanie\n");
    printf("6 - pierwiastkowanie\n");
    int opcja;
    printf("Podaj jaka operacje chcesz wykonac: ");
    scanf ("%d", &opcja);
    switch (opcja){
        case 1:
            int suma = a + b;
            printf("Suma podanych liczb wynosi: %d\n", suma);
        break;
        case 2:
            int roznica = a - b;
            printf("Roznica podanych liczb wynosi: %d\n", roznica);
        break;
        case 3:
            float iloraz;
            if (b == 0){
                printf("Ilorazu nie da sie policzyc. Nie mozna dzielic przez 0!\n");
                return 1;
            }
            iloraz = (((float)a) / ((float)b));
            printf("Iloraz podanych liczb wynosi: %f\n", iloraz);
        break;
        case 4:
            double iloczyn= a * b;
            printf("Iloczyn podanych liczb wynosi: %lf\n", iloczyn);
        break;
        case 5:
            double potega;
            if (a == 0 && b == 0){
                printf("Potega podanych iczb to symbol nieoznaczony typu 0^0\n");
                return 2;
            }
            if (b == 0){
                potega = 1;
                printf("Potega podanych liczb wynosi %lf\n", potega);
            }
            potega = pow(a,b);   
            printf("Potega podanych liczb to: %lf\n", potega);
        break;
        case 6:
            if (b == 0){
                printf("Podales nieprawidlowy stopien!");
                return 3;
            }
            if (a < 0 && (b % 2 == 0)){
                printf("Podales nieprawidlowy stopien!");
                return 3;
            }
            double pierwiastek;
            float stopien = 1.0 / b;
            pierwiastek = pow(a, stopien);
            break;
        default: 
            printf("Podales nieprawidlowa wartosc!\n");
            return 1;
    }
    return 0;
}