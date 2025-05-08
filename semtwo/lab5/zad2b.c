#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** podziel(char* string, int* index);
void sort(char** tab, int index);
char* sklej(char** tab, int index);

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Użycie: %s (lista słów)!\n", argv[0]);
        return 1;
    }
    int index = 0;
    char** tab = podziel(argv[1], &index);
    sort(tab, index);
    char* ready = sklej(tab, index);
    puts(ready);
    //"The sun did not shine. It was too wet to play. So we sat in the house, All that cold cold, wet day."
    free(tab);
    free(ready);
    tab = NULL;
    ready = NULL;
    return 0;
}

char** podziel(char* string, int* index){
    char** tab = NULL;
    char* token = strtok(string, ", ;.:");
    int flaga = 0;
    while(token){
        for(int i = 0; i < *index; i++){
            if(strcmp(token, tab[i]) == 0)
                flaga = 1;
        }
        if(flaga != 1){
            tab = realloc(tab, (*index + 1) * sizeof(char*));
            if(!tab){
                printf("Za mało pamięci na stercie!\n");
                free(tab);
                tab = NULL;
                exit(2);
            }
            tab[*index] = token;
            (*index)++;
        }
        flaga = 0;
        token = strtok(NULL, ", ;.:");
    }
    return tab;
}

void sort(char** tab, int index){
    for(int i = 0; i < index - 1; i++){
        for(int j = 0; j < index - i - 1; j++){
            if(strcmp(tab[j], tab[j + 1]) > 0){
                char* tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}

char* sklej(char** tab, int index) {
    if(index == 0) return strdup("");
    size_t total = 0;
    for(int i = 0; i < index; i++)
        total += strlen(tab[i]);
    total += index;    
    char* result = malloc(total);
    if(!result){
        printf("Za mało pamięci na stercie!\n");
        exit(3);
    }
    result[0] = '\0';
    for(int i = 0; i < index; i++) {
        strcat(result, tab[i]);
        if(i != index - 1) strcat(result, " ");
    }
    return result;
}