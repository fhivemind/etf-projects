#include <stdio.h>
#include <math.h>
#define PI 3.14159265

double poz(double x) {
	if(x < 0) return -x;
	else return x;
}

int main() {
	/* initial */
	double a,b,c,R,H,P,V,P_K;
	
	/* input */
	printf("Unesite stranice kvadra (a,b,c)="); scanf("%lf,%lf,%lf", &a, &b, &c);
	printf("Unesite parametre valjka (R,H)="); scanf("%lf,%lf", &R, &H);
	
	/* validity check */
	if(a<=0 || b<=0 || c<=0 || R<=0 || H < 0) {
		printf("Pogresan unos!");
		return 0;
	}
	
	/* calculation */
	P_K = R*R*PI;
	R *= 2; /* pretpostavlja se da korisnik unosi poluprecnik valjka */
	
	P = a*b + 2*(a*c + b*c) + R*H*PI + P_K + poz(P_K - a*b);
	V = a*b*c + P_K*H;
	
	/* output */
	printf("Povrsina tijela sa date slike je %.3f cm2.\n", P);
	printf("Zapremina tijela sa date slike je %.3f cm3.", V);
	return 0;
}
