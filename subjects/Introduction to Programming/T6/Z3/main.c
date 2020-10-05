#include <stdio.h>
#define M_SIZE 10

int main() {
	/* initial */
	int A[M_SIZE], B[M_SIZE], C[2*M_SIZE], 
		n = 0, i = 0, _test = 0;
	char c;
	/* input */
	printf("Unesite elemente niza A: ");
	do {
		scanf("%d", &A[i]);
		if((_test = (A[i] != -1 && i < M_SIZE))) {
			C[n++] = A[i++];
			_test = i < M_SIZE;
		}
	} while (_test);
	
	i = 0;
	printf("Unesite elemente niza B: ");
	do {
		scanf("%d", &B[i]);
		if((_test = (B[i] != -1 && i < M_SIZE))) {
			C[n++] = B[i++];
			_test = i < M_SIZE;
		}
	} while (_test);
	
	/* output */
	printf("Niz C glasi: ");
	for(i = 0; i < n; i++) {
		c = (i == n-1 ? '\0':',');
		printf("%d%c", C[i], c);
	}
	return 0;
}
