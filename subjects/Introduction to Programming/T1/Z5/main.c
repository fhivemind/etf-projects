#include <stdio.h>

int main() {
	/* initial */
	double VT, MT, c_VT, c_MT, u_P, u_C;
	int udio_M, udio_V;
	
	/* input */
	printf("Unesite potrosnju VT="); scanf("%lf", &VT);
	printf("Unesite potrosnju MT="); scanf("%lf", &MT);
	printf("Unesite cijenu VT="); scanf("%lf", &c_VT);
	printf("Unesite cijenu MT="); scanf("%lf", &c_MT);
	
	/* validity check */
	if(VT < 0 || MT < 0 || c_VT <= 0 || c_MT <= 0) {
		printf("Pogresan unos!");
		return 0;
	}
	
	/* calculation */
	u_P = VT + MT;
	u_C = VT*c_VT + MT*c_MT;
	if(u_P > 0) {
		udio_V = ((float)(VT/u_P)*100);
		udio_M = 100 - udio_V;
	}
	else {
		udio_M = 0;
		udio_V = 0;
	}
	
	/* output */
	printf("Ukupna potrosnja je %.2f kWh.\n", u_P);
	printf("Udio velike tarife u ukupnoj potrosnji je %d%%.\n", udio_V);
	printf("Udio male tarife u ukupnoj potrosnji je %d%%.\n", udio_M);
	printf("Iznos racuna je %.2f KM.", u_C);
	return 0;
}
