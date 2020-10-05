#include <iostream>
#include <stdexcept>
#include <algorithm>


int **KreirajTrougao(int n) {
	if(n <= 0) throw std::domain_error("Broj redova mora biti pozitivan");
	int **p {nullptr};
	/* allocate */
	try {
	     p = new int*[n] {};
	}
	catch(...) {
	     throw; 
	}
	/* start creating arrays */
     try{
          p[0] = new int[n*n];
     }
     catch(...) {
          /* clean space */
          delete [] p;
          throw;
     }
	/* fill array with elements */
	p[0][0] = 1;
	for(int i{1}; i < n; i++) {
		p[i] = p[i-1] + (i-1)*2 + 1;
	     p[i][0] = i+1;
	     p[i][2*i] = i+1;
	     for(int j = 1; j < 2*i; j++) 
	         p[i][j] = p[i-1][j-1];
	}
	return p;
}

/* main  */
int main ()
{
     int n;
     std::cout << "Koliko zelite redova: ";
     std::cin >> n;
     int **p{nullptr};
     try {
          p = KreirajTrougao(n);
     }
     catch(std::bad_alloc) {
          std::cout << "Izuzetak: Nedovoljno memorije!";
          return -1;
     }
     catch(std::exception& e) {
          std::cout << "Izuzetak: " << e.what();
          return -1;
     }
     
     for(int i{0}; i < n; ++i) {
          for(int j{0}; j < 2 * i + 1; ++j)
               std::cout << p[i][j] << " ";
          std::cout << std::endl;
     }
     delete [] p[0];
     delete [] p;
	return 0;
}