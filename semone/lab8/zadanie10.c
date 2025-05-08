#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ascsort(double* tab, int n);
void descsort(double* tab, int n);

int main(int argc, char* argv[]){
    if (argc < 7 || argc > 7){
        printf("Nieprawidłowe użycie!\n");
        printf("Kolejno 5 liczb typu double oraz sposob sortowania (asc/desc)\n");
        return 1;
    }
    char* str = argv[6];
    int n = argc - 2;
    double tab[n];
    double tabtmp[n];
    for (int i = 0; i < 5; i++){
        tab[i] = atof(argv[i + 1]);
        tabtmp[i] = atof(argv[i + 1]);
    }
    if (strcmp(str, "asc") == 0)
        ascsort(tab, 5);
    else if (strcmp(str, "desc") == 0)
        descsort(tab, 5);
    else{
        printf("Podałeś niepoprawny rodzaj sortowania!\n");
        return 1;
    }
    printf("Tabela przed posortowaniem: [");
    for (int i = 0; i < n; i++)
        (i != (n - 1)) ? printf("%.2f, ", tabtmp[i]) : printf("%.2f]\n", tabtmp[i]);
    printf("Tabela po posortowaniu: [");
    for (int i = 0; i < n; i++)
        (i != (n - 1)) ? printf("%.2f, ", tab[i]) : printf("%.2f]\n", tab[i]);
    return 0;
}

void ascsort(double *tab, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (*(tab + j) > *(tab + j + 1)){
                double tmp = *(tab + j);
                *(tab + j) = *(tab + j + 1);
                *(tab + j + 1) = tmp;
            }
        }
    }
}

void descsort(double *tab, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (*(tab + j) < *(tab + j + 1)){
                double tmp = *(tab + j);
                *(tab + j) = *(tab + j + 1);
                *(tab + j + 1) = tmp;
            }
        }
    }
}
