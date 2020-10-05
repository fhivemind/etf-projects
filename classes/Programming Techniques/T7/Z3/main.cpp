#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
#include <algorithm>

/* 	function to read and alocate string	*/
std::string** allocateStrings(int _size) {
	std::cin.ignore(10000, '\n'); // clear buffer
	std::string** output(nullptr);
	try {
		output = new std::string*[_size] {};
	}
	catch(...) { 
		delete [] output;
		throw "Problemi s memorijom!"; 
	}
	
	try {
		for(int i(0); i < _size; ++i) {
			output[i] = new std::string;
			std::getline(std::cin, *output[i]);
		}
	}
	catch(...) {
		for(int i(0); i < _size; ++i) 
			delete output[i];
		delete [] output;
		throw "Problemi s memorijom!";
	}
	
	return output;
}

/*	main program logic 	*/
int main () {
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::string** strList (nullptr);
	try {
		std::cout << "Unesite recenice: " << std::endl;
		strList = allocateStrings(n);
		std::sort(strList, strList+n, [](const std::string *a, const std::string *b) -> bool {
			return (*a < *b);
		});
	}
	catch(const char *tekst) {
		std::cout << tekst;
		return -1;
	}
	catch(std::exception& e) {
		std::cout << e.what();
		return -1;
	}
	
	std::cout << "Sortirane recenice: " << std::endl;
	for(int i(0); i < n; ++i)
		std::cout << *strList[i] << std::endl;
	
	for(int i(0); i < _size; ++i) 
		delete _clean[i];
	delete [] _clean;
	return 0;
}