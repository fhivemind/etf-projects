/* TP, 2017/2018, Tutorijal 4, Zadatak 2 */
#include <iostream>
#include <algorithm>
#include <string>

using std::string;


/* function to swap two elements (could have been generic) */
void swap(char &a, char &b) {
     char temp {a};
     a = b;
     b = temp;
}


/* function to reverse string */
void IzvrniString(string &input) {
     size_t i{0}, j {input.length()-1};
     for(;i < j;) { 
          swap(input.at(i), input.at(j));
          ++i;
          --j;
     }
     //a moglo je i ovako
     //std::reverse(input.begin(), input.end());
}


int main ()
{
     string input;
     std::cout << "Unesi string: ";
     std::getline(std::cin, input);
     
     IzvrniString(input);
     
     std::cout << "Izvrnuti string je: ";
     std::cout << input;
	return 0;
}