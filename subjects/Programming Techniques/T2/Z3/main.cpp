#include <iostream>
#include <cmath>
#include <complex>

int main () {
	/* input */
	int n;
	std::complex<double> z{0,0}, zu{0,0};
	bool _nulSet = false; 				/* to check if element zero exists */
	
	std::cout << "Unesite broj elemenata: "; std::cin >> n;
	std::cout << "\n";
	
	for(int i(1); i <= n; i++) {
		std::cout << "Z_" << i << " = "; std::cin >> z;
		
		if(std::abs(z) > 0) zu += 1./z;
		else _nulSet = true;
	}
	
	std::cout << " \n";
	if(std::abs(zu) > 0) zu = 1./zu;
	if(_nulSet) zu = std::complex<double>{0,0}; /* if nul element exists */
	std::cout << "Paralelna veza ovih elemenata ima impedansu Z_ = " << zu << '.';
	return 0;
}