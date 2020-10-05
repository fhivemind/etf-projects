#include <stdio.h>
#define SIZE 10
int main() {
	/* initial */
	int A[SIZE][SIZE], i, j, temp;
	
	/* create variables to save location of min-max elements */
	int min[2] = {0}, max[2] = {0};
	
	/* input */
	printf("Unesite elemente matrice: "); 
	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE; j++) {
			scanf("%d", &A[i][j]);
			if(A[i][j] < A[min[0]][min[1]]) {
				min[0] = i;
				min[1] = j;
			}
			if(A[i][j] > A[max[0]][max[1]]) {
				max[0] = i;
				max[1] = j;
			}
		}
	}
	/* output */
	if(min[0] == max[0])
		printf("Najmanji i najveci element se nalaze u istom redu.");
	else {
		/* swap rows */
		for(j = 0; j < SIZE; j++) {
			temp = A[min[0]][j];
			A[min[0]][j] = A[max[0]][j];
			A[max[0]][j] = temp;
		}
		/* print matrix */
		printf("Nakon zamjene matrica glasi: \n");
		for(i = 0; i < SIZE; i++) {
			for(j = 0; j < SIZE; j++) 
				printf("%d ", A[i][j]);
			printf("\n");
		}
	}
	return 0;
}
