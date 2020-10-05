/* TP, 2017/2018, Tutorijal 4, Zadatak 4 */
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cmath>

using std::string;

/* function to read any arithmetic-typed data */
template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
void UnosBroja(string promptText, string errorMessage, T &var) {
     T tempInputVar;
     for(;;) {
          std::cout << promptText << std::endl;
          std::cin >> tempInputVar;
          if(!std::cin || std::cin.peek() != '\n') {
               std::cin.clear();
               std::cin.ignore(10000, '\n');
               std::cout << errorMessage << std::endl;
          }
          else {
               var = tempInputVar;
               break;
          }
     }
}

/* main function to do nonsense... */
int main () {
     double baza;
     UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...", baza);
     int eksponent;
     std::cout << std::endl;
     UnosBroja("Unesite cjelobrojni eksponent: ", "Neispravan unos, pokusajte ponovo...", eksponent);
     
     std::cout << std::endl << baza << " na " << eksponent << " iznosi " << std::pow(baza, eksponent);
	return 0;
}