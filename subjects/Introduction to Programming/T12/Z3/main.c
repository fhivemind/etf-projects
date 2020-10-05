#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *ulaz;
	int index, type, grade, predmet, _passed = 0, _all = 0, _sGrade = 0;
	float prosjek = .0, prolaznost = .0; 
	
	ulaz = fopen("ispiti.txt", "r");
    if (ulaz == NULL) {
        printf ("Pogreska kod otvaranja datoteke 'ispiti.txt'!\n\n");
        exit (1);
    }
    
    printf("Unesite predmet: "); scanf("%d", &predmet);
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
		printf("Zalimo, ali ne postoje podaci o predmetu sa brojem %d!", predmet);
	fclose (ulaz);
	return 0;
}
