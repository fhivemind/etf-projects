#include <iostream>
#include <cmath>
#include <iomanip>

/* IntegralSum function */
double IngeralSum(double f(double), double a, double b, int n, int k) {
	if(k == 0) return 0;
	else if(k == 1) return f(a + (b-a)/n);
	else return f(a + k*(b-a)/n) + IngeralSum(f, a, b, n, k-1);
}

/* function to calculate aprox. value of integral */
double TrapeznoPravilo(double f(double), double a, double b, int n) {
	return ((b - a)/(2*n) * (f(a) + f(b) + 2 * IngeralSum(f, a, b, n, n-1)));
}

/* main function something to do ne znam */
int main () {
	int n;
	std::cout << "Unesite broj podintervala: ";
	std::cin >> n; 	
	std::cout << "Za taj broj podintervala priblizne vrijednosti integrala iznose: " << std::endl;
	
	constexpr double PI {4*atan(1)};
	
    	std::cout << std::fixed;
	std::cout << std::setprecision(5) << "- Za funkciju sin x na intervalu (0,pi): " << TrapeznoPravilo(std::sin, 0, PI, n) << std::endl; 
    	std::cout << std::setprecision(2) << "- Za funkciju x^3 na intervalu (0,10): " << TrapeznoPravilo([](double x) {return x*x*x;}, 0, 10, n) << std::endl; 
	std::cout << std::setprecision(5) << "- Za funkciju 1/x na intervalu (1,2): " << TrapeznoPravilo([](double x) {return 1/x;}, 1, 2, n) << std::endl; 
	return 0;
}