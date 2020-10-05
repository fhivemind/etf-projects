#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <stdexcept>
#include <type_traits>
#include <new>
#include <cstdio>

template <typename iter>
auto KreirajDinamickuKopiju2D(iter niz) -> typename std::remove_reference<decltype(niz[0][0])>::type ** {
	typedef typename std::remove_reference<decltype(niz[0][0])>::type tip;
	
	tip **p{nullptr};
	try {
		p = new tip*[niz.size()] {};	
	}
	catch(...) {
		throw;
	}
	
	int _size {0};
	for(int i=0; i < niz.size(); ++i) 
		_size += niz.at(i).size();
		
	try {
		p[0] = new tip[_size];
	}
	catch (...) {
          delete[] p;
          throw;
	}
	
	for(int i {0}; i < niz.size(); ++i) {
		if(i > 0) p[i] = p[i-1] + niz.at(i-1).size();
		
		for(int j {0}; j < niz.at(i).size(); ++j) 
			p[i][j] = niz.at(i).at(j);
	}
	return p;
}

int main () {
	int n;
	std::cout <<"Unesite broj redova kvadratne matrice: ";
	std::cin >> n;
	
	std::vector<std::deque<int>> mat;
	try {
		mat.resize(n);
		for(int i {0}; i < n; i++)
			mat.at(i).resize(n);
	}
	catch (std::bad_alloc) {
		std::cout << "Nedovoljno memorije";
        	return 1;
	}
	
	std::cout << "Unesite elemente matrice: ";
	for(int i {0}; i < n; i++) 
		for(int j {0}; j < n; j++)
			std::cin >> mat.at(i).at(j);
			
	
	int **dinArr{nullptr};
	try {
		dinArr = KreirajDinamickuKopiju2D(mat);
	}
	catch (std::bad_alloc) {
		std::cout << "Nedovoljno memorije";
        	return 1;
	}
	
	for(int i {0}; i < n; i++) {
		for(int j {0}; j < mat.at(i).size(); j++)
			std::cout << dinArr[i][j] << ' ';
		std::cout << std::endl;
	}
	
	delete [] dinArr[0];
     delete [] dinArr;
	
	return 0;
}