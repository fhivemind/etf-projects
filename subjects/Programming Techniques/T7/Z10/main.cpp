#include <iostream>
#include <functional>

// g(x) = f(f(...f(x))...) - n times
std::function<int(int)> IteriranaFunkcija(std::function<int(int)> f, int n) {
	if(n <= 1) return f;
	return [=](int x) { return f(IteriranaFunkcija(f, n-1)(x)); };
}

int main () {
	
}