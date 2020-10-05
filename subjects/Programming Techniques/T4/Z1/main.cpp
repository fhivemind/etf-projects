/* TP, 2017/2018, Tutorijal 4, Zadatak 1 */
#include <iostream>

/* function to calculate digits */
int Cifre(long long int num, int &c_min, int &c_max) {
     
     c_max = abs(num % 10);
     c_min = abs(num % 10);
     num /= 10;
   
     int ostatak;
     int numCount {1} ;
     for(;abs(num) > 0;) {
          ostatak = abs(num % 10);
          if(c_min > ostatak) c_min = ostatak;
          if(c_max < ostatak) c_max = ostatak;
          num /= 10;
          ++numCount;
     }
     
     return numCount;
}

/* main function */
int main () {
     long long e;
     int digits, mini, maxi;
     std::cout << "Unesite broj: "; std::cin >> e;
     
     digits = Cifre(e, mini, maxi);
     std::cout << "Broj "<< e <<" ima "<< digits <<" cifara, najveca je "<<maxi<<" a najmanja "<<mini<<".";
	return 0;
}