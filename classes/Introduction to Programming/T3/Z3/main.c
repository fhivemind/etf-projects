#include <stdio.h>

/* test if divisible */
int _div(int n, int _t) {
	if(n%_t == 0) return 1;
	else return 0;
}

int main() {
	/* initial */
	int n, i;
	
	/* input */
	printf("Unesite broj n: "); scanf("%d", &n);
	if(n < 1) {
		printf("Pogresan unos.");
		return 0;
	}
	
	/* check */
	for(i = n; i >= 5; i--) 
		if(_div(i,5) || _div(i,7) || _div(i,11))
			printf("%d\n", i);
	
	
	return 0;
}
