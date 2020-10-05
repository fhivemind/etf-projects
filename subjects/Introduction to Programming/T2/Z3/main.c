#include <stdio.h>

int main() {
	
	/* input */
	int day, month;
	printf("Dan: "); scanf("%d", &day);
	printf("Mjesec: "); scanf("%d", &month);
	
	/* validity check (not optimised) */
	if(month > 12 || month < 1 || day > 31 || day < 1) {
		printf("Pogresan unos.\n");
		return 0;
	}
	
	/* calculate */
	printf("Vas znak je ");
	switch(month) {
		case 1: 
			if(day <= 19) printf("Jarac");
			else printf("Vodolija");
			break;
		case 2:
			if(day <= 18) printf("Vodolija");
			else printf("Ribe");
			break;
		case 3:
			if(day <= 20) printf("Ribe");
			else printf("Ovan");
			break;
		case 4:
			if(day <= 19) printf("Ovan");
			else printf("Bik");
			break;
		case 5: 
			if(day <= 20) printf("Bik");
			else printf("Blizanci");
			break;
		case 6: 
			if(day <= 20) printf("Blizanci");
			else printf("Rak");
			break;
		case 7:
			if(day <= 22) printf("Rak");
			else printf("Lav");
			break;
		case 8: 
			if(day <= 22) printf("Lav");
			else printf("Djevica");
			break;
		case 9:
			if(day <= 22) printf("Djevica");
			else printf("Vaga");
			break;
		case 10: 
			if(day <= 22) printf("Vaga");
			else printf("Skorpija");
			break;
		case 11:
			if(day <= 21) printf("Skorpija");
			else printf("Strijelac");
			break;
		case 12:
			if(day <= 21) printf("Strijelac");
			else printf("Jarac");
			break;
	}
	printf("!");
	
	return 0;
}
