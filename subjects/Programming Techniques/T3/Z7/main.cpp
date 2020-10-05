/* TP, 2017/2018, Tutorijal 3, Zadatak 7 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

typedef unsigned long long ull;
typedef std::vector<std::vector<ull>> Mat;
typedef std::vector<ull> IntArr;


/*   calculate number on position on Pascal Triangle
     Recursioun - slow
     faster implementation below 
*/

ull PascalNum(int red, int kolona, const IntArr &redArr) {
     if(kolona == 0 || kolona == red) return 1;
     else if(kolona == 1 || kolona == (red-1)) return static_cast<ull>(red); 
     else return (redArr.at(kolona) + redArr.at(kolona-1));
}

/* calculate number of digits */
inline int NumSize(ull num) {
     int _size{1};
     for(;num >= 10;) {
          _size++;
          num /= 10;
     }
     return _size;
}

/* return maximum size */
int NajvecaSirina(const Mat &matrica) {
     return NumSize(matrica.at(matrica.size()-1).at((matrica.size()-1)/2));
}

/* print matrix */
void PrintMatrix(const Mat &matrica) {
     int width {NajvecaSirina(matrica)+1};
     
     for(int i{0}; i < matrica.size(); i++) {
          for(int j{0}; j <= i; j++) 
               std::cout << std::setw(width) << std::right << matrica.at(i).at(j);
          std::cout << std::endl;
     }
     
}

/* create triangle */
Mat PascalovTrougao(int n) {
     Mat output;
     /* check special cases first */
     if(n == 0) return output;
     else if(n < 0) throw std::domain_error("Broj redova ne smije biti negativan");

     /* create matrix */
     IntArr toAdd;
     for(int i{0}; i < n; i++) {
          for(int j{0}; j <= i; j++) {
               toAdd.push_back(PascalNum(i, j, ((i > 0) ? output.at(i-1) : (IntArr {}))));
          }
          output.push_back(toAdd);
          toAdd.clear();
     }
     
     return output;
}


int main () {
     int n;
     std::cout << "Unesite broj redova: ";
     std::cin >> n;
     try {
          std::cout << "\n";
          PrintMatrix(PascalovTrougao(n));
     }
     catch (std::domain_error _out) {
          std::cout << _out.what();
     }
     
     return 0;
}