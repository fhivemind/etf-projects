#include <stdio.h>
#include <math.h>

int main() {
	/* initial */
	double x[2], y[2], z[2], d;
	
	/* input */
	printf("Unesite koordinate tacke T1(x1,y1,z1)="); scanf("%lf,%lf,%lf", &x[0], &y[0], &z[0]);
	printf("Unesite koordinate tacke T2(x2,y2,z2)="); scanf("%lf,%lf,%lf", &x[1], &y[1], &z[1]);
	
	/* calculation */
	d = sqrt(pow(x[1]-x[0], 2) + pow(y[1]-y[0], 2) + pow(z[1]-z[0], 2));
	
	/* output */
	printf("Udaljenost izmedju tacaka T1 i T2 je d=%f", d);
	return 0;
}
