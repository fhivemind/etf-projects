#include <stdio.h>

#define SIZE 10

/* print header function */
void header() {
	int i;
	printf("%3c |", 'X');
	for(i = 1; i <= SIZE; i++) {
		printf("%4d", i);	
	}
	printf("\n");
	for(i = 0; i <= SIZE; i++) {
		if(i == 1) printf("+");
		printf("----");
	}
	printf("\n");
}

int main() {
	/* initial */
	int i, j;
	/* print */
	header();
	for(i = 1; i <= SIZE; i++) {
		printf("%3d |", i);
		for(j = 1; j <= SIZE; j++) {
			printf("%4d", i*j);
		}
		printf("\n");
	}
	return 0;
}
