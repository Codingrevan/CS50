#include <stdio.h>

int main(void){
    char b[][5] = {"Ala", "Ola", "Tola"};
    for(int i = 0; i < 3; i++)
        printf("%s ", b[i]);
    b[2][0] = 'K';
    for(int i = 0; i < 3; i++)
        printf("%s ", b[i]);
    return 0;
}