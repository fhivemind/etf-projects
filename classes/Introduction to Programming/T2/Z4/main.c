#include <stdio.h>

#define leftB 50
#define rightB 200

/* check limit */
int checkLimit(int num) {
	if(num >= leftB && num <= rightB)
		return 1;
	else 
		return 0;
}

/* min and max func */
int min(int x, int y) {
	return (x < y ? x : y);
}

int max(int x, int y) { 
	return (x > y ? x : y);
}

/* main */
int main() {
	/* initial */
	int a, b, c, _min, _max, _mid, diff = 3;
	printf("Unesite tri broja: "); scanf("%d %d %d", &a, &b, &c);
	
	/* check limits */
	if(checkLimit(a) == 0 || checkLimit(b) == 0 || checkLimit(c) == 0) {
		printf("Svi brojevi nisu iz intervala %d do %d", leftB, rightB);
	}
	else {
		_max = max(max(a, b), c);
		_min = min(min(a, b), c);
		_mid = a + b + c -_max - _min;
		if(a == b) diff--;
		if(a == c) diff--;
		if(b == c) diff--;
		printf("Brojevi poredani po velicini glase: %d,%d,%d\n", _min, _mid, _max);
		if(diff != 0)
			printf("Unesena su %d razlicita broja\n", diff);
		else 
			printf("Unesen je 1 razlicit broj");
	}
	return 0;
}
