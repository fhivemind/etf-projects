/* TP, 2017/2018, Tutorijal 4, Zadatak 5 */
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using std::cin; using std::cout;

template <typename VekType>
VekType Presjek(VekType v1, VekType v2) {
     VekType output;
     
     for(int i {0}; i < v1.size(); ++i) 
          for(int j {0}; j < v2.size(); ++j) 
               if(v1.at(i) == v2.at(j) && std::find(output.begin(), output.end(), v1.at(i)) == output.end()) 
                    output.push_back(v1.at(i));
          
     return output;
}

int main () {
     /* za realne brojeve ->- */
     cout << "Test za realne brojeve...\n";
     std::vector<int>A, B;
     int sizeA, sizeB, num;
     
     cout << "Unesite broj elemenata prvog vektora: "; 
     cin >> sizeA;
     cout << "Unesite elemente prvog vektora: ";
     for(int i(0); i < sizeA; ++i) {
          std::cin >> num;
          A.push_back(num);
     }
     
     cout << "Unesite broj elemenata drugog vektora: "; 
     cin >> sizeB;
     cout << "Unesite elemente drugog vektora: ";
     for(int i(0); i < sizeB; ++i) {
          std::cin >> num;
          B.push_back(num);
     }
     
     cout << "Zajednicki elementi su: ";
     std::vector<int>ZajednickiInt {Presjek(A, B)};
     for(int i = 0; i < ZajednickiInt.size()-1; ++i) cout << ZajednickiInt.at(i) << ' ';
     if(!ZajednickiInt.empty())  cout << ZajednickiInt.at(ZajednickiInt.size()-1);
     
     /* za stringove */
     cout << "\n\nTest za stringove...\n";
     std::vector<std::string> strA, strB;
     int sizeAstr, sizeBstr;
     std::string rec;
     
     
     cout << "Unesite broj elemenata prvog vektora: "; 
     cin >> sizeAstr;
     
     /* empty buffer before entering reading */
     cin.ignore(10000, '\n');
     
     cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
     for(int i(0); i < sizeAstr; ++i) {
          std::getline(std::cin, rec);
          strA.push_back(rec);
     }
     
     cout << "Unesite broj elemenata drugog vektora: "; 
     cin >> sizeBstr;
     
     /* empty buffer before entering reading */
     cin.ignore(10000, '\n');
     
     cout << "Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
     for(int i(0); i < sizeBstr; ++i) {
          std::getline(std::cin, rec);
          strB.push_back(rec);
     }
     
     cout << "Zajednicki elementi su:";
     std::vector<std::string>ZajednickiStr {Presjek(strA, strB)};
     for(auto element:ZajednickiStr)
          cout << '\n' << element;
	return 0;
}