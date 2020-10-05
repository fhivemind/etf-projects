#include <iostream>
#include <cctype>

/* function to remove first word using pointers */
char* RemoveFirstWord(char* text) {
	bool _word {false}, _second {false};
	for(;*text != '\0';) {
		if(!isspace(*text)) {
			if(_word && _second) return text;
			_word = true;
		}
		else if(_word) 
			_second = true;
		++text;
	}
	return text;
}


/* main function */
int main () {
	char text[1000];
	std::cout << "Unesite recenicu: ";
	std::cin.getline(text, 1000);
	std::cout << "Recenica bez prve rijeci glasi: " << RemoveFirstWord(text) << std::endl;
	return 0;
}