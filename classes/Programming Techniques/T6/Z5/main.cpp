#include <iostream>
#include <deque>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <new>

template <typename iter>
auto KreirajDinamickuKopiju2D(iter niz) -> typename std::remove_reference<decltype(niz[0][0])>::type ** {
	typedef typename std::remove_reference<decltype(niz[0][0])>::type tip;
	
	tip **p{nullptr};
	try {
		p = new tip*[niz.size()];	
	}
	catch(...) {
		throw;
	}
	
	for(int i  {0}; i < niz.size(); ++i) {
		try {
			p[i] = new tip[niz.at(i).size()];
		}
		catch (...){
			for(int j {0}; j < i; ++j)
	               delete[] p[j];
	          delete[] p;
	          throw;
		}
		for(int j {0}; j < niz.at(i).size(); ++j) p[i][j] = niz.at(i).at(j);
	}
	return p;
}

int main ()
{
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
	
	for(int j {0}; j < n; ++j)
          delete [] dinArr[j];
     delete [] dinArr;
	
	return 0;
}