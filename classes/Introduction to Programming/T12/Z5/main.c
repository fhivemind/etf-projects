#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unesi(char niz[], int velicina) {
	char znak = getchar();
	int i = 0;
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

/* statistics about course */
void statistikaPredmeta() {
	FILE *ulaz, *predmeti;
	
	char input[150], _test[150], line[250];
	int index, type, grade, predmet, _passed = 0, _all = 0, _sGrade = 0, _set = 0;
	float prosjek = .0, prolaznost = .0; 
	
	
	ulaz = fopen("ispiti.txt", "r");
    if (ulaz == NULL) {
        printf ("Pogreska kod otvaranja datoteke!\n\n");
        exit (1);
    }
	/* find id about the project */
    do {
    	printf("Unesite predmet: "); unesi(input, 150);
    	predmeti = fopen("predmeti.txt", "r");
		if (predmeti == NULL) {
		    printf ("Pogreska kod otvaranja datoteke!\n\n");
		    exit (1);
		}
    	while(fgets(line, sizeof(line), predmeti)) {
	    	if(sscanf(line,"%d %[^\t\n]\n", &predmet, _test) == 2) {
	    		if(strcmp(input, _test) == 0) {
	    			_set = 1;
	    			break;
	    		}
	    	}
    	}
		fclose (predmeti);
    	if(!_set)
    		printf("Nepostojeci predmet!\n");
    }
    while(!_set);
    
    while (fscanf(ulaz,"%d %d %d\n", &index, &type, &grade) == 3) {
		if(type == predmet) {
			_all++;
			if(grade >= 6 && grade <= 10) 
				_passed++;
			_sGrade += grade;
		}
	}
	if(_all > 0) {
		prosjek = (float)_sGrade/_all;
		prolaznost = _passed*100/_all;
		printf("Prosjecna ocjena: %.2f\nProlaznost: %.f%%", prosjek, prolaznost);
	}
	else 
		printf("Zalimo, ali ne postoje podaci o predmetu %s!", input);
	
	fclose (ulaz);
}



int main() {
	int tip;
   	
   	/* check type */
   	printf("Unesite 1 za statistiku studenta, 2 za statistiku predmeta, 0 za izlaz: \n");
   	scanf("%d", &tip);

	return 0;
}
