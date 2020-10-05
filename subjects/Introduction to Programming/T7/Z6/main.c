#include <stdio.h>

/* function */
long pascal(int x, int y) {
	if(x == 1 || y == 1)
		return 1;
	else if(x > y && y > 1)
		return (pascal(x-1, y) + pascal(x-1, y-1));
	else if(x==y)
		return 1;
	else
		return 0;
}

int main() {
	/* input */
	int i, j, n;
	do {
		printf("Unesite n: "); scanf("%d", &n);
	} while(n < 1);
	/* output */
	for(i = 0; i <= n; i++) {
		for(j = 1; j <= i; j++) { 
			printf("%-4ld", pascal(i, j));
		}
		printf("\n");
	}
	return 0;
}