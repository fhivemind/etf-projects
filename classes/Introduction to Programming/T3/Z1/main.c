#include <stdio.h>
#define INF 999999


int main() {
	int i=0,broj, suma=0;
	while(suma <= 100) {
		scanf("%d", &broj);
		suma+=broj;
		if(i++ >= INF) break;
	}
	printf("%d\n", suma);
	return 0;
}
