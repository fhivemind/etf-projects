#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int prebroji(char* s, char znak) {
	int broj = 0;
	while (*s != '\0') {
		if (*s == znak)
			broj++;
		s++;
	}
	return broj;
}

int check_chars(char *arr, char znak, int length) {
	int i = 0;
	for(i = 0; i < length; i++) 
		if(*(arr+i) == znak)
			return 1;
	
	return 0;
}

int duzina(char* s) {
	int duz = 0;
	while(*s != '\0') {
		duz++;
		s++;
	}
	return duz;
}

int samoglasnici(char *s) {
	/* create an array of chars */
	char _samo[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	int _len = 10;
	
	int i = 0;
	int _num = 0;
	for(i = 0; i < duzina(s); i++) 
		if(check_chars(_samo, *(s+i), _len))
			_num++;
	
	return _num;
}

int main() {
	char a[80],c;
	printf ("\nUnesite jednu rijec do 80 znakova (ENTER za kraj):  \n");
	unesi(a, 80);
	printf ("\nKoji znak treba prebrojati:   ");
	scanf ("%c", &c);
	printf("\nUnesena rijec sadrzi %d znakova.", duzina(a));
	printf("\nBroj znakova %c je: %d", c, prebroji(a, c));
	printf("\nBroj samoglasnika je: %d ", samoglasnici(a));
	return 0;
}
