/* TP, 2017/2018, Tutorijal 3, Zadatak 1 */
#include <iostream>
#include <deque>
#include <cmath>
#include <limits>

typedef std::deque<int>      IntArr;

/* function to sum integer elements */
inline int DigitSum(long num) {
     int sum{0};
     for(;std::abs(num) > 0;) {
          sum += num % 10;
          num /= 10;
     }
     return sum;
}

/* function to check sum type */
inline bool isDivisibleByTwo(int &num) {
     return static_cast<bool>(DigitSum(num) % 2);
}

/* function to implement */
IntArr IzdvojiElemente(const IntArr &niz, bool check) {
     IntArr elements;
     for(auto num:niz) 
          if(isDivisibleByTwo(num) == !check) elements.push_back(num);
     
     return elements;
}

/* print Array */
void printArray(IntArr niz) {
     int i{0};
     for(auto num:niz) {
          i++;
          std::cout << num << ((i < niz.size()) ? ",": "");
     }
}


int main () {
     /* start */
     int n;
     std::cout << "Koliko zelite unijeti elemenata: ";
     for(;;) {
          std::cin >> n;
          if(!std::cin) {
               std::cin.clear();
               std::cin.ignore(10000, '\n');
          }
          else if(n <= 0) {
               std::cout << "Broj elemenata mora biti veci od 0!";
               return 0;
          }
          else break;
     }
     
     /* input */
     std::cout << "Unesite elemente: ";
     IntArr niz;
     int a;
     for(int i{0}; i < n; i++) {
          std::cin >> a;
          niz.push_back(a);
     }
     
     /* print */
     printArray(IzdvojiElemente(niz, true));
     std::cout << "\n";
     printArray(IzdvojiElemente(niz, false));
     
     
	return 0;
}