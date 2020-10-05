#include <iostream>

int main () {
     /* input */
     long int a, b, c, d;
     std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
     std::cin >> a >> b >> c;
     std::cout << "Unesite sirinu plocice u centimetrima: \n";
     std::cin >> d;
     
     /* check */
     long int P = (a*b + 2*(a*c + b*c))*10000; 
     long int Z = d*d;
     
     if(Z > 0 && (P % Z == 0)) 
          std::cout << "Za poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m \
sa plocicama dimenzija " << d << "x" << d << "cm\npotrebno je " << P/Z << " plocica.";
     else 
          std::cout << "Poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m \
sa plocicama dimenzija " << d << "x" << d << "cm\nnije izvodljivo bez lomljenja plocica!";
     
	return 0;
}
