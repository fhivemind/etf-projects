#include <stdio.h>

int main() {
	/* initial */
	double a, b, c, d;
	printf("Unesite brojeve a,b,c,d: "); scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	
	/* check validty */
	if(a > b || c > d) {
		printf("Nepostojeci interval.");
		return 0;
	}
	
	/* S1 A S2 */
	if(b < c || d < a) 
		printf("Skupovi se ne sijeku.\n");
	else if(c <= a && b >= d && a < d)
		printf("Rezultantni interval je [%g,%g].\n", a, d);
	else if(a <= c && d >= b && c < b) 
		printf("Rezultantni interval je [%g,%g].\n", c, b);
	else if(c <= a && b <= d)
		printf("Rezultantni interval je [%g,%g].\n", a, b);
	else
		printf("Rezultantni interval je [%g,%g].\n", c, d);
	return 0;
}
