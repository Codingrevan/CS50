#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

int number_cmp(char* num_1, char* num_2);

int main(void){
    srand(time(NULL));
    int r1 = rand_i(30, 50);
    int r2 = rand_i(30, 50);
    char num_1[r1 + 1];
    printf("pierw liczba = ");
    for(int i = 0; i < r1; i++){
        if(i == 0)
            num_1[i] = '0' + rand_i(1,9);
        else    
            num_1[i] = '0' + rand_i(0,9);
        printf("%c", num_1[i]);
    }
    num_1[r1] = '\0';
    char num_2[r2 + 1];
    printf("\ndruga liczba = ");
    for(int i = 0; i < r2; i++){
        if(i == 0)
            num_2[i] = '0' + rand_i(1,9);
        else    
            num_2[i] = '0' + rand_i(0,9);
        printf("%c", num_2[i]);
    }
    num_2[r2] = '\0';
    printf("\n\n");
    int wynik = number_cmp(num_1, num_2);
    if(wynik == 0)
        printf("Liczby są równe\n");
    else if(wynik == 1)
        printf("Pierwsza liczba jest większa\n");
    else
        printf("Druga liczba jest większa\n");
    return 0;
}

int number_cmp(char* num_1, char* num_2){
    int len1 = strlen(num_1);
    int len2 = strlen(num_2);
    if(len1 > len2)
        return 1;
    if(len1 < len2)
        return -1;
    return strcmp(num_1, num_2);
}