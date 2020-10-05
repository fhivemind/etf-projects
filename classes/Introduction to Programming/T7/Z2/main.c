#include <stdio.h>

/* recursive function */
long int faktorijel(int n) {
	int i = 2;
	long int rez = 1;
	for(i = 2; i <= n; i++)
		rez *= i;
	return rez;
}

int main() {
	/* initial */
	int n, i, _test;
	double x, suma;
	/* input */
	do {
		printf("Unesite broj n u intervalu [1, 12]: "); 
		scanf("%d", &n);
		if((_test = (n < 1 || n > 12)))
			printf("Greska!");
	} while(_test);
	printf("Unesite realan broj x: "); scanf("%lf", &x);
	/* count */
	suma = x;
	for(i = 2; i <= n; i++) 
		suma += ((double)x/faktorijel(i));
	/* output */
	printf("Suma od 1 do %d za x = %.3f je %.3f", n, x, suma);
	return 0;
}
