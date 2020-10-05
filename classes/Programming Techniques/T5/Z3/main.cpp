#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

/* to edit sort function */
inline bool sortFunction(const int &a, const int &b) { 
	return (int(log10(abs(a))) < int(log10(abs(b)))); 
}

inline bool nefTroficfren(const int &num) { 
	return (abs(num) > 999  || abs(num) < 100); 
}

inline bool fTroficfren(const int &num) { 
	return !nefTroficfren(num); 
}


int main () {
	int size;
	std::cout << "Unesite broj elemenata (max. 1000): ";
	std::cin >> size;

	std::vector<int> niz(size);
	std::cout << "Unesite elemente: ";
	std::for_each(niz.begin(), niz.end(), [](int &ref) { std::cin >> ref; });
	
	auto minmax = std::minmax_element(niz.begin(), niz.end());
	std::cout << "Najveci element niza je " << *(minmax.second) << std::endl;  
	std::cout << "Najmanji element niza se pojavljuje "<< std::count(niz.begin(), niz.end(), *(minmax.first)) <<" puta u nizu" << std::endl;
	
	std::cout << "U nizu ima "<< std::count_if(niz.begin(), niz.end(), 
		[](const int &a) { return ((int(std::sqrt(a)) * int(std::sqrt(a))) == a); }) <<" brojeva koji su potpuni kvadrati" << std::endl;
	
	std::cout << "Prvi element sa najmanjim brojem cifara je " << *(min_element  (std::begin(niz), std::end(niz), sortFunction))<< std::endl;

	std::cout << "Elementi koji nisu trocifreni su: ";
	int brojTrocifrehih = std::count_if(niz.begin(), niz.end(), fTroficfren);
	std::vector<int> trocifreni(size-brojTrocifrehih);
	std::copy_if(niz.begin(), niz.end(), trocifreni.begin(), nefTroficfren);
	std::for_each(trocifreni.begin(), trocifreni.end(), [](const int &num) { std::cout << num << ' '; });
	std::cout << '\n';
	return 0;
}