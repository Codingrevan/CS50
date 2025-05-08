#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double d_rand(double min, double max) {
    double r = (double)rand() / RAND_MAX;
    return r * (max- min) + min;
}

int main(void){
    srand(time(NULL));
    int N = 9 * 7;
    double tab[N];
    double dol, gora;
    while (1){
        printf("Podaj dolny zakres losowania: ");
        scanf("%lf", &dol);
        printf("Podaj górny zakres losowania ");
        scanf("%lf", &gora);
        if (dol > gora){
            printf("Podałeś nieprawidłowy zakres!\n");
            continue;
        }
        else{
            break;
        }
    }
    for (int i = 0; i < N; i++){
        double los = d_rand(dol, gora); 
        tab[i] = los;
        printf("tab[%d] = %6.2f\n", i, los);
    }
    int min = 0, max = 0;
    for (int i = 0; i < N; i++){
        if (tab[i] < tab[min]){
            min = i;
        }
        if (tab[i] > tab[max]){
            max = i;
        }
    }
    printf("\n");
    printf("Indeks najmniejszego elementiu: %d, największego %d.\n", min, max);
    printf("\n");
    double tmp = tab[min];
    tab[min] = tab[max];
    tab[max] = tmp;
    for (int i = 0; i < N; i++){
        printf("tab[%d] = %6.2f\n", i, tab[i]);
    }
    return 0;
}