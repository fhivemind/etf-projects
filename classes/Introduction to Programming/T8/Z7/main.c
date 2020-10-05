#include <stdio.h>

/* swap function */
void zamijeni(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	/* initial */
	int a, b;
	scanf("%d %d", &a, &b);
	
	/* swap */
	zamijeni(&a, &b);
	
	/* output */
	printf("%d %d", a, b);
	return 0;
}
