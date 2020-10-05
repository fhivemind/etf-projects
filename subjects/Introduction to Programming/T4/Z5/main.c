#include <stdio.h>

int main() {
	/* initial */
	int n, c, _max, _min;
	do {
		printf("Unesite broj: "); scanf("%d", &n);
	} while(n < 0);
	
	/* find numbers */
	_max = n%10;
	_min = n%10;
	n = n/10;
	
	while(n != 0) {
		c = n%10;
		if(c >= _max) _max = c;
		if(c <= _min) _min = c;
		n=n/10;
	}
	
	printf("Najveca cifra je %d a najmanja je %d.", _max, _min);
	
	return 0;
}
