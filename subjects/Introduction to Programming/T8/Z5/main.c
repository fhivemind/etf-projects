#include <stdio.h>
#include <math.h>

void zaokruzi(double *niz, int vel) {
	int i;
	for(i = 0; i < vel; i++) 
		*(niz+i) = round(*(niz+i)*10)/10;
}

int main() {
	return 0;
}
