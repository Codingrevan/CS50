#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc == 1){
        printf("Nie podano żadnych argumentów przy wywołaniu!\n");
        return 0;
    }
    for(int i = 1; i < argc; i++)
        printf("%s\n", argv[i]);
    for(int i = 1; i < argc; i++){
        for(int j = i + 1; j < argc; j++){
                if(strcmp(argv[i], argv[j]) == 0)
                    argv[j]="";
        }
    }
    for(int i = 1; i < argc; i++)
        printf("%s", argv[i]);
    printf("\n");
    return 0;
}