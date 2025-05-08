#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_i(int a, int b){
	return (a + rand() % (b - a + 1));
}

int main(void){
	srand(time(NULL));
	int rows = rand_i(4, 7);
	int columns = rand_i(4, 7);
	int rows_new = rand_i(2, 8);
	int columns_new = rand_i(2, 8);
	printf("rows = %d columns = %d\nrows_new = %d columns_new = %d\n", rows, columns, rows_new, columns_new);
	int** tab_1 = calloc(rows, sizeof(int*));
	if(tab_1 == NULL){
		printf("Za mało pamięci na stercie!\n");
		exit(1);
	}
	for(int i = 0; i < rows; i++){
    	tab_1[i] = calloc(columns, sizeof(int));
        if(tab_1[i] == NULL){
        	printf("Za mało pamięci na stercie!\n");
			exit(1);
		}
	}
	printf("tab_1:\nPRZED ZMIANAMI\n\n");
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			tab_1[i][j] = i;
			printf("tab_1[%d][%d] = %d ", i, j, tab_1[i][j]);
		}
		printf("\n");
	}
	if(rows_new > rows){
        tab_1 = realloc(tab_1, rows_new * sizeof(int*));
        if(tab_1 == NULL){
        	printf("Za mało pamięci na stercie!\n");
			exit(1);
		}
        for(int i = rows; i < rows_new; i++){
        	tab_1[i] = malloc(columns * sizeof(int));
        	if(tab_1[i] == NULL){
        		printf("Za mało pamięci na stercie!\n");
				exit(1);
			}
		}
        for(int i = rows; i < rows_new; i++)
        	for(int j = 0; j < columns; j++)
        		tab_1[i][j] = i;
    }
    else if(rows_new < rows){
    	for(int i = rows_new; i < rows; i++)
        	free(tab_1[i]);
        tab_1 = realloc(tab_1, rows_new * sizeof(int*));
        if(tab_1 == NULL){
        	printf("Za mało pamięci na stercie!\n");
			exit(1);
		}
    }
    printf("\ntab_1:\nPO ROWS_NEW\n\n");
	for(int i = 0; i < rows_new; i++){
		for(int j = 0; j < columns; j++)
			printf("tab_1[%d][%d] = %d ", i, j, tab_1[i][j]);
		printf("\n");
	}
	if(columns_new > columns){
        for(int i = 0; i < rows_new; i++){
			tab_1[i] = realloc(tab_1[i], columns_new * sizeof(int));
        	if(tab_1[i] == NULL){
        		printf("Za mało pamięci na stercie!\n");
				exit(1);
			}
		}
        for(int i = 0; i < rows_new; i++)
        	for(int j = columns; j < columns_new; j++)
        		tab_1[i][j] = i;
    }
    else if(columns_new < columns){
    	for(int i = 0; i < rows_new; i++){
        	tab_1[i] = realloc(tab_1[i], columns_new * sizeof(int));
        	if(tab_1[i] == NULL){
        		printf("Za mało pamięci na stercie!\n");
				exit(1);
			}
		}
    }
	printf("\ntab_1:\nPO COLUMNS_NEW\n\n");
	for(int i = 0; i < rows_new; i++){
		for(int j = 0; j < columns_new; j++)
			printf("tab_1[%d][%d] = %d ", i, j, tab_1[i][j]);
		printf("\n");
	}
    for(int i = 0; i < rows_new; i++){
    	free(tab_1[i]);
		tab_1[i] = NULL;
    }
    free(tab_1);
    tab_1 = NULL;

    int** tab_2 = calloc(rows, sizeof(int*));
    if(tab_2 == NULL){
        printf("Za mało pamięci na stercie!\n");
		exit(1);
	}
    tab_2[0] = calloc(columns * rows, sizeof(int));
    if(tab_2[0] == NULL){
    	printf("Za mało pamięci na stercie!\n");
		exit(1);
	}
    for(int i = 1; i < rows; i++)
    	tab_2[i] = tab_2[i - 1] + columns;
    printf("\ntab_2:\nPRZED ZMIANAMI\n\n");
    for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			tab_2[i][j] = i;
			printf("tab_2[%d][%d] = %d ", i, j, tab_2[i][j]);
		}
		printf("\n");
	}
   	if(rows_new > rows){
        tab_2 = realloc(tab_2,rows_new * sizeof(int*));
        if(tab_2 == NULL){
        	printf("Za mało pamięci na stercie!\n");
			exit(1);
		}
        tab_2[0] = realloc(tab_2[0], columns * rows_new * sizeof(int));
        if(tab_2[0] == NULL){
        	printf("Za mało pamięci na stercie!\n");
			exit(1);
		}
        for(int i = 1;i < rows_new; i++)
        	tab_2[i] = tab_2[i - 1] + columns;
        for(int i = rows; i < rows_new; i++)
        	for(int j = 0;j < columns;j++)
        		tab_2[i][j] = i;
     }
     else if(rows_new < rows){
        tab_2 = realloc(tab_2, rows_new * sizeof(int*));
        if(tab_2 == NULL){
        	printf("Za mało pamięci na stercie!\n");
			exit(1);
		}
        tab_2[0] = realloc(tab_2[0], columns * rows_new * sizeof(int));
        if(tab_2[0] == NULL){
        	printf("Za mało pamięci na stercie!\n");
			exit(1);
		}
        for(int i = 1; i < rows_new; i++)
       		tab_2[i] = tab_2[i - 1] + columns;
     }
     printf("\ntab_2:\nPO ROWS_NEW\n\n");
     for(int i = 0; i < rows_new; i++){
		 for(int j = 0; j < columns; j++){
			 tab_2[i][j] = i;
			 printf("tab_2[%d][%d] = %d ", i, j, tab_2[i][j]);
		 }
		 printf("\n");
	 }


	 if(columns_new > columns){
        tab_2[0] = realloc(tab_2[0], columns_new * rows_new * sizeof(int));
        if(tab_2[0] == NULL){
        	printf("Za mało pamięci na stercie!\n");
			exit(1);
		}
        for(int i = 1; i < rows_new; i++)
        	tab_2[i] = tab_2[i - 1] + columns_new;
        for(int i = 0; i < rows_new; i++)
        	for(int j = 0; j < columns_new; j++)
        		tab_2[i][j] = i;
     }
     else if(columns_new < columns){
        tab_2[0] = realloc(tab_2[0], columns_new * rows_new * sizeof(int));
        if(tab_2[0] == NULL){
        	printf("Za mało pamięci na stercie!\n");
			exit(1);
		}
        for(int i = 1; i < rows_new; i++){
       		tab_2[i] = tab_2[i - 1] + columns_new;
		}
		for(int i = 0; i < rows_new; i++){
		    for(int j = 0; j < columns_new; j++){
			   tab_2[i][j] = i;
			}
		}
     }
	 printf("\ntab_2:\nPO COLUMNS_NEW\n\n");
     for(int i = 0; i < rows_new; i++){
		 for(int j = 0; j < columns_new; j++){
			 tab_2[i][j] = i;
			 printf("tab_2[%d][%d] = %d ", i, j, tab_2[i][j]);
		 }
		 printf("\n");
	 }
     free(tab_2[0]);
     tab_2[0] = NULL;
     free(tab_2);
     tab_2 = NULL;
	 return 0;
}
