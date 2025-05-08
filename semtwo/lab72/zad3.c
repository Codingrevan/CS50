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
    int (*tab_3)[columns] = calloc(rows * columns, sizeof(int));
    if(tab_3 == NULL){
    	printf("Za mało pamięci na stercie!\n");
    	exit(1);
    }
	printf("tab_3:\nPRZED ZMIANAMI\n\n");
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			tab_3[i][j] = i;
			printf("tab_3[%d][%d] = %d ", i, j, tab_3[i][j]);
		}
		printf("\n");
	}
	tab_3 = realloc(tab_3, rows_new * columns * sizeof(int));
	if(tab_3 == NULL){
    	printf("Za mało pamięci na stercie!\n");
    	exit(1);
    }
    if(rows_new > rows){
    	for(int i = rows; i < rows_new; i++)
        	for(int j = 0; j < columns; j++)
        		tab_3[i][j] = i;
    }
    printf("\ntab_3:\nPO ROWS_NEW\n\n");
    for(int i = 0; i < rows_new; i++){
    	for(int j = 0; j < columns; j++)
        	printf("tab_3[%d][%d] = %d ", i, j, tab_3[i][j]);
	    printf("\n");
    }
	tab_3 = realloc(tab_3, rows_new * columns_new * sizeof(int));
	if(tab_3 == NULL){
    	printf("Za mało pamięci na stercie!\n");
    	exit(1);
    }
    if(columns_new > columns){
    	for(int i = 0; i < rows_new; i++)
        	for(int j = 0; j < columns_new; j++)
        		tab_3[i][j] = i;
    }
	if(columns_new < columns){
    	for(int i = 0; i < rows_new; i++)
        	for(int j = 0; j < columns_new; j++)
        		tab_3[i][j] = i;
	}
	printf("\ntab_3:\nPO COLUMNS_NEW\n\n");
    for(int i = 0; i < rows_new; i++){
    	for(int j = 0; j < columns_new; j++)
        	printf("tab_3[%d][%d] = %d ", i, j, tab_3[i][j]);
	    printf("\n");
    }
    free(tab_3);
	return 0;
}
