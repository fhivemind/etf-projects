#include <iostream>
#include <stdexcept>
#include <cstring>
#include <algorithm>

/* 	function to read and alocate string	*/
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

/*	main program logic 	*/
int main () {
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	char** strList (nullptr);
	try {
		std::cout << "Unesite recenice: " << std::endl;
		strList = allocateStrings(n);
		std::sort(strList, strList+n, [](char* a, char* b) -> bool {
			return (std::strcmp(a, b) < 0);
		});
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