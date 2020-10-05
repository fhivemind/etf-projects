#include <stdio.h>
#define M_SIZE 10

int main() {
	/* initial */
	int A[M_SIZE][M_SIZE], i, j, min, _SET = 0;
	
	/* input */
	for(i = 0; i < M_SIZE; i++) {
		for(j = 0; j < M_SIZE; j++) {
			scanf("%d", &A[i][j]);
			if(!_SET) {
				_SET = 1;
				min = A[i][j];
			}
			/* check min */
			else if(i == j && min > A[i][j]) 
				min = A[i][j];
		}
	}
	/* output */
	printf("%d", min);
	return 0;
}
