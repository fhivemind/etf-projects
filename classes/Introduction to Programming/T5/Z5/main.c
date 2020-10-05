#include <stdio.h>

#define leftB 0
#define rightB 100

int main() {
	/* initial */
	int t[rightB+1] = {0}, num, i;
	
	/* input */
	printf("Unesite brojeve: ");
	do {
		scanf("%d", &num);
		if((num < leftB || num > rightB) && num != -1) {
			printf("\nBrojevi moraju biti izmedju %d i %d!", leftB, rightB);
		}
		else if(num != -1) 
			t[num]++;
	} while (num != -1);
	
	/* output */
	for(i = leftB; i <= rightB; i++) 
		if(t[i] > 0)
			printf("\nBroj %d se javlja %d puta.", i, t[i]);
	return 0;
}
