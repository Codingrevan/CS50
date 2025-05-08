#include <stdio.h>

int main(void){
    float wzrost, masa;
    printf("Podaj swoja mase w kg: ");
    scanf("%f",&masa);
    while (1){
        printf("Podaj swoj wzrost w cm: ");
        scanf("%f",&wzrost);
        if (wzrost!=0)
        {
            break;
        }
    }
    float BMI;
    BMI=masa/((wzrost/100)*(wzrost/100));
    if (BMI<18.5){
        printf("Niedowaga");
    }
    if (BMI>25.0){
        printf("Nadwaga");
    }
    return 0;
}