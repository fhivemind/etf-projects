#include <iostream>
#include <cmath>
#include <iomanip> 

/* function to create row */
void _row(int size, int type) {
     std::cout << "+";
     for(int i = 0; i < size; i++)
          std::cout << "-";
     if(type) std::cout << "+\n";
}

void _row(int size) {
     std::cout << "+";
     for(int i = 0; i < size; i++)
          std::cout << "-";
}

/* funtion to create header */
void _header() {
     _row(9); _row(10); _row(10); _row(11, 1);
     std::cout << "| Brojevi | Kvadrati | Korijeni | Logaritmi |" << std::endl;
     _row(9); _row(10); _row(10); _row(11, 1);
}

/* start creating tables */
void _tableRow(int num) {
     /* print num value */
     std::cout << "| ";
     std::cout.width(8);
     std::cout << std::left << num;
     
     /* print sqr value */
     std::cout << "|";
     std::cout.width(9);
     std::cout << std::right << num*num << ' ';
     
     /* print sqrt value */
     std::cout << "|";
     std::cout.width(9);
     std::cout << std::right << std::setprecision(3) << std::fixed << std::sqrt(num) << ' ';
     
     /* print log value */
     std::cout << "|";
     std::cout.width(10);
     std::cout << std::right << std::setprecision(5) << std::fixed << std::log(num) << " |";
     
     std::cout << std::endl;
} 

int main () {
     /* start doing something */
     int a, b;
     std::cout << "Unesite pocetnu i krajnju vrijednost: ";
     std::cin >> a >> b;
     
     /* start */
     std::cout << '\n';
     _header();
     for(int i = a; i <= b; _tableRow(i++));
     _row(9); _row(10); _row(10); _row(11, 1);
	return 0;
}