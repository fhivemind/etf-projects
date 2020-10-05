#include <iostream>
#include <cmath>
#include <vector>

/* prime function check */
bool DaLiJeProst(int n) {
	if(n <= 1) return false;
	
	for(int i(2); i <= int(std::sqrt(std::abs(n))); i++)
		if(n % i == 0) return false; 				
	
	return true;
} 

/* vector function */
std::vector<int> ProstiBrojeviUOpsegu(int a, int b) {
	std::vector<int> list;
	for(long i = static_cast<long>(a); i <= static_cast<long>(b); i++)
		if(DaLiJeProst(int(i))) list.push_back(int(i));
	
	return list;
}

int main () {
	/* input */
	int a, b;
	std::cout << "Unesite pocetnu i krajnju vrijednost: ";
	std::cin >> a >> b;
	
	/* create prime vector */
	std::vector<int> primes = ProstiBrojeviUOpsegu(a, b);
	if(primes.empty()) std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b << "!\n";
	else {
		std::cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
		for(int i(0); i < int(primes.size())-1; (std::cout << primes.at(i++) << ", "));
		std::cout << primes.at(int(primes.size())-1) << '\n';
	}
	return 0;
}