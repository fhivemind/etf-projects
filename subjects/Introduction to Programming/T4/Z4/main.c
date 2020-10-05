#include <stdio.h>

int main() {
	/* initial */
	int m, y;
	printf("Unesite mjesec: "); scanf("%d", &m);
	printf("Unesite godinu: "); scanf("%d", &y);
	
	/* test */
	if(y < 1 || m > 12 || m < 1) {
		printf("Pogresan unos.");
		return 0;
	}
	
	/* calculate */
	switch(m) {
		case 1: printf("Januar %d, broj dana: 31", y); break;
		case 2: 
			if(y%400==0 || (y%100!=0 && y % 4 == 0)) printf("Februar %d, broj dana: 29", y);
			else printf("Februar %d, broj dana: 28", y);
		break;
		case 3: printf("Mart %d, broj dana: 31", y); break;
		case 4: printf("April %d, broj dana: 30", y); break;
		case 5: printf("Maj %d, broj dana: 31", y); break;
		case 6: printf("Juni %d, broj dana: 30", y); break;
		case 7: printf("Juli %d, broj dana: 31", y); break;
		case 8: printf("Avgust %d, broj dana: 31", y); break;
		case 9: printf("Septembar %d, broj dana: 30", y); break;
		case 10: printf("Oktobar %d, broj dana: 31", y); break;
		case 11: printf("Novembar %d, broj dana: 30", y); break;
		case 12: printf("Decembar %d, broj dana: 31", y); break;
	}
	
	return 0;
}
