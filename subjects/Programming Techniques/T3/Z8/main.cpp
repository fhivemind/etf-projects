/* TP, 2017/2018, Tutorijal 3, Zadatak 8 */
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using std::string;

/* function to implement */
string IzdvojiRijec(string text, int wordNum) {
     string word;
     bool _found {false};
     int _words{0};
     
     /* cast string to input stream */
     std::stringstream strIn(text);
     for(;strIn >> word;) {
          _words++;
          if(_words == wordNum) {
               _found = true;
               break;
          }
     }
     
     /* throw error */
     if(!_found) throw std::range_error("Pogresan redni broj rijeci!");
     return word;
}


int main () {
     int pos;
     std::cout << "Unesite redni broj rijeci: ";
     std::cin >> pos;
     
     std::cin.clear();
     std::cin.ignore(10000, '\n');
     
     std::cout << "Unesite recenicu: ";
     string text;
     std::getline(std::cin, text);
     
     try {
          string word = IzdvojiRijec(text, pos);
          std::cout << "Rijec na poziciji " << pos << " je " << word;
     }
     catch (std::range_error _out) {
          std::cout << "IZUZETAK: " << _out.what();
     }
     
	return 0;
}