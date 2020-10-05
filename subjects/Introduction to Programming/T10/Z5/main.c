#include <stdio.h>
#include <ctype.h>

/* remove whitespaces function */
char* whitespace(char* str) {
	/* initial */
	char *poc = str;
	char *edit = str;
	char *output = edit;
	
	int _set = 0;
	
	while(*str != '\0') {
		/* firstly, check front */
		if(_set == 0) 
			if(!isspace(*str))
				_set = 1;
		
		/* check rest */
		if(isspace(*str)) {
			poc = str;
			edit = str;
			
			while(isspace(*str)) str++;
			if(_set)
				*edit++ = ' ';
	
			/* copy strings */
			while((*edit++ = *str++));
			/* pointer reset */
			str = poc;
			edit = poc;
		}
		str++;
	}
	
	/* check back */
	while(*edit++ != '\0');
	edit--;
	
	if(*(edit-1) == ' ') 
		*(edit-1) = '\0';
	
	return output;
}

int main() {
	
	return 0;
}
