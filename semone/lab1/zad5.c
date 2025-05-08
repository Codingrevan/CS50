#include <stdio.h>
#include <math.h>
int main(void){
    int a,b,c;
    printf("Podaj wspolczynnik a: ");
    scanf("%d",&a);
    printf("Podaj wspolczynnik b: ");
    scanf("%d",&b);
    printf("Podaj wspolczynnik b: ");
    scanf("%d",&c);
    float x,rozw1,rozw2;
    if (a==0)
    {
        if (c==0){
            x=0;
            printf("Wynikiem jest %d\n",x);
            return 0;
        }
        x=((-b)/c);
        printf("Wynikiem jest %10.f\n",x);
        return 0;
    }
    float delta;
    delta=(b*b)-(4*a*c);
    if (delta<0){
        printf("Brak rozwiazan!");
        return 0;
    }
    if (delta==0.0){
        x=((-b)/(2*a));
        printf("Rownanie ma podwojne rozwiazanie %f\n",x);
        printf("Postac iloczynowa %d(x-%f)^2\n",a,x);
        printf("Postac kanoniczna jest taka sama\n");
    }
    if (delta>0){
        rozw1=((-b)-pow(delta,1/2))/(2*a);
        rozw2=((-b)+pow(delta,1/2))/(2*a);
        printf("Rownanie ma podwojne rozwiazania %f, %f\n",rozw1,rozw2);
        printf("Postac iloczynowa %d(x-%f)(x-%f)\n",a,rozw1,rozw2);
        int p=((-b)/(2*a));
        float q=(-delta)/(4*a);
        printf("Postac kanoniczna %d(x+(%d)^2+%f\n",a,p,q);
    }
}