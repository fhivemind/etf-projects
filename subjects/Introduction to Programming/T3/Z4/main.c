#include <stdio.h>

/* print row */
void row(int r, int n) {
	int i;
	if(r % 2 == 0) printf(" ");
	for(i = 1; i <= n; i++)
		printf("* ");
	printf("\n");
}


int main() {
	/* initial */
	int n, i;
	printf("Unesite broj n: "); scanf("%d", &n);
	if(n < 1) return 0;
	
	/* output */
	for(i = 1; i <= n; i++)
		row(i, n);
	
	return 0;
}
