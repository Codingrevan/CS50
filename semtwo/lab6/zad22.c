#include <stdio.h>

int main(void){
    char *c[] = {"HOOD", "LATE", "RING", "BABY"};
    char **cp[] = {c + 3, c + 2, c + 1, c};
    char ***cpp = cp;
    printf("%s ", **++cpp);
    printf("%s ", *--*--cpp);
    --*cpp;
    printf("%lld ", *cpp - c + 2);
    printf("%s", cpp[3][2]+1);
    for(int i = sizeof(c)/sizeof(*c); i > 0; i--)
        printf("%s ", *cp[i-1]);
    return 0;
}