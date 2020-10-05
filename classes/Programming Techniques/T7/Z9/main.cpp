#include <iostream>
#include <functional>
#include <algorithm>


//	function implementation
std::function<double(double)> plus2(double r) { 
	return [=](double k) -> double { 
		return k + r; 
	};
}

std::function<std::function<double(double)>(double)> plus3(double r) {
	return [=](double h) {
		return [=](double g) {
			return r + plus2(g)(h);
		};
	};
}

// currying?
auto plus4 = [](double r) {
	return [=](double h) {
		return [=](double g) {
			return [=](double x) {
				return r + plus3(h)(g)(x);
			};
		};
	};
};

int main ()
{
	/*double x (5), y (6), z(7), m(8);
	double k (plus2(x)(y));
	double d (plus3(x)(y)(z));
	double l (plus4(x)(y)(z)(plus3(x)(y)(plus3(x)(y)(plus3(x)(y)(plus3(x)(y)(m))))));*/
	return 0;
}