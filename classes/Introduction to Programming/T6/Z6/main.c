#include <stdio.h>
#define M_SIZE 100

/* check element location */
int okolina(int x, int SIZE) {
	if(x == 0 || x == SIZE) return 1;
	else return 0;
}

int main() {
	/* initial */
	double M[M_SIZE][M_SIZE], _SUM = .0;
	int A, B, i, j;
	/* input */
	printf("Unesite dimenzije matrice: "); 
	do
		scanf("%d %d", &A, &B);
	while (A < 0 || A > M_SIZE || B < 0 || B > M_SIZE);
	/* scan matrix */
	printf("Unesite elemente matrice: ");
	for(i = 0; i < A; i++) {
		for(j = 0; j < B; j++) {
			scanf("%lf", &M[i][j]);
			/* check sum */
			if(okolina(i, A-1) || okolina(j, B-1)) 
				_SUM += M[i][j];
		}
	}
	/* output */
	printf("Suma elemenata na rubu je %.2f", _SUM);
	return 0;
}
