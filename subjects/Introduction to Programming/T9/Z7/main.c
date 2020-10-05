#include <stdio.h>


char to_down(char znak) {
	if(znak >= 'A' && znak <= 'Z')
		return (znak+'a'-'A');
	return znak;
}


int strcmpi(const char *s1, const char *s2, int velikamala) {
	
	char c1, c2;
	
	while(*s1 != '\0') {
		/* check */
		c1 = *s1;
		c2 = *s2;

		if(c2 == '\0')
			return -1;

		if(!velikamala) {
			c1 = to_down(c1);
			c2 = to_down(c2);
		}

		if(c1 < c2)
			return -1;
		else if(c1 > c2)
			return 1;
		
		s1++;
		s2++;
	}
	
	if(*s2 != '\0')
		return -1;
	
	return 0;
}



int main() {
	
	return 0;
}
