#include <stdio.h>
#define upLIMIT 8

/* maxtemp function */
float maxtemp(float t[8]) {
	float max = t[0];
	int i;
	
	for(i = 1; i < upLIMIT; i++) 
		if(t[i] > max)
			max = t[i];
	
	return max;
}

/* prtemp function */
float prtemp(float t[8]) {
	float _srValue = 0;
	int i;
	
	for(i = 0; i < upLIMIT; i++) 
		_srValue += t[i];
		
	return (_srValue/upLIMIT);
}

int main() {
	/* initial */
	float t[upLIMIT];
	int i;
	
	printf("Unesite temperature: ");
	for(i = 0; i < upLIMIT; i++) 
		scanf("%f", &t[i]);
		
	printf("Maksimalna temperatura: %.1f\n", maxtemp(t));
	printf("Prosjecna temperatura: %.1f\n", prtemp(t));
	return 0;
}
