#include <iostream>
#include <cmath>
#include <vector>

typedef std::vector<double> Niz;
constexpr double ERR {0.00001};

/* function to check number period */
bool TestPerioda(Niz num, int p) {
	/* iff condition, must check */
	if(p <= 0 || static_cast<int>(num.size()) <= p) return false; 
	
	/* find basic cycle */
	int cycle {static_cast<int>(num.size()-1)/p};
	
	/* check array */
	for(int i(0); i < p; i++) {
		for(int j(0); j <= cycle; j++) {
			int pos = j*p + i;
			if(pos < static_cast<int>(num.size())) 
				if(fabs(num.at(i) - num.at(pos)) > ERR) return false;
		}
	}
	
	/* default output */
	return true;
}

/* function to find number period */
int OdrediOsnovniPeriod(Niz num) {
	/* start checking */
	for(int j(1); j < static_cast<int>(num.size()); j++)
		if(TestPerioda(num, j)) return j;
	
	/* default output */
	return 0;
}

int main () {
	/* start doing something */
	Niz arr;					/* create empty vector */
	std::cout << "Unesite slijed brojeva (0 za kraj): ";
	for(;;) {
		double num;
		std::cin >> num;
		if(fabs(num) < ERR) break;	/* if input is 0 */
		arr.push_back(num);
	}
	
	/* output */
	int period {OdrediOsnovniPeriod(arr)}; /* find number period */
	if(period) std::cout << "Slijed je periodican sa osnovnim periodom "<< period << ".";
	else std::cout << "Slijed nije periodican!" << std::endl;
	
	return 0;
}