#include <stdio.h>
#define MAX 100

/* function to check validity of numbers */
int brojCifre(int broj) {
	int temp = broj;
	int zadnja, c;
	
	if(temp < 0) temp = -temp;
	if(temp > 9) {
		zadnja = temp%10;
		temp = temp/10;
	}
	else return 1;
	while(temp > 0) {
		c = temp % 10;
		if(zadnja != c) return 0;
		zadnja = c;
		temp = temp/10;
	}
	return 1;
}


/* function to sort */
void preslozi(int niz[], int SIZE) {
	int i, j, k;
	int broj;
	
	for(i = 0; i < SIZE-1; i++) {
		/* found number not on place */
		if(brojCifre(niz[i]) == 0) {
			/* search for a swapping number */	
			for(j = i+1; j < SIZE; j++) {
				/* found it */
				if(brojCifre(niz[j]) == 1) {
					/* swap and shift */
					broj = niz[j];
					for(k = j; k > i; k--) 
						niz[k] = niz[k-1];
					niz[i] = broj;
					break;
				}
			}
		}
	}
}

int main() {
	/* initial */
	int niz[MAX], SIZE = 0, i, num;
	
	/* input */
	printf("Unesite brojeve:\n");
	do {
		scanf("%d", &num);
		if(num == -1 || SIZE >= MAX) break;
		niz[SIZE++] = num;
	} while(1);
	
	/* function call */
	preslozi(niz, SIZE);
	
	/* output */
	printf("Nakon poziva funkcije niz glasi:\n");
	for(i = 0; i < SIZE-1; i++) 
		printf("%d,",niz[i]);
	
	/* play with the last number */	
	if(SIZE >= 1) printf("%d.", niz[SIZE-1]);
	
	return 0;
}
