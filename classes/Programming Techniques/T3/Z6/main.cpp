/* TP, 2017/2018, Tutorijal 3, Zadatak 6 */
#include <iostream>
#include <iomanip>
#include <vector>

typedef std::vector<std::vector<int>> Mat;
typedef std::vector<int> IntArr;

/* calculate number of digits */
inline int NumSize(long num) {
     int _size{0};
     if(num < 0) _size++;
     for(;std::abs(num) > 0;) {
          _size++;
          num /= 10;
     }
     return _size;
}

/* find greatest number */
int NajvecaSirina(const Mat &matrica) {
     int max{0}, _tempSave{0};
     for(int i{0}; i < matrica.size(); i++)
          for(int j{0}; j < matrica.at(i).size(); j++) 
               if((_tempSave = NumSize(matrica.at(i).at(j))) > max)
                    max = _tempSave;
                    
     return max;
}

/* print matrix */
void PrintMatrix(const Mat &matrica) {
     int _width = NajvecaSirina(matrica)+1;
     for(auto x:matrica) {
          for(auto num:x) 
               std::cout << std::right << std::setw(_width) << num;
          std::cout << "\n";
     }
}

/* function to implement */
Mat KroneckerovProizvod(const IntArr &a, const IntArr &b) {
     Mat output;
     
     IntArr temp;
     for(int i{0}; i < a.size(); i++) {
          for(int j{0}; j < b.size(); j++) 
               temp.push_back(a.at(i)*b.at(j));
          if(!temp.empty()) output.push_back(temp);
          temp.clear();
     }
     
     return output;
}

/* main function */
int main () {
     int sizeA, sizeB, num;
     std::cout << "Unesite broj elemenata prvog vektora: ";
     std::cin >> sizeA;
     
     IntArr A;
     std::cout << "Unesite elemente prvog vektora: ";
     for(int i{0}; i < sizeA; i++) {
          std::cin >> num;
          A.push_back(num);
     }
     
     std::cout << "Unesite broj elemenata drugog vektora: ";
     std::cin >> sizeB;
     
     IntArr B;
     std::cout << "Unesite elemente drugog vektora: ";
     for(int i{0}; i < sizeB; i++) {
          std::cin >> num;
          B.push_back(num);
     }
     
     std::cout << "\n";
     Mat output {KroneckerovProizvod(A, B)};
     PrintMatrix(output);
     
	return 0;
}