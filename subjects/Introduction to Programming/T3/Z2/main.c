#include <stdio.h>
#define INF 999999

int main() {
	int broj=0, suma;
	for(suma=0; suma <= 100; suma += broj)
		scanf("%d", &broj);
	printf("%d\n", suma);
	return 0;
}
