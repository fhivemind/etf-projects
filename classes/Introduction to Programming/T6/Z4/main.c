#include <stdio.h>
#define M_SIZE 10

int main() {
	/* initial */
	int i, A[M_SIZE],j, n, _MEMB;
	char c;
	/* input */
	printf("Unesite elemente niza: ");
	for(i = 0; i < M_SIZE; i++) {
		scanf("%d", &A[i]);
		if(A[i] == -1 || i == M_SIZE-1) {
			n = i + (i == M_SIZE-1? 1:0);
			break;
		}
	}
	printf("Unesite element koji treba izbaciti: "); scanf("%d", &_MEMB);
	/* remove element */
	for(i = 0; i < n; i++) {
		if(A[i] == _MEMB) {
			for(j = i; j < n-1; j++) 
				A[j]=A[j+1];
			n--;
			i--;
		}
	}
	/* output */
	printf("Novi niz glasi: ");
	for(i = 0; i < n; i++) {
		c = (i == n-1 ? '\0':',');
		printf("%d%c", A[i], c);
	}
	return 0;
}
