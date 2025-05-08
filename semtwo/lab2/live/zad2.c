#include <stdio.h>

unsigned bits(unsigned int x, unsigned int n);
void write_binar (unsigned int n, char* wsk);

int main(void){
	unsigned number, result, bit_num;
	scanf("%u",&number);
	scanf("%u",&bit_num);
	if(bit_num < 0 || bit_num > (sizeof(unsigned) * 8)){
		printf("Podałeś nieprawidłową liczbę bitów\n");
		return 1;
	}
	char wsk[sizeof(unsigned) * 8 + 1];
	write_binar(number, wsk);
 	printf("liczba wczytana %d : %s \n", number, wsk);
	result = bits (number,  bit_num);
	write_binar(result, wsk);
    printf("%u nowa liczba : %s\n", result, wsk);
    return 0;
	}

void write_binar(unsigned int n, char* wsk){
	unsigned mask = 1 << (sizeof(unsigned) * 8 - 1);
	int i;
	for(i = 0; i < (sizeof(unsigned) * 8); i++){
		wsk[i] = (n & mask) ? '1' : '0';
		mask >>= 1;
	}
	wsk[i] = '\0';
}

unsigned bits(unsigned int x, unsigned int n){
	unsigned mask = 0xFFFFFFFF;
	/*unsigned mask = 1 << (sizeof(unsigned) * 8 - 1);
	for(int i = 0; i < (sizeof(unsigned) * 8); i++){
		mask = mask + 1;
		mask <<= 1;
	}*/
	
	/*unsigned mask = 0;
	for(int i = 0; i < sizeof(unsigned) * 8; i++){
		mask = mask + 1;
		mask <<= 1;
	}
	*/
	for(int i = 0; i < (sizeof(unsigned) * 8) - n; i++)
		mask <<= 1;
	x = x & mask;
	x = x >> ((sizeof(unsigned) * 8) - n);
	return x;
}
