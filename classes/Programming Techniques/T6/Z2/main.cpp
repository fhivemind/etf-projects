#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <type_traits>

/* function to implement */
template <typename iter>
auto KreirajIzvrnutiNiz(iter arrStart, iter arrEnd) -> decltype(&*arrStart) {
	try { 	
		auto niz = new typename std::remove_reference<decltype(*arrStart)>::type[std::distance(arrStart,arrEnd)];
	
		/* postavi pokazivac na kraj */
		niz += std::distance(arrStart,arrEnd);
		for(;arrStart != arrEnd; *--niz = *arrStart++);
		return niz;
	}
	catch(...) {
		throw std::bad_alloc();
	}
}

/* main function*/
int main () {
	int n;
	std::cout << "Koliko zelite elemenata: ";
	std::cin >> n;
	try {
		std::vector<double> niz(n, 0);
		std::cout << "Unesite elemente: ";
		for(int i {0}; i < n; ++i) std::cin >> niz.at(i);
		try {
			double* p {KreirajIzvrnutiNiz(std::begin(niz), std::end(niz))};
			double* elem {p};
			std::cout << "Kreirani niz: ";
			for(int i{0}; i < n; i++) std::cout << *elem++ << ' ';
			delete [] p;
		}
		catch(std::bad_alloc& e) {
			std::cout << e.what();
		}
	}
	catch(...) {
		std::cout << "Nedovoljno memorije!";
	}
	return 0;
}