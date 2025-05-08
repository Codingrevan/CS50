#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutacje(char* str, int l, int r);

int main(int argc, char* argv[]){
    if (argc < 2 || argc > 2){
        printf("Nieprawidłowe użycie!\n");
        printf("Podaj ciąg znaków, który ma zostać poddany permutacji\n");
        return 1;
    }
    char* str = argv[1];
    printf("Podany tekst: %s\n", str);
    printf("Permutacje:\n");
    int n = strlen(str);
    permutacje(str, 0, n - 1);
    return 0;
}


void permutacje(char *str, int l, int r) {
    if (l == r)
        printf("%s, ", str);
    else{
        for(int i = l; i <= r; i++){
            char tmp = str[l];
            str[l] = str[i];
            str[i] = tmp;
            permutacje(str, l + 1, r);
            tmp = str[l];
            str[l] = str[i];
            str[i] = tmp;
        }
    }
}

