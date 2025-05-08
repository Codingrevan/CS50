#include <stdio.h>

int main(void){
    int counter=0;
    int a,b;
    printf("Podaj dolny zakres: ");
    scanf("%d",&a);
    while (1){
        printf("Podaj gorny zakres: ");
        scanf("%d",&b);
        if (b>=a){
            break;
        }
    }
    int n,m;
        while (1){
        printf("Podaj przez co liczba ma byc podzielna: ");
        scanf("%d",&n);
        if (n!=0){
            break;
        }
    }
    printf("Podaj przez co liczba ma byc niepodzielna: ");
    scanf("%d",&m);

    for (int i=a;i<=b;i++)
    {
        if ((i % n == 0) && !(i % m == 0))
        {
            printf("%d\n",i);
            counter++;
        }
    }
    printf("Takich liczb jest: %d\n",counter);
}