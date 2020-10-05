#include <stdio.h>

#define SP_D 90
#define SP_G 120
#define DP_D 60
#define DP_G 80
#define P_D 55
#define P_G 100

/* check limits */
void checkLimit(int leftB, int rightB, float value) {
	if(leftB <= value && rightB >= value) 
		printf("normalan\n");
	else 
		printf("nije normalan\n");
}

int main() {
	/* initial */
	float SP, DP, P;
	
	/* input */
	printf("Dobrodosli kod Vaseg kucnog ljekara!");
	printf("\nUnesite sistolicki, dijastolicki pritisak i puls: "); 
	scanf("%f %f %f", &SP, &DP, &P);
	
	/* output */
	printf("SP: "); checkLimit(SP_D, SP_G, SP);
	printf("DP: "); checkLimit(DP_D, DP_G, DP);
	printf("Puls: "); checkLimit(P_D, P_G, P);

	return 0;
}
