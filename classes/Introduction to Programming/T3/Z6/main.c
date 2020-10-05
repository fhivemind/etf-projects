#include <stdio.h>
#include <math.h>

/* is prime */
int _prime(int n) {
	int check = 1, i = 0;
	for(i = 2; i <= sqrt(n); i++)
	{		
		if(n%i == 0) {
			check = 0;
			break;
		}
	}
	return check;
}


int main() {
	/* initial */
	int n;
	printf("Unesite broj: "); scanf("%d", &n);
	
	/* check */
	if(n <= 0) printf("Broj nije prirodan.");
	else if(n == 1) printf("Broj nije ni prost ni slozen.");
	else if(_prime(n)==0) printf("Broj je slozen.");	/* manje iteracija za provjeru slozenog broja */
	else printf("Broj je prost.");

	return 0;
}
