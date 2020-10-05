#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak = getchar();
	int i = 0;
	
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

char* velika(char *s) {
	char *arr = s;
	int shift = 'A' - 'a';
	
	while(*arr != '\0') {
		if(*arr >= 'a' && *arr <= 'z') 
			*arr = *arr + shift;
		arr++;
	}
	return s; 
}




int main() {
	char s[100];
	printf("Unesite neki tekst: ");
	unesi(s, 100);
	printf("%s", velika(s));
	
	return 0;
}
