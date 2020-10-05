#include <stdio.h>
#include <stdlib.h> /* Zbog funkcije exit() */
#include <ctype.h>

int isVow(char c) {
	char vows[5] = {'A', 'E', 'I', 'O', 'U'};
	int i;
	for(i = 0; i < 5; i++) {
		if(toupper(c) == vows[i])
			return 1;
	}
	return 0;
}


int main() {
    FILE *ulaz;
    char znak, ime[20];
    int broj_redova=0, broj_rijeci=0, broj_znakova=0, razmak=1;
    
    int _vow = 0, _nums = 0, _upps = 0;
    
    printf ("Unesite ime datoteke: ");
    scanf ("%s", ime);
    ulaz = fopen(ime, "r");
    if (ulaz == NULL) {
        printf ("Pogreska kod otvaranja datoteke %s!\n\n", ime);
        exit (1);
    }
    while ((znak=fgetc(ulaz)) != EOF) {
        if (znak=='\n')
            ++broj_redova;
        if (znak==' ' || znak=='\n' || znak=='\t')
            razmak=1;
        else {
        	if(isVow(znak)) _vow++;
        	if(isupper(znak)) _upps++;
        	if(isdigit(znak)) _nums++; 
        	
        	
            ++broj_znakova;
            if (razmak==1) ++broj_rijeci;
            razmak=0;
        }
    }
    if (broj_znakova != 0) broj_redova++;
    printf ("Broj redova: %d\nBroj rijeci: %d\nBroj znakova: %d\nBroj samoglasnika: %d\nBroj velikih slova: %d\nBroj cifara: %d", broj_redova, broj_rijeci, broj_znakova, _vow, _upps, _nums);
    fclose (ulaz);
    return 0;
}