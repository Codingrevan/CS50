#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_i(int a, int b){
        return (a + rand() % (b - a + 1));
}

void print_tab2d_all(int y, int a[][y], int x);

int main(void){
    srand(time(NULL));
    int rows = rand_i(3, 7);
    int columns = rand_i(3, 7);
    int rows_new = rand_i(3, 7);

    int **tab_1 = calloc(rows, sizeof(int*));
    if(tab_1 == NULL){
        printf("Za mało pamięci na stercie!\n");
        exit(1);
    }
    for(int i = 0; i < rows; i++){
        tab_1[i] = calloc(columns, sizeof(int));
        if (tab_1[i] == NULL){
            printf("Za mało pamięci na stercie!\n");
            exit(1);
        }
    }
    printf("tab_1:\nPRZED:\n\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            tab_1[i][j] = rand_i(1, 15);
            printf ("%3d", tab_1[i][j]);
        }
        printf ("\n");
    }
    printf("\n");
    if(rows_new > rows){
        tab_1 = realloc(tab_1, rows_new * sizeof(int*));
        for(int i = rows; i < rows_new; i++)
            tab_1[i] = malloc(columns * sizeof(int));
        for(int i = rows; i < rows_new; i++)
            for(int j = 0; j < columns; j++)
                tab_1[i][j]=rand_i(-15,-1);   
    }
    if(rows_new < rows){
        for(int i = rows_new; i < rows; i++)
            free(tab_1[i]);
        tab_1 = realloc(tab_1,rows_new * sizeof(int*));
    } 
    printf("tab_1:\nPO:\n\n");
    for(int i = 0; i < rows_new; i++){
        for(int j = 0; j < columns; j++)
            printf ("%3d", tab_1[i][j]);
        printf ("\n");
    }
    printf("\n");
    for(int i = 0; i < rows_new; i++)
        free(tab_1[i]);
    free(tab_1);

    int **tab_2 = calloc(rows, sizeof(int*));
    if (tab_2 == NULL){
        printf("Za mało pamięci na stercie!\n");
        exit(1);
    }
    tab_2[0] = calloc(rows * columns, sizeof(int));
    if (tab_2[0] == NULL){
        printf("Za mało pamięci na stercie!\n");
        exit(1);
    }
    for(int i = 1; i < rows; i++)
        tab_2[i] = tab_2[i - 1] + columns;
    printf("tab_2:\nPRZED:\n\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            tab_2[i][j] = rand_i(1,15); 
            printf ("%3d", tab_2[i][j]);
        }
        printf ("\n");
    }
    printf("\n");
    printf("tab_2:\nPO:\n\n");
    if(rows_new > rows){
        tab_2 = realloc(tab_2, rows_new * sizeof(int*));
        tab_2[0] = realloc(tab_2[0], columns * rows_new * sizeof(int));
        for(int i = 1; i < rows_new ;i++)
            tab_2[i] = tab_2[i - 1] + columns;
        for(int i = rows; i < rows_new; i++)
            for(int j = 0; j < columns; j++)
                tab_2[i][j] = rand_i(-15,-1);
    }
    else if(rows_new < rows){
        tab_2 = realloc(tab_2, rows_new * sizeof(int*));
        tab_2[0] = realloc(tab_2[0], columns * rows_new * sizeof(int));
        for(int i = 1; i < rows_new; i++)
            tab_2[i] = tab_2[i - 1] + columns;
    }
    for(int i = 0; i < rows_new; i++){
        for(int j = 0; j < columns; j++) 
            printf ("%3d", tab_2[i][j]);
        printf ("\n");
    }
    printf("\n");
    free(tab_2[0]);
    tab_2[0] = NULL;
    free(tab_2);
    tab_2 = NULL;

    int (*tab_3)[columns] = calloc(rows * columns, sizeof(int));
    if (tab_3 == NULL){
        printf("Za mało pamięci na stercie!\n");
        exit(1);
    }
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            tab_3[i][j] = rand_i(1,15);
    printf("tab_3:\nPRZED:\n\n");
    print_tab2d_all(columns, tab_3, rows);
    printf("\n");
    printf("tab_3:\nPO:\n\n");
    tab_3 = realloc(tab_3, rows_new * columns * sizeof(int));
    for(int i = rows; i < rows_new; i++)
        for(int j = 0; j < columns; j++)
            tab_3[i][j] = rand_i(-15,-1);
    print_tab2d_all(columns, tab_3, rows_new);
    printf("\n");
    free(tab_3);
    tab_3 = NULL;

    return 0;
}

void print_tab2d_all(int y, int a[][y], int x){
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < y; j++)
            printf ("%3d", a[i][j]);
        printf ("\n");
    }
    return;
}