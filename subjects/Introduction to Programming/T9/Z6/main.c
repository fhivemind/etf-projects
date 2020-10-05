#include <stdio.h>


int strcmp(const char *s1, const char *s2) {
	while(*s1 != '\0') {

		/* check */
		if(*s2 == '\0')
			return -1;

		if(*s1 < *s2)
			return -1;
		else if(*s1 > *s2)
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
