#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* sortiraj funkcija */
void sortiraj(double *niz, int vel) {
	/* initial */
	int i, j;
	double temp;
	
	/* sort */
	for(i = 0; i < vel-1; i++) {
		for(j = i; j < vel; j++) {
			if(*(niz + i) > *(niz + j)) {
				temp = *(niz + i);
				*(niz + i) = *(niz + j);
				*(niz + j) = temp;
			}
		}
	}
}

int main() {
	/* initial */
	int i;
	double niz[100];
	
	/* generate */
	srand(time(0));
	for(i = 0; i < 100; i++) 
		niz[i] = (double) (rand()%1000);
	
	/* sort */
	sortiraj(niz, 100);
	
	/* output */
	printf("\n");
	for(i = 0; i < 100; i++)
		printf("%g ", niz[i]);
	return 0;
}