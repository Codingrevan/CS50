#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    time_t czas;
    srand((unsigned int)time(&czas));
    int n = 65 + rand() % (90 - 65 + 1);
    int var;
    printf("Podaj czy piramida ma byc malejaca - 1 czy rosnaca - 0: ");
    scanf("%d", &var);
    switch (var)
    {
        case 0: {
            int znaki = n-64;
            int spacje = (n - 65)*2;
            int j = 0, w = 1;
            int tmp = 1, number = 1;
            int sign = 0;
            int counter = 0;
            int print;
            while(j <= (znaki-1)){
                while(w <= (spacje / 2)){
                    printf(" ");
                    w++;
                }
                w = 1;
                while(tmp >= 0){
                    print = 65 + sign;
                    printf("%c", print);
                    if (counter == 0){
                        if (sign < tmp){
                            sign++;
                            tmp--;
                        }
                        if ((sign - 1) >= tmp){
                            counter++;
                            sign--;
                        }
                    }
                    if (counter != 0){
                        sign--;
                        tmp--;
                    }
                }
                w = 1;
                while(w <= (spacje / 2)){
                    printf(" ");
                    w++;
                }
                w = 1;
                printf("\n");
                sign = 0;
                counter = 0;
                spacje = spacje - 2;
                number = number + 2;
                tmp = number;
                j++;
            }
        break;
        }
        case 1:{
            int znaki = n - 64;
            int spacje = 0;
            int j = 0, w = 1;
            int number = (n-65)*2 + 1;
            int tmp = number;
            int sign = 0;
            int counter = 0;
            int print;
            while(j <= (znaki-1)){
                while(w <= (spacje / 2)){
                    printf(" ");
                    w++;
                }
                w = 1;
                while(tmp >= 0){
                    print = 65 + sign;
                    printf("%c", print);
                    if (counter == 0){
                        if (sign < tmp){
                            sign++;
                            tmp--;
                        }
                        if ((sign-1) >= tmp){
                            counter++;
                            sign--;
                        }
                    }
                    if (counter != 0){
                        sign--;
                        tmp--;
                    }
                }
                w = 1;
                while(w <= (spacje / 2)){
                    printf(" ");
                    w++;
                }
                w = 1;
                printf("\n");
                sign = 0;
                counter = 0;
                spacje = spacje + 2;
                number = number - 2;
                tmp = number;
                j++;
            }
        break;
        }
    default : printf("Podales nieprawidlowa wartosc!\n");
              return 1;
    }
    return 0;
}