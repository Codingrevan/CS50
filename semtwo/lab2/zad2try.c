#include <stdio.h>

unsigned bits(unsigned x);
void write_binar(unsigned n, char * wsk);

int main(void){
    unsigned number, result;
    scanf("%u", &number);
    char bin_string[sizeof(unsigned)*8+1];
    write_binar(number, bin_string);
    printf("liczba wczytana %d : %s \n", number, bin_string);
    result = bits(number);
    write_binar(result, bin_string);
    printf("%u po wyzerowaniu bitów %s\n", result, bin_string);
    return 0;
}

void write_binar(unsigned n, char* wsk){
    unsigned mask = 0xFFFFFFFF;
    for(int i = 0; i < sizeof(unsigned) * 8; i++)
        wsk[i] = (n && mask) ? '1' : '0';
    wsk[sizeof(unsigned) * 8 + 1] = '\0';
}

unsigned bits(unsigned x){
    unsigned mask = 0xAAAAAAAA;
    return x & mask;
}