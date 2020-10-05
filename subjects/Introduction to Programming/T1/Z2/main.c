#include <stdio.h>
#define PI 3.14159265

int main() {
	/* initial */
	float R, P, V, P_L;
	
	/* input */
	printf("Unesite poluprecnik: "); scanf("%f", &R);
	if(R < 0) {
		printf("Pogresan unos!");
		return 0;
	}
	
	/* calculation */
	P = R*R*PI;
	P_L = 4*P;
	V = 4./3*P*R;
	
	/* output */
	printf("Povrsina kruga sa poluprecnikom R=%2f je P=%.2f\n", R, P);
	printf("Povrsina lopte sa poluprecnikom R=%2f je Pl=%.2f\n", R, P_L);
	printf("Zapremina kugle sa poluprecnikom R=%2f je V=%.2f", R, V);
	return 0;
}
