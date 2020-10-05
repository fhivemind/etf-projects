#include <stdio.h>
#define PI 3.14159265
#define SQR(X)		((X)*(X))
#define READFILE	"geometrija.txt"
#define SAVEFILE	"geometrija-sortirano.txt"

/* definitions of bodies */
struct Kruznica {
	float poluprecnik;
};
struct Trougao {
	float baza;
	float visina;
};
struct Pravougaonik {
	float sirina;
	float visina;
};
struct Tijelo {
	int tip;
	struct Trougao tr;
	struct Kruznica kr;
	struct Pravougaonik pr;
};


/* functions to implement */

/* read function */
int ucitaj(struct Tijelo niz[], int velicina) {
	int SIZE = 0;
	FILE* input;
	char type;
	
	/* temp bodies to save in before dumping in array */
	struct Kruznica circle;
	struct Trougao triangle;
	struct Pravougaonik rect;
	
	if((input = fopen(READFILE, "r")) == NULL) return 0;
	
	/* start reading */
	while(!feof(input) && SIZE < velicina) {
		type = fgetc(input); /* intial type check */
		if(type == 'K') {
			if(fscanf(input, "%f", &circle.poluprecnik) == 1) {
				niz[SIZE].tip = 1;
				niz[SIZE++].kr = circle;
			}
			else break;
		}
		else if(type == 'T') {
			if(fscanf(input, "%f,%f", &triangle.baza, &triangle.visina) == 2) {
				niz[SIZE].tip = 2;
				niz[SIZE++].tr = triangle;
			}
		}	
		else if(type == 'P') {
			if(fscanf(input, "%f,%f", &rect.sirina, &rect.visina) == 2) {
				niz[SIZE].tip = 3;
				niz[SIZE++].pr = rect;
			}
		}
		else break;
		if(ferror(input)) break;
	}
	fclose(input);
	return SIZE;
}

/* povrsina jednog tijela */
float povrsina_tijela(struct Tijelo tijelo) {
	if(tijelo.tip == 1) 
		return (SQR(tijelo.kr.poluprecnik)*PI);
	else if(tijelo.tip == 2)
		return (tijelo.tr.baza*tijelo.tr.visina/2);
	else if(tijelo.tip == 3)
		return (tijelo.pr.sirina*tijelo.pr.visina);
	return 0;
}

/* function to save */
void zapisi(struct Tijelo tijelo[], int SIZE) {
	/* intial */
	int i = 0, j = 0;
	FILE *output;
	struct Tijelo temp;
	
	/* sort array */
	for(i = 0; i < SIZE-1; i++) {
		for(j = i+1; j < SIZE; j++) {
			if(povrsina_tijela(tijelo[j]) > povrsina_tijela(tijelo[i])) {
				temp = tijelo[i];
				tijelo[i] = tijelo[j];
				tijelo[j] = temp;
			}
		}
	}
	
	/* start saving */
	if((output = fopen(SAVEFILE, "w+")) == NULL) return;
	
	/* start writing */
	for(i = 0; i < SIZE; i++) {
		if(tijelo[i].tip == 1) 
			fprintf(output, "Krug %.2f\n", tijelo[i].kr.poluprecnik);
		if(tijelo[i].tip == 2) 
			fprintf(output, "Trougao %.2f %.2f\n", tijelo[i].tr.baza, tijelo[i].tr.visina);
		if(tijelo[i].tip == 3) 
			fprintf(output, "Pravougaonik %.2f %.2f\n", tijelo[i].pr.sirina, tijelo[i].pr.visina);
		if(ferror(output)) break;
	}
	fclose(output);
}

/* cijela povrsina */
float povrsina(struct Tijelo niz[], int SIZE) {
	int i = 0;
	float povrsina = 0;
	
	/* whole function */
	for(i = 0; i < SIZE; i++) 
		povrsina += povrsina_tijela(niz[i]);
	
	return povrsina;
}

int main() {
	
	return 0;
}