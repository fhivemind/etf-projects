#include <stdio.h>

#define leftB -10
#define rightB 10

int checkLimit(double x) {
	if(x >= leftB && x <= rightB)
		return 1;
	else return 0;
}

int main() {
	
	/* initial */
	double a, b, c, x, _x;
	printf("Unesite koeficijente a, b i c: "); scanf("%lf %lf %lf", &a, &b, &c);
	
	/* check validity */
	if(!checkLimit(a) || !checkLimit(b) || !checkLimit(c)) {
		printf("Koeficijenti a, b i c nisu u zadanom rasponu.\n");
		return 0;
	}
	else {
		printf("Unesite tacku x: "); scanf("%lf", &x);
		_x = 2*a*x + b;
		printf("Prva derivacija u tacki x=%g je %g.\n", x, _x);
	}
	return 0;
}
