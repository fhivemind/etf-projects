#include <stdio.h>
#define NUM 5

/* global variables */
double A[NUM], B[NUM], C[NUM];

/* input numbers */
void input_num(int type) {
	int i;
	if(type==0) printf("Unesite clanove niza A: ");
	else printf("Unesite clanove niza B: ");
	for(i = 0; i < NUM; i++) {
		if(type==0) {
			scanf("%lf", &A[i]);
			C[i] = 2*A[i];
		}
		else {
			scanf("%lf", &B[i]);
			C[i] += B[i];
		}
	}
}

/* print numbers */
void print_num(int type) {
	int i;
	char niz;
	double k;
	
	if(type == 0) niz = 'A';
	else if(type == 1) niz = 'B';
	else niz = 'C';
	printf("Niz %c glasi: ", niz);
	
	for(i = 0; i < NUM; i++) {
		if(type == 0) k = A[i];
		else if(type == 1) k = B[i];
		else k = C[i];
		printf("%.2f", k);
		if(i < NUM-1) printf(", ");
	}
	printf("\n");
}

/* main */
int main() {
	/* input */
	input_num(0); /* array A */
	input_num(1); /* array B */
	
	/* output */
	print_num(0); /* array A */
	print_num(1); /* array B */
	print_num(2); /* array C */
	return 0;
}