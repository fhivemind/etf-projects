#include <stdio.h>
#include <math.h>

/* function factorial */
double faktorijel(int n) {
	int i = 2;
	double rez = 1.0;
	for(i = 2; i <= n; i++)
		rez *= i;
	return rez;
}

/* function sinus */
double sinus(double x, int n) {
	double value = x;
	int i;
	/* calculate */
	for(i = 2; i <= n; i++) 
		value = value+(pow(-1, i-1)*pow(x, 2*i - 1)/faktorijel(2*i - 1));
	return value;
}

int main() {
	/* input */
	int n;
	double error, x, r_sin, value;
	/* input */
	printf("Unesite x: "); scanf("%lf", &x);
	do {
		printf("\nUnesite n: "); scanf("%d", &n);
	} while(n < 1);
	/* calculate */
	value = sinus(x, n);
	r_sin = sin(x);
	error = fabs(r_sin-value)*100/r_sin;
	/* output */
	printf("\nsin(x)=%g", r_sin);
	printf("\nsinus(x)=%g", value);
	printf("\nRazlika: %f (%.2f%%).", fabs(value-r_sin), error);
	return 0;
}
