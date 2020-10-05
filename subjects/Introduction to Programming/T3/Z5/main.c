#include <stdio.h>
#include <math.h>

/* recursion */

double _sum(int i) {
	if(i == 1)
		return 1.0;
	else 
		return (_sum(i-1) + pow(-1, i-1)/i);
	
}

int main() {
	/* initial */
	int n;
	printf("Unesite broj n: "); scanf("%d", &n);
	if(n < 1) return 0;
	
	/* calculate */
	printf("Koristeci %d clanova suma je %.3f.\n", n, _sum(n));
	return 0;
}
