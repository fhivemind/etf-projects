#include <stdio.h>
#define HASHNUM	13

/* swap letter */
char encrypt_decrypt(char letter, int tip) {
	int znak = (tip == 0 ? 1:-1);
	int c = letter;
	
	if((c >= 'A' && c <= 'Z')) {
		c += znak*(HASHNUM % 26);
		if(c > 'Z') c += 'A' - 'Z' - 1;
		else if(c < 'A') c += 'Z' - 'A';
	}
	else if((c >= 'a' && c <= 'z')) {
		c += znak*(HASHNUM % 26);
		if(c > 'z') c += 'a' - 'z' - 1;
		else if(c < 'a') c += 'z' - 'a';
	}
	
	return c;
}


char* rot13(char* str) {
	int len = 0;
	
	while(*str != '\0') {
		*str = encrypt_decrypt(*str, 0);
		str++;
		len++;
	}
	
	/* put pointer on front */
	while(len > 0) {
		str--;
		len--;
	}
	
	return str;
}

int main() {
	
	return 0;
}
