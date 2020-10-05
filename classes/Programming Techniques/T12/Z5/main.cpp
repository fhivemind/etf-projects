#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main ()
{
	int n;
	std::cout << "Koliko zelite elemenata: "; std::cin >> n; std::vector<double> lista(n);
	std::cout << "Unesite elemente: "; std::for_each(lista.begin(), lista.end(), [](double &val) {std::cin >> val;});
	std::cout << "Transformirani elementi: ";
	std::transform(lista.begin(), lista.end(), lista.begin(), std::bind1st(std::divides<double>(), 1.));
	std::for_each(lista.begin(), lista.end(), [](double &val) {std::cout << val << " ";});
	return 0;
}