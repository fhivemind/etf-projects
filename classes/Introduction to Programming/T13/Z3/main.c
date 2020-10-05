#include <stdio.h>
#include <stdlib.h> /* Zbog funkcije exit() */
struct Student {
    char prezime[20];
    char ime[15];
    int  broj_bodova1;
    int  broj_bodova2;
};

/* unos */
void unesi(char niz[], int velicina) {
	char znak = getchar();
	int i;
	if (znak == '\n') znak=getchar();
	i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

/* prototip */
void unos_clana();
void ispis();

void upis(struct Student student) {
    struct Student studenti[300], tmp;
    FILE *ulaz, *izlaz;
    int i, j, vel;
    /* Otvaranje datoteka */
    	if ((izlaz = fopen("ispit.txt","a")) == NULL) {
        	printf("Greska pri otvaranju datoteke usmeni.txt");
        	exit(1);
    	}	
	fprintf(izlaz,"%-20s%-15s%2d %2d\n", student.prezime, student.ime, student.broj_bodova1, student.broj_bodova2);
	fclose(izlaz);
	
    /* Otvaranje datoteka */
    if ((ulaz = fopen("ispit.txt","r")) == NULL) {
        printf("Greska pri otvaranju datoteke ispit.txt");
        exit(1);
    }
    	if ((izlaz = fopen("usmeni.txt","w")) == NULL) {
        	fclose(ulaz);
        	printf("Greska pri otvaranju datoteke usmeni.txt");
        	exit(1);
    	}
    /* Ucitavanje datoteke u niz studenti */
    i=0;
     while (fscanf(ulaz,"%20s%15s%2d %2d\n", studenti[i].prezime, studenti[i].ime, &studenti[i].broj_bodova1, &studenti[i].broj_bodova2) == 4 && i<300)
        i++;
    vel = i;
    studenti[i] = student;
    vel++;
    
    /* Sortiranje niza po broju bodova */
    for (i=0; i<vel-1; i++) {
        for (j=i+1; j<vel; j++) {
            if ((studenti[j].broj_bodova1+studenti[j].broj_bodova2) > (studenti[i].broj_bodova1+studenti[i].broj_bodova2))  {
                tmp = studenti[i];
                studenti[i] = studenti[j];
                studenti[j] = tmp;
            }
        }
    }
    
    for (i=0; i<vel; i++)
        if((studenti[i].broj_bodova1 >= 10  && studenti[i].broj_bodova2 >= 10))
            fprintf(izlaz,"%-20s%-15s%2d\n", studenti[i].prezime, studenti[i].ime, studenti[i].broj_bodova1+studenti[i].broj_bodova2);

    fclose(ulaz);
    fclose(izlaz);
}

void radi_nesto() {
    int tip;
    do {
    		printf("Unesite 1 za unos, 2 za ispis, 0 za izlaz: "); scanf("%d", &tip);
    		if(tip == 1) unos_clana();
    		else if(tip == 2) ispis();
    		else if(tip == 0) break;
    } while(tip < 0 || tip > 2);
    
}

int main() {
    radi_nesto();
    return 0;
}


void unos_clana() {
	struct Student student;
	printf("Unesite ime: "); unesi(student.ime, 15);
	printf("Unesite prezime: "); unesi(student.prezime, 20);
	do {
	    printf("Unesite broj bodova na I parcijalnom: "); scanf("%d", &student.broj_bodova1);
	} while(student.broj_bodova1 < 0 || student.broj_bodova1 > 20);
	do {
	    printf("Unesite broj bodova na II parcijalnom: "); scanf("%d", &student.broj_bodova2);
	} while(student.broj_bodova2 < 0 || student.broj_bodova2 > 20);
	upis(student);
	radi_nesto();
}

void ispis() {
    FILE *ulaz;
    int i = 0;
	struct Student student;
    if ((ulaz = fopen("ispit.txt","r")) == NULL) {
        printf("Greska pri otvaranju datoteke ispit.txt");
        exit(1);
    }
    i=1;
    printf("\n");
    while (fscanf(ulaz,"%20s%15s%2d %2d\n", student.prezime, student.ime, &student.broj_bodova1, &student.broj_bodova2) == 4 && i<300) {
        printf("%d. %s %s - %-2d, %-2d\n", i, student.ime, student.prezime, student.broj_bodova1, student.broj_bodova2);
        i++;   
    }
	radi_nesto();
}