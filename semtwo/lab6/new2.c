#include <stdio.h>
#include<stdlib.h>

int main(void){ 
    float v1 = 1.5;
    float v2 = 2.5;
    float v3 = 3.5;
    float tab1[] = {-1.5, -2.5, -3.5};
    float tab3[3][6] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4}, {1, 2, 3}};
    
    float* a;
    float b;
    float *c;
    float (*d)[3];
    float (*f)[3];
    float g;
    float *h;
    float (*i)[6];
    float (**j)[6];
    a = &v1;
    b = *a;
    c = tab1;
    d = &tab1;
    float e[3]= {v1, v2, v3};
    f = &e;
    g = *(*(tab3 + 1) - 3);
    h = *(tab3 + 1) - 3;
    i = tab3 + 1;
    j = &i;
    return 0;
}