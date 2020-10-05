#include <stdio.h>
#include <stdlib.h>
/* structure */
struct Vrijeme {
	int sati;
	int minute;
	int sekunde;
};

struct Vrijeme unos_vremena() {
	struct Vrijeme t;
	scanf("%d %d %d", &t.sati, &t.minute, &t.sekunde);
	return t;
}

unsigned int proteklo(struct Vrijeme t1, struct Vrijeme t2) {
	struct Vrijeme output;
	unsigned int seconds = 0;
	seconds = abs(t1.sati*3600 + t1.minute*60 + t1.sekunde - (t2.sati*3600 + t2.minute*60 + t2.sekunde));
	
	output.sati = seconds / 3600;
	output.minute = (seconds/60 - output.sati*60);
	output.sekunde = seconds - output.minute*60 - output.sati*3600;

	seconds = output.sati*3600 + output.minute*60 + output.sekunde;
	
	return seconds;
}


int main() {
	struct Vrijeme t1;
	struct Vrijeme t2;
	unsigned int seconds = 0;
	printf("Unesite prvo vrijeme (h m s): "); 
	t1 = unos_vremena();
	printf("\nUnesite drugo vrijeme (h m s): "); 
	t2 = unos_vremena();
	
	/* calculate seconds */
	seconds = proteklo(t1, t2);
	
	printf("\nIzmedju dva vremena je proteklo %u sekundi.", seconds);
	return 0;
}
