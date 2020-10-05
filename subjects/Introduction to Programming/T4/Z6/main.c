#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
	/* initial */
	int br, n;
	srand(time(NULL));
	br = rand()%101 + 1; /* generate between [1-100] */
	printf("Izabrao sam broj. Probaj ga pogoditi (-1 za izlaz)\n");
	n = 0;
	do {
		printf("Unesite broj: "); scanf("%d", &n);
		if(n == -1) break;
		else if(n > br) printf("MANJI");
		else if(n < br) printf("VECI");
		else {
			printf("JEDNAK");
			n = -1;
		}
	} while(n != -1);
	
	printf("Kraj igre.");
	return 0;
}
