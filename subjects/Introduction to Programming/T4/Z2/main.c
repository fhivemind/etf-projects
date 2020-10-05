#include <stdio.h>

void ispisi(int test) {
	if(test)
		printf("+");
	else
		printf("|");
}

void ispisi_red(int a, int t) {
	int j = 0;
	for(j = 1; j < a-1; j++) {
		if(t)
			printf("-");
		else
			printf(" ");
	}
}

int main() {
	/* initial */
	int a, b, i;
	i = 0;
	printf("Unesite stranice pravougaonika a,b: "); scanf("%d,%d", &a, &b);

	/* print */
	for(i = 0; i < b; i++) {
		int t = (i == 0 || i == b-1);
		ispisi(t);	
		ispisi_red(a, t);
		if(a > 1)
			ispisi(t);
			
		printf("\n");
	}

	return 0;
}
