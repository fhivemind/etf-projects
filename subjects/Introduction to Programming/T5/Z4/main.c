#include <stdio.h>

int main() {
	/* initial */
	int _div[3] = {0,0,0};
	int i, num;
	
	/* input */
	printf("Unesite brojeve: ");
	do {
		scanf("%d", &num);
		if(num%5==0) _div[0]++;
		if(num%7==0) _div[1]++;
		if(num%11==0) _div[2]++;
	} while(num!=-1);
	
	/* output */
	printf("\nDjeljivih sa 5: %d\n", _div[0]);
	printf("Djeljivih sa 7: %d\n", _div[1]);
	printf("Djeljivih sa 11: %d\n", _div[2]);
	
	
	
	return 0;
}
