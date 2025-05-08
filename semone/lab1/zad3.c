#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
    time_t czas;
    srand ( (unsigned int)time(&czas) );
    int a, b;
    printf("Podaj dolny zakres: ");
    scanf("%d",&a);
    while (1){
        printf("Podaj gorny zakres: ");
        scanf("%d", &b);
        if (!(b<a))
            break;
    }
    int n=a+rand()%(b-a+1);
    int m=a+rand()%(b-a+1);
     int check=0;
    int suma=a+b;
    int roznica=a-b;
    int iloczyn=a*b;
    int iloraz;
    if (b!=0){
        int iloraz=a/b;
    }
    else
    {
        check++;
    }
    printf("Pierwsza z wylosowanych liczb to: %d\n", n);
    printf("Druga z wylosowanych liczb to: %d\n",m);
    printf("Suma podanych liczb to: %d\n", suma);
    printf("Roznica podanych liczb to: %d\n", roznica);
    printf("Iloczyn podanych liczb to: %d\n", iloczyn);
    if (check==1)
    {
        printf("Ilorazu nie da sie policzyc\n");
    }
    else
    if (a<b)
    {
        printf("Iloraz jest mniejszy od jeden\n");
    }
    else
    {
    printf("Iloraz podanych liczb to: %d\n", iloraz);
    }
    int potega;
    if (b==0 && a!=0)
    {
        potega=1;
        printf("Potega podanych liczb to: %d\n", potega);
        return 0;
    }
    else
    if (a==0 && b==0)
    {
        printf("Potega dla tych liczb jest wartoscia niezdefiniowana\n");
        return 0;
    }
    else
    {
        potega=0;
        printf("Potega podanych liczb to: %d\n", potega);
        return 0;
    }
    for (int i=0;i<(b-2);i++){
        if (b>0)
        {
            potega=potega*potega;
        }
    }
    printf("Potega podanych liczb to: %d\n", potega);
    return 0;
}