#include <stdio.h>
#include <string.h>

/* function to swap */
char* zamijeni_broj(char* niz, int num) {
	char broj[10][7] = {"nula", "jedan", "dva", "tri", "cetiri", "pet", "sest", "sedam", "osam", "devet"};
	int duzina = strlen(broj[num])-1, 
		i = 0, _len = 0;
	char *c = niz;
	char br;
	
	/* save calculate time */
	br = num + '0';
	
	/* swap num with words */
	while (*c != '\0') {
		if(br == *c) {
			char *tmp = c;
			while(*tmp != '\0') tmp++;
			while(tmp > c) { 
				*(tmp+duzina) = *tmp;
				tmp--;
			}
			
			i = 0;
			_len += duzina;
			while(i <= duzina) 
				*c++ = broj[num][i++];
			c--;
		}
		c++;
		_len++;
	}
	
	/* put pointer on the first place */
	while(_len > 0) { 
		c--;
		_len--;
	}
	
	return c;
}

int main() {
	return 0;
}
