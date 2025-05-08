#include <stdio.h>

int main(void){
    int a,b,c;
    printf("Podaj pierwsza liczbe: ");
    scanf("%d",&a);
    printf("Podaj druga liczbe: ");
    scanf("%d",&b);
    printf("Podaj trzecia liczbe: ");
    scanf("%d",&c);
    if (a<=0 || b<=0 || c<=0){
        printf("Z podanych wartosci nie da sie zbudowac trojkata!");
        return 0;
    }
    if (a<=c && b<=c){
        if ((a*a)+(b*b)==(c*c)){
            printf("Te liczby stanowia trojke pitagorejska");
            return 0;
        }
        else
        {
            printf("Te liczby nie stanowia trojki pitagorejskiej");
            return 0;
        }
    }
    if (a<=b && c<=b){
    if ((a*a)+(c*c)==(b*b)){
        printf("Te liczby stanowia trojke pitagorejska");
        return 0;
    } 
    else
    {
        printf("Te liczby nie stanowia trojki pitagorejskiej");
        return 0;
    }
    }
    if (c<=a && b<=a){
    if ((c*c)+(b*b)==(a*a)){
        printf("Te liczby stanowia trojke pitagorejska");
        return 0;
    } 
    else
    {
        printf("Te liczby nie stanowia trojki pitagorejskiej");
        return 0;
    }
    }
}