#include <stdio.h>
#include <stdlib.h>

int* fun_1(int* t_1, int* t_2, int n1, int n2, int* nw);

int main(void){
    int arg_1[] = {10, 12, 12, 15, 15, 15, 16, 16, 18, 19};
    int arg_2[] = {10, 11, 11, 12, 14, 15, 16, 16 ,18, 18, 18, 19, 19, 20, 20};
    int n1 = sizeof(arg_1) / sizeof(int);
    int n2 = sizeof(arg_2) / sizeof(int);
    printf("arg_1[] = ");
    for(int i = 0; i < n1; i++)
		(i + 1 != n1) ? printf("%d, ", arg_1[i]) : printf("%d\n", arg_1[i]);
    printf("arg_2[] = ");
    for(int i = 0; i < n2; i++)
		(i + 1 != n2) ? printf("%d, ", arg_2[i]) : printf("%d\n", arg_2[i]);
    int nw = 0;
    int* wynik = fun_1(arg_1, arg_2, n1, n2, &nw);
    printf("wynik -> ");
    for(int i = 0; i < nw; i++)
		(i + 1 != nw) ? printf("%d, ", wynik[i]) : printf("%d\n", wynik[i]);
	free(wynik);
	wynik = NULL;
    return 0;
}

int* fun_1(int* t_1, int* t_2, int n1, int n2, int* nw){
    int* wynik = NULL;
    int c1 = 0, c2 = 0, value, flag = 0;
    for(int i = 0; i < n1 + n2; i++){
        if(c1 < n1 && c2 < n2){
            if(t_1[c1] < t_2[c2])
                value = t_1[c1++];
            else
                value = t_2[c2++];
        }
        else if(c1 < n1)
            value = t_1[c1++];
        else
            value = t_2[c2++];
        for(int j = 0; j < *nw; j++){
            if(wynik[j] == value)
                flag = 1;
        }
        if(flag != 1){
            wynik = realloc(wynik, (*nw + 1) * sizeof(int));
            if(!wynik){
                printf("Za mało pamięci na stercie!\n");
                exit(1);
            }
            wynik[*nw] = value;
            (*nw)++;
        }
        flag--;
    }
    return wynik;
}
