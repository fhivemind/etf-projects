#include <iostream>     
#include <cmath>
#include <algorithm>   
#include <vector>

/* function to sum digits */
int sumaCifara(int num) {
	if(num == 0) return 0;
	else return (num % 10) + sumaCifara(num/10);
}

/* sort temp function */
bool sortAlgoritam(const int &a, const int &b) { 
	if(sumaCifara(abs(a)) == sumaCifara(abs(b)) && a < b) return true;
	return (sumaCifara(abs(a)) < sumaCifara(abs(b)));
}

/* main function */
int main () {
	int size;
  	std::cout << "Unesite broj elemenata: ";
  	std::cin >> size;
  	std::vector<int>niz(size);
  	
  	std::cout << "Unesite elemente: ";
	std::for_each(niz.begin(), niz.end(), [](int &ref) { std::cin >> ref; });
	
	std::cout << "Niz sortiran po sumi cifara glasi: ";
  	std::sort(niz.begin(), niz.end(), sortAlgoritam);
  	std::for_each(niz.begin(), niz.end(), [](const int &num) { std::cout << num << ' '; });
	std::cout << std::endl;
	
  	int num;
  	std::cout << "Unesite broj koji trazite: ";
  	std::cin >> num;
  	bool _exists = std::binary_search(niz.begin(), niz.end(), num, sortAlgoritam);
  	if(_exists) {
  		auto it = std::find(niz.begin(), niz.end(), num);
  		std::cout << "Trazeni broj nalazi se na poziciji " << (it-niz.begin());
  	}
  	else std::cout << "Trazeni broj ne nalazi se u nizu!";
  	
  	return 0;
}