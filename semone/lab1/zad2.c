#include <stdio.h>
#include <math.h>
int main(void){
    int a, b;
    printf("Podaj pierwsza liczbe: ");
    scanf("%d",&a);
    printf("Podaj druga liczbe: ");
    scanf("%d", &b);
    int check=0;
    int suma=a+b;
    int roznica=a-b;
    int iloczyn=a*b;
    int iloraz;
    if (b!=0 && a>=b){
        int iloraz=(a/b);
    }
    if (b==0)
    {
        check++;
    }
    printf("Suma podanych liczb to: %d\n", suma);
    printf("Roznica podanych liczb to: %d\n", roznica);
    printf("Iloczyn podanych liczb to: %d\n", iloczyn);
    if (check==1)
    {
        printf("Ilorazu nie da sie policzyc\n");
    }
    if (a<b && check!=1)
    {
        printf("Iloraz jest mniejszy od jeden\n");
    }
    if (check!=1 && a>=b)
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
    if (a==0 && b==0)
    {
        printf("Potega dla tych liczb jest wartoscia niezdefiniowana\n");
        return 0;
    }
    if (b<0){
        printf("potega jest mniejsza od zera");
        return 0;
    }
    if (b!=0 && a!=0)
    {
        potega=pow(a,b);   
        printf("Potega podanych liczb to: %d\n", potega);
        return 0;
    }
}