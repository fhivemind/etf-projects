#include <stdio.h>

/* function to implement */
char* zamijeni_slova(char* input, char *change) {
	/* intial pointers */
	char* edit = input;
	char* output = edit;
	char* pocetak = edit; 
	
	char* start = change;
	char* end = change;
	
	/* set wanted pointer to end */
	while((*end != '\0')) end++;
	end--;
	
	/* go thourgh array and start replacing them */
	while(start != end && start < end) {
		edit = pocetak;
		
		while(*edit != '\0') {
			if(*edit == *start)
				*edit = *end;
			edit++;
		}
		/* shift pointers  */
		start++;
		end--;
	}
	return output;
}

int main() {
	return 0;
}
