#include <iostream>
#include <cmath>

/* function to check value */
int _sumType(int num) {
     int _temp = 1;
     for(int i = 2; i < num; ((num % i) ? (i++):(_temp+=i++)));
     /* return value */
     if(num == 1) return -1;                 /* special case */
     if(_temp < num) return -1;
     else if(_temp > num) return 1;
     return 0;
}


/* main function */
int main () {
     for(;;) {
          double num;
          std::cout << "Unesite prirodan broj ili 0 za kraj: ";
          std::cin >> num;
          /* validity check */
          if(std::cin) {
               /* check if natural num */
               constexpr double _error{0.0001}; 
               int n{-1}; /* initialize value */
               
               /* error check */
               if((fabs(num - (n = static_cast<int>(num))) > _error) or (n < 0)) {
                    std::cout << "Niste unijeli prirodan broj!\n";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
               }
               else {
                    if(n == 0) {
                         std::cout << "Dovidjenja!";
                         break;
                    }
                    else {
                         /* print */
                         if(_sumType(n) == 1) std::cout << "Broj " << n << " je obilan!\n";
                         else if(_sumType(n) == -1) std::cout << "Broj " << n << " je manjkav!\n";
                         else std::cout << "Broj " << n << " je savrsen!\n";
                    }
               }
          }
          else {
               std::cout << "Niste unijeli prirodan broj!\n";
               std::cin.clear();
               std::cin.ignore(10000, '\n'); 
          }
     }
	return 0;
}