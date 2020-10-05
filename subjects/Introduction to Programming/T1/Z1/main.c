#include <stdio.h>
#define PI 3.14159265

int main() {
	/* initial */
	float R, P, V;
	
	/* input */
	printf("Unesite poluprecnik: "); scanf("%f", &R);
	if(R < 0) {
		printf("Pogresan unos!");
		return 0;
	}
	
	/* calculation */
	P = R*R*PI;
	V = 4./3*P*R;
	
	/* output */
	printf("Povrsina kruga sa poluprecnikom R=%2f je P=%.2f\n", R, P);
	printf("Zapremina kugle sa poluprecnikom R=%2f je V=%.2f", R, V);
	return 0;
}
