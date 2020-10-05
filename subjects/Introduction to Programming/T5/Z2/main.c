#include <stdio.h>
#define BROJ_EL 10

int main() {
	int niz[BROJ_EL], sum_all, sum_even, min, max, i, _el;
	float prosjek_all, prosjek_even;
	
	/* unos niza */
	sum_all = 0;
	sum_even = 0;
	_el = 0;
	
	/* min max */
	min = -1;
	max = -1;
	
	for(i = 0; i < BROJ_EL; i++) {
		/* input */
		printf("Unesite %d. cijeli broj: ", i+1);
		scanf("%d", &niz[i]);
		
		/* assign value */
		if(min == -1) min = niz[i];
		if(max == -1) max = niz[i];
		
		/* calculate sums of numbers */
		sum_all += niz[i];
		if(niz[i] % 2 == 0) {
			sum_even += niz[i];
			_el++;
		}
		
		/* min max */
		if(max < niz[i]) max = niz[i];
		if(min > niz[i]) min = niz[i];
	}
	/* racunanje prosjeka */
	prosjek_all = (float)sum_all/BROJ_EL;
	if(_el > 0) prosjek_even = (float)sum_even/_el;
	else prosjek_even = 0.0;
	
	/* output */
	printf("Srednja vrijednost unesenih brojeva je %.2f.\n", prosjek_all);
	printf("Srednja vrijednost parnih brojeva je %.2f.\n", prosjek_even);
	printf("Najveci element je %d a najmanji %d.", max, min);
	return 0;
}