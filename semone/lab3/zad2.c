#include <stdio.h>

int main(void){
    int suma = 0;
    int iloczyn = 1;
    for (int i = 10; i <= 30; i++){
        if ((i % 2 == 0) && (i % 3 == 0)){
            printf("%d ", i);
            suma = suma + i;
            iloczyn = iloczyn * i;
        }
    }
    printf("\n");
    printf("Suma = %d, iloczyn = %d.\n", suma, iloczyn);
    return 0;
}