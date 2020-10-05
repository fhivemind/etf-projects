#include <stdio.h>
#define upLIMIT 100

/* maxtemp function */
float maxtemp(float t[], int vel) {
	float max = t[0];
	int i;
	
	for(i = 1; i < vel; i++) 
		if(t[i] > max)
			max = t[i];
	
	return max;
}

/* prtemp function */
float prtemp(float t[], int vel) {
	float _srValue = 0;
	int i;
	
	for(i = 0; i < vel; i++) 
		_srValue += t[i];
		
	return (_srValue/vel);
}

int main() {
	/* initial */
	float t[upLIMIT];
	int i, vel;
	
	printf("Unesite broj mjerenja: ");
	do 
		scanf("%d", &vel);
	while(vel <= 0 || vel > 100);
	
	printf("Unesite temperature: ");
	for(i = 0; i < vel; i++) 
		scanf("%f", &t[i]);
		
	printf("Maksimalna temperatura: %.1f\n", maxtemp(t, vel));
	printf("Prosjecna temperatura: %.1f\n", prtemp(t, vel));
	return 0;
}
