#include <stdio.h>

/* check char type */
int is_word(char c) {
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

/* function to find first word */
int prva_rijec(char *s) {
	char *arr = s;
	int i = 0, _words = 0;
	
	/* count the words and find the first*/
	while(*arr != '\0') {
		while(is_word(*arr)) {
			arr++;
			if(*arr == '\0' || !is_word(*arr)) {
				_words++;
				break;
			}
			if(_words == 0) i++;
		}
		while(!is_word(*arr) && *arr != '\0')
			arr++;
	}
	/* overwrite */
	*(s+i+1) = '\0';
	
	return _words;
}




int main() {
	char recenica[200] = "Danas    je    lijep    i     suncan    dan.    ";
	printf("Broj rijeci u recenici je: %d\n",prva_rijec(recenica));
	printf("%s", recenica);
	return 0;
}
