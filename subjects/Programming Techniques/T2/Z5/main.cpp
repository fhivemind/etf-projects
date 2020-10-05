#include <iostream>
#include <cmath>
#include <complex>

int main () {
	/* input */
	int n;
	double Z, Fi;
	std::complex<double> zu{0,0}, z;
	bool _nulSet = false; 				/* to check if element zero exists */
	
	std::cout << "Unesi broj elemenata:"; std::cin >> n;
	std::cout << "\n";
	
	/* define constant PI */
	constexpr double PI {4 * atan(1)};
	
	for(int i(1); i <= n; i++) {
		std::cout << "Z" << i << " = "; std::cin >> Z;
		std::cout << "fi" << i << " = "; std::cin >> Fi;
		std::cout << "\n";
		
		Fi = Fi * PI/180.0;			/* degree to rad */
		z = std::polar(Z, Fi);
		
		if(std::abs(z) > 0) zu += 1./z;		
		else _nulSet = true;
	}
	
	if(std::abs(zu) > 0) zu = 1./zu;
	if(_nulSet) zu = std::complex<double>{0,0}; /* if nul element exists */
	std::cout << "Paralelna veza ovih elemenata ima Z = " << std::abs(zu) << " i fi = " << std::arg(zu)*180.0/PI << ".\n";
	return 0;
}