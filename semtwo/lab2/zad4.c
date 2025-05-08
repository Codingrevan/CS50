#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    if(argc > 3 || argc < 3){
        printf("Należy podać 3 argumenty na wejściu!\n");
        return 0;
    }
    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);
    int len;
    if(len1 > len2)
        len = len1;
    else
        len = len2;
    char nap_1[len + 1];
    char nap_2[len + 1];
    int i, j;
    for(i = 0; i < len; i++)
        nap_1[i] = argv[1][i];
    nap_1[i] = '\0';
    for(j = 0; j < len; j++)
        nap_2[j] = argv[2][j];
    nap_2[j] = '\0';
    printf("A --> napis_1 = %s napis_2 = %s\n", nap_1, nap_2);
    char tmp;
    for(int w = 0; w < len; w++){
        tmp = nap_1[w];
        nap_1[w] = nap_2[w];
        nap_2[w] = tmp;
    }
    printf("B --> napis_1 = %s napis_2 = %s\n", nap_1, nap_2);
    return 0;
}