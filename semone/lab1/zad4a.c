#include <stdio.h>

int main(void){
    int counter=0;
    for (int i=-123;i<=89;i++)
    {
        if ((i % 5 == 0) && !(i % 3 == 0))
        {
            printf("%d\n",i);
            counter++;
        }
    }
    printf("Takich liczb jest: %d\n",counter);
}