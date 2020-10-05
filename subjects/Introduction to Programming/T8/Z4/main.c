#include <stdio.h>
#define upLIMIT 10000

/* BRZO (NEEFIKASNO) RJEŠENJE */



struct histogram {
	int value;
	int index;
};

/* function to find second greatest number in array */
int max_value(int niz[], int vel) {
	int i;
	int max = niz[0];
	
	for(i = 1; i < vel; i++) 
		if(niz[i] > max)
			max = niz[i];
			
	return max;
}


int drugi(int niz[], int vel) {
	/* initial */
	int i, max, hSize = 0, id;
	int _helpA[upLIMIT];
	
	struct histogram data[upLIMIT];
	for(i = 0; i < vel; i++) {
		data[i].value = niz[i];
		data[i].index = i;
	}
	
	/* remove max elements from histogram */
	max = max_value(niz, vel);
	for(i = 0; i < vel; i++) 
		if(niz[i] == max) 
			data[i].index = -1;
	
	/* find second maximum number */
	for(i = 0; i < vel; i++) 
		if(data[i].index != -1)
			_helpA[hSize++] = data[i].value;
	
	if(hSize > 0)
		max = max_value(_helpA, hSize);
	else 
		return -1;
	
	id = -1;
	for(i = 0; i < vel; i++) {
		if(max == niz[i]) {
			id = i;
			break;
		}
	}
	
	return id;
}



int main() {
	/* initial */
	int i, vel = 0;
	int niz[upLIMIT];
	
	/* input */
	printf("Unesite niz brojeva: ");
	do {
		scanf("%d", &niz[vel++]);
	} while(niz[vel-1] != -1);
	
	/* output */
	printf("Indeks drugog po velicini je: %d", drugi(niz, vel));
	return 0;
}
