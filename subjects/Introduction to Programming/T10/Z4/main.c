#include <stdio.h>

/* check if letter */
int is_letter(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

/* remove n-th word from sentence */
char* izbaci_rijec(char *c, int n) {
    /* initial */
    int znak = 1, _words = 0;
    
    char *pocetak = c;
    char *output = pocetak;
    
    /* start going through set */
    while(*c != '\0') {
        if(!is_letter(*c)) znak = 1;
        else if(znak == 1) {
            znak = 0;
            _words++;
            if(_words == n) {
                pocetak = c;
                /* go to the end of word to remove */
                while(is_letter(*c)) c++;
                /* overwrite them and keep track of length */
                while((*pocetak++ = *c++));
                pocetak--;
                c--;
            }
        }
        if(*c != '\0') c++;
    }
    
    return output;
}

int main() {
    
	return 0;
}
