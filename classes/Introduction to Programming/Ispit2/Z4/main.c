#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Grad {
	char naziv[20];
	int br_stanovnika;
};
struct Drzava {
	char naziv[20];
	struct Grad gradovi[100];
	int br_gradova;
};


/* function to implement */
int izbaci_duple(struct Grad* gradovi, int velg, struct Drzava* drzave, int veld) {
	/* intial */
	int i, j, k, _exists;
	
	/* start searching for doubles */
	for(i = 0; i < velg; i++) {
		_exists = 0;
		/* go through all the countries and search for given city (ONLY ONCE) */
		for(j = 0; j < veld; j++) {
			for(k = 0; k < drzave[j].br_gradova; k++) {
				/* checking by name */
				if(strcmp(drzave[j].gradovi[k].naziv, gradovi[i].naziv) == 0) {
					_exists++;
					/* no need to continue the search if the city has been found */
					break;
				}
			}
			/* already in two countries, no need to search for more */
			if(_exists >= 2) break;
		}
		
		/* dump from array */
		if(_exists >= 2) {
			for(j = i+1; j < velg; j++) 
				gradovi[j-1] = gradovi[j];
			i--;
			velg--;
		}
	}
	return velg;
}


int main() {
	
	return 0;
}
