#include <stdio.h>


/* structure person */
struct Osoba {
	char ime[15];
	char prezime[20];
	int telefon;
}





int main() {
	/* initial */
	struct Osoba imenik[100];
	int type;
	printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: "); scanf("%d", &type);
	
	
	return 0;
}
