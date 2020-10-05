#include <iostream>
#include <stdexcept>
#include <cstring>

/* 	function to read and allocate string	*/
char** allocateStrings(int _size) {
	std::cin.ignore(10000, '\n'); // clear buffer
	char** output(nullptr);
	try {output = new char*[_size];}
	catch(...) {throw "Problemi s memorijom!";}
	
	for(int i(0); i < _size; ++i) {
		try {
			char temp[1000];
			std::cin.getline(temp, sizeof temp);
			output[i] = new char[std::strlen(temp) + 1];
			std::strcpy(output[i], temp);
		}
		catch(...) {
			for(int j(0); j < i; ++j)
				delete [] output[j];
			delete [] output;
			throw "Problemi s memorijom!";
		}
	}
	
	return output;
}
/*	sort strings function	*/
void sortStrings(char **strList, int n) {
	for(int i(0); i < n-1; ++i) {
		for(int j(i+1); j < n; ++j) {
			if(std::strcmp(strList[i], strList[j]) > 0) {
				char* temp (strList[i]);
				strList[i] = std::move(strList[j]);
				strList[j] = std::move(temp);
			}
		}
	}
}

/*	main program logic 	*/
int main () {
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	char** strList (nullptr);
	try {
		std::cout << "Unesite recenice: " << std::endl;
		strList = allocateStrings(n);
		sortStrings(strList, n);
	}
	catch(const char *tekst) {
		delete [] strList;
		std::cout << tekst;
		return -1;
	}
	catch(std::exception& e) {
		delete [] strList;
		std::cout << e.what();
		return -1;
	}
	
	std::cout << "Sortirane recenice: " << std::endl;
	for(int i(0); i < n; ++i)
		std::cout << strList[i] << std::endl;
	
	for(int i(0); i < n; ++i)
		delete [] strList[i];
	delete [] strList;
	return 0;
}