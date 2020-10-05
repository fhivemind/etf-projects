#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <cmath>

/*   Generate type	*/
template <typename Tip>
void PopuniStepenimaDva(Tip* niz, int n) {
	Tip num {static_cast<Tip>(1)};
	*niz++ = num;
	for(int i{1}; i < n; ++i) {
		num *= static_cast<Tip>(2);
		if(num < std::numeric_limits<Tip>::max() && num > 0) *niz++ = num;
		else {
			throw std::overflow_error("Prekoracen dozvoljeni opseg");
		}
	}
}

template <typename Tip>
Tip* GenerirajStepeneDvojke(int n) {
	if(n <= 0) throw std::domain_error("Broj elemenata mora biti pozitivan");
	Tip* niz {nullptr};
	try {
		niz = new Tip[n];
		try {
			PopuniStepenimaDva(niz, n);	
		}
		catch(...) {
			delete [] niz;
			throw;
		}
		return niz;
	}
	catch(std::bad_alloc) {
		throw std::runtime_error("Alokacija nije uspjela");
	}
}

int main () {
	// testiranje funkcije na double tip podataka
	int n;
	std::cout << "Koliko zelite elemenata: ";
	std::cin >> n;
	
	try {
		int *p {GenerirajStepeneDvojke<int>(n)};
		for(int i {0}; i < n; ++i) std::cout << p[i] << " ";
		delete [] p;
	}
	catch (std::exception& ex) {
		std::cout << "Izuzetak: " << ex.what();
		return -1;
	}
	return 0;
}