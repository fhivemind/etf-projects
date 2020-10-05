#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH	10
#define L_CUT	3

char* tritacke(char* text) {
	char *poc = text;
	char *edit = text;
	char *output = edit;
	int i = 0, _cut = 0;
	
	while(*text != '\0') {
		_cut = 0;
		i = 0;
		if(isalpha(*text)) {
			while(isalpha(*text)) {
				i++;
				if(i == L_CUT+1) {
					poc = text;
					edit = text;
				}
				else if(i >= LENGTH) {
					_cut = 1;
				}
				
				if(*text != '\0')
					text++;
				else break;
			}
			if(_cut) {
				*edit++ = '.';
				
				while((*edit++ = *text++));
				text--;
				text = poc;
				edit = poc;
			}
		}
		if(*text != '\0')
			text++;
	}
	return output;
	
}

int main() {
	return 0;
}
