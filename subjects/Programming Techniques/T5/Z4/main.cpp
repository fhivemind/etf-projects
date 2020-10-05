#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>

int main () {
	int size;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> size;

	std::deque<int> niz(size);
	std::cout << "Unesite elemente: ";
	std::for_each(niz.begin(), niz.end(), [](int &ref) { std::cin >> ref; });
	
	auto minmax = std::minmax_element(niz.begin(), niz.end());
	std::cout << "Najveci element deka je " << *(minmax.second) << std::endl;  
	std::cout << "Najmanji element deka se pojavljuje "<< std::count(niz.begin(), niz.end(), *(minmax.first)) <<" puta u deku" << std::endl;
	
	std::cout << "U deku ima "<< std::count_if(niz.begin(), niz.end(), 
		[](const int &a) { return ((int(std::sqrt(a)) * int(std::sqrt(a))) == a); }) <<" brojeva koji su potpuni kvadrati" << std::endl;
	
	std::cout << "Prvi element sa najmanjim brojem cifara je " << *(min_element  (std::begin(niz), std::end(niz), 
		[](const int &a, const int &b) { return (int(log10(abs(a))) < int(log10(abs(b)))); }))<< std::endl;

	auto nefTroficfren = [](const int &num) { return (abs(num) > 999  || abs(num) < 100); };
	auto fTroficfren = [nefTroficfren](const int &num) { return !nefTroficfren(num); };

	std::cout << "Elementi koji nisu trocifreni su: ";
	int brojTrocifrehih = std::count_if(niz.begin(), niz.end(), fTroficfren);
	std::deque<int> trocifreni(size-brojTrocifrehih);
	std::copy_if(niz.begin(), niz.end(), trocifreni.begin(), nefTroficfren);
	std::for_each(trocifreni.begin(), trocifreni.end(), [](const int &num) { std::cout << num << ' '; });
	std::cout << '\n';
	return 0;
}