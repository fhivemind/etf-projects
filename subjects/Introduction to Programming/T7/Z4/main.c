#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function */
int obrnut(int n) {
	int temp = n;
	int reverse = 0;
	while(temp != 0) {
		reverse = reverse*10 + temp%10;
		temp = temp/10;
	}
	if(n < 0) return -reverse;
	else return reverse;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", obrnut(n));
	return 0;
}
