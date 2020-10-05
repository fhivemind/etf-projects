/* TP, 2017/2018, Tutorijal 4, Zadatak 3 */
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using std::string;
using VekStr = std::vector<string>;

/* function to transform string into lowercase (for checking) */
string toLower (string input) {
     string output{input};
     for(int i{0}; i<input.length(); ++i) 
          output.at(i) = tolower(input.at(i));
     return output;
}

/* function to select elements that repeat within input array */
void ZadrziDuplikate(VekStr &input) {
     /* check for empty array */
     if(input.empty()) {
          input = {};
          return;
     }
     
     VekStr output;
     bool _exist{false};
     for(size_t i {0}; i < input.size()-1; ++i) {
          for(size_t j {i+1}; j < input.size(); ++j) {
               if(input.at(i) == input.at(j)) {
                    _exist = false;
                    for(int k{0}; k < output.size(); k++) {
                         if(output.at(k) == input.at(i)) {
                              _exist = true;
                              break;
                         }
                    }
                    if(!_exist) output.push_back(input.at(i));
               }
          }    
     }
     
     input = output;
}

/* function to find first and last word in array in alphabetical order */
void IzdvojiKrajnjeRijeci(VekStr input, string &firstWord, string &lastWord) {
     if(input.size() == 0) {
          firstWord = "";
          lastWord = "";
          return;
     }
     
     firstWord = input.at(0);
     lastWord = input.at(0);
     for(int i {0}; i < input.size(); ++i) {
          if(toLower(firstWord) > toLower(input.at(i)))
               firstWord = input.at(i);
          if(toLower(lastWord) < toLower(input.at(i)))
               lastWord = input.at(i);
     }
     
}

int main () {
     int size;
     std::cout << "Koliko zelite unijeti rijeci: ";
     std::cin >> size;
     
     string str, first, last;
     VekStr arrayInput;
     std::cout << "Unesite rijeci: ";
     for(int i{0}; i < size; ++i) {
          std::cin >> str;
          arrayInput.push_back(str);
     }
     
     IzdvojiKrajnjeRijeci(arrayInput, first, last);
     ZadrziDuplikate(arrayInput);
     
     std::cout << "\nPrva rijec po abecednom poretku je: " << first;
     std::cout << "\nPosljednja rijec po abecednom poretku je: " << last;
     std::cout << "\nRijeci koje se ponavljaju su: ";
     for(int i{0}; i < arrayInput.size()-1; ++i)
          std::cout << arrayInput.at(i) << ' ';
     
     if(!arrayInput.empty()) 
          std::cout << arrayInput.at(arrayInput.size()-1);
     
	return 0;
}