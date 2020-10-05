#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
#include <memory>
#include <algorithm>

using SHARED = std::shared_ptr<std::string>;

/* 	function to read and alocate string	*/
std::unique_ptr<SHARED[]> allocateStrings(int _size) {
	std::cin.ignore(10000, '\n'); // clear buffer
	std::unique_ptr<SHARED[]> output;
	try {
		output = std::unique_ptr<SHARED[]>(new SHARED[_size]);
	}
	catch(...) { 
		throw "Problemi s memorijom!"; 
	}
	
	try {
		for(int i(0); i < _size; ++i) {
			output[i] = std::make_shared<std::string>();
			std::getline(std::cin, *output[i]);
		}
	}
	catch(...) {
		throw "Problemi s memorijom!";
	}
	
	return output;
}

/*	main program logic 	*/
int main () {
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::unique_ptr<SHARED[]> strList;
	try {
		std::cout << "Unesite recenice: " << std::endl;
		strList = allocateStrings(n);
		std::sort(strList.get(), strList.get()+n, [](const SHARED a, const SHARED b) -> bool {
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

	return 0;
}