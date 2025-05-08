#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *fun_1(int *t_1, int *t_2, int n, int m, int *k ){
    int i=0, j=0;
    int *tab=malloc((++(*k))*sizeof(int));
    int *tab1;
    if(*t_1<=*t_2){
        *tab = *t_1;
        i++;
    } else{
        *tab = *t_2;
        j++;
    }
    while(i<n&&j<m){
        while(t_1[i]==*(tab+(*k)-1) && i<n)
            i++;
        while(t_2[j]==*(tab+(*k)-1)&&j<m)
            j++;
        if(i<n&&j<m){
            tab1 = realloc(tab,(++(*k))*sizeof(int));
            if(!tab1){
                return NULL;
            }
            tab=tab1;
            if(t_1[i]<=t_2[j]){
                tab[(*k)-1]=t_1[i];
                i++;
            } else{
                tab[(*k)-1] = t_2[j];
                j++;
            }
        }
    }
    if(i==n){
        while(j<m){
            while(t_2[j]==*(tab+(*k)-1)&&j<m)
                j++;
            if(j<m){
                tab1=realloc(tab,(++(*k))*sizeof(int));
                if(!tab){
                    return NULL;
                }
                tab=tab1;
                tab[(*k)-1]=t_2[j];
            }
        }
    } else{
        while(i<n){
            while(t_1[i]==*(tab+(*k)-1)&&i<n)
                i++;
            if(i<n){
                tab1=realloc(tab,(++(*k))*sizeof(int));
                if(!tab){
                    return NULL;
                }
                tab=tab1;
                tab[(*k)-1]=t_1[i];
            }
        }
    }
    return tab;
}
void wypisz_i (int *poczatek, int *koniec) {
    while(poczatek < koniec){
        printf ("%4d ", *poczatek++);
    }
    printf ("\n");
    return;
}


int main(){
    srand(time(NULL));
    int k=0;
    int arg_1[] = {10, 12, 12, 15, 15, 15, 16, 16, 18, 19};
    int arg_2[] = {10, 11, 11, 12, 14, 15, 16, 16, 18, 18, 18, 19, 19, 20, 20};
    wypisz_i(arg_1,arg_1+10);
    wypisz_i(arg_2,arg_2+15);
    int *arg_3 = fun_1(arg_1,arg_2,10,15,&k);
    wypisz_i(arg_3,arg_3+k);
    free(arg_3);
    arg_3 = NULL;
}
