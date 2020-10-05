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

struct Vrijeme proteklo(struct Vrijeme t1, struct Vrijeme t2) {
	struct Vrijeme output;
	unsigned int seconds = 0;
	
	seconds = abs(t1.sati*3600 + t1.minute*60 + t1.sekunde - (t2.sati*3600 + t2.minute*60 + t2.sekunde));
	output.sati = seconds / 3600;
	output.minute = (seconds/60 - output.sati*60);
	output.sekunde = seconds - output.minute*60 - output.sati*3600;
	
	return output;
}



int main() {
	struct Vrijeme t1;
	struct Vrijeme t2;
	struct Vrijeme proteklo_t;
	printf("Unesite prvo vrijeme (h m s): "); 
	t1 = unos_vremena();
	printf("\nUnesite drugo vrijeme (h m s): "); 
	t2 = unos_vremena();
	
	/* calculate time */
	proteklo_t = proteklo(t1, t2);
	
	printf("\nIzmedju dva vremena je proteklo %d sati, %d minuta i %d sekundi.", proteklo_t.sati, proteklo_t.minute, proteklo_t.sekunde);
	return 0;
}
