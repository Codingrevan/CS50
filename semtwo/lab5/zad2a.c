#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Użycie: %s (lista słów)!\n", argv[0]);
        return 1;
    }
    char** tab = NULL;
    int index = 0;
    char* token = strtok(argv[1], ", ;.:");
    while(token){
        tab = realloc(tab, (index + 1) * sizeof(char*));
        if(!tab){
            printf("Za mało pamięci na stercie!\n");
            free(tab);
            tab = NULL;
            return 2;
        }
        tab[index] = token;
        index++;
        token = strtok(NULL, ", ;.:");
    }
    int count = 1;
    char* max = tab[0];
    for(int i = 1; i < index; i++){
        if(strcmp(max, tab[i]) == 0)
            count++;
        if(strcmp(max, tab[i]) == -1){
            max = tab[i];
            count = 1;
        }
    }
    //"The sun did not shine. It was too wet to play. So we set ine the house, All that cold wet day."
    printf("Longest: %s, count: %d\n", max, count);
    free(tab);
    tab = NULL;
    return 0;
}