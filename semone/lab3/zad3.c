#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

int i_rand(int min, int max){
    return rand() % (max - min + 1) + min;
}

int main(void){
    srand(time(NULL)); 
    int gora;
    while (1){
        printf("Podaj gorny zakres losowania: ");
        scanf("%d", &gora);
        if ((gora % 1 != 0) || (gora <= 0) || (gora > INT_MAX)){
            printf("Podałeś nieprawidłową wartość!\n");
            continue;
        }
        else{
            break;
        }
    }
    int N = i_rand(1, gora);
    N = 5;
    double calka = 0.0;
    for (double x = 0.0; x <= 5; x += 0.0001){
        double podstawa = pow((x - 5), 2);
        podstawa *= 2.5;
        calka += podstawa;
    }
    printf("Całka w przedziale [0, %d] wynosi: %lf\n", N, calka*0.0001);
    return 0;
}