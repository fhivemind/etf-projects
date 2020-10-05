#include <iostream>
#include <list>
#include <algorithm>


template <class T> 
void SortirajListu(std::list<T> &inputList) {
	for(;;) {
		bool _sorted(true);
		
		auto _next (inputList.begin());
		auto _current (_next++);
		
		for (; _next != inputList.end(); _current++, _next++) {
			if(*_next < *_current) {
				_sorted = false;
				iter_swap(_next, _current);
			}
		}
		if(_sorted) break;
	}
}

int main () {
	int n;
	std::cout << "Koliko ima elemenata: ";
	std::cin >> n;
	std::cout << "Unesite elemente: ";
	std::list<int> lista(n, 0);
	std::for_each(lista.begin(), lista.end(), [](int &val) {std::cin>>val;});
	std::cout << "Sortirana lista: ";
	SortirajListu(lista);
	std::for_each(lista.begin(), lista.end(), [](const int &val) {std::cout<<val<<" ";});
	return 0;
}