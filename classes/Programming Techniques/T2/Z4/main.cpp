#include <iostream>
#include <cmath>
#include <complex>

int main () {
	/* input */
	int n;
	double R, X;
	std::complex<double> zu{0,0}, z;
	bool _nulSet = false; 				/* to check if element zero exists */
	
	std::cout << "Unesite broj elemenata: "; std::cin >> n;
	std::cout << "\n";
	
	for(int i(1); i <= n; i++) {
		std::cout << "R" << i << " = "; std::cin >> R;
		std::cout << "X" << i << " = "; std::cin >> X;
		std::cout << "\n";
	
		z = std::complex<double>(R, X);
		if(std::abs(z) > 0) zu += 1./z;		
		else _nulSet = true;
	}
	
	if(std::abs(zu) > 0) zu = 1./zu;
	if(_nulSet) zu = std::complex<double>{0,0}; /* if nul element exists */
	std::cout << "Paralelna veza ovih elemenata ima R = " << zu.real() << " i X = " << zu.imag() << ".\n";
	return 0;
}