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

int main(void){
    srand(time(NULL));
    int n;
    while (1){
        printf("Podaj liczbę prób (liczba całkowita): ");
        scanf("%d", &n);
        if ((n % 1 != 0) || (n <= 0) || (n > INT_MAX)){
            printf("Podałeś wartość która nie jest typu integer!\n");
            continue;
        }
        else{
            break;
        }
    }
    double wartosci[n];
    for (int j = 0; j < n; j++){
        int suma = 0;
        for (int i = 0; i < 1000; i++){
            double x = d_rand(0.0, 1.0);
            double y = d_rand(0.0, 1.0);
            if (pow(x,2) + pow(y,2) <= 1){
                suma += 1;
            }
        }
        double pi = ((float)(4 * suma)) / ((float)1000);
        wartosci[j] = pi;
        printf("Wartość pi to w przybliżeniu %.17f\n", wartosci[j]);
    }
    int min = 0, max = 0;
    for (int i = 0; i < n; i++){
        if (wartosci[i] < wartosci[min]){
            min = i;
        } 
        if (wartosci[i] > wartosci[max]){
            max = i;
        } 
    }
    double mini = wartosci[min];
    double maks = wartosci [max];
    double koncowe[2];
    koncowe[0] = mini;
    koncowe[1] = maks;
    printf("Najmniejsza wartość pi to %.17f, a największa wartość to %.17f\n", koncowe[0], koncowe[1]);
    return 0;
}