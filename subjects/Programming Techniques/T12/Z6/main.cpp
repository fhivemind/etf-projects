#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <algorithm>

template <typename TipEl> class Matrica {
  int br_redova, br_kolona;
  TipEl **elementi;
  char ime_matrice;
  static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
  static void DealocirajMemoriju(TipEl **elementi, int br_redova);
  void KopirajElemente(TipEl **elementi);
  void checkIndex(const int& i, const int& j) const;
public:
  Matrica(int br_redova, int br_kolona, char ime = 0);
  Matrica(const Matrica &m);
  Matrica(Matrica &&m);
  ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
  Matrica &operator=(const Matrica &m);
  Matrica &operator=(Matrica &&m);
  
  /// stream operators
  template <class T>
  friend std::ostream &operator <<(std::ostream &tok, const Matrica<T> &m);
  template <class T>
  friend std::istream &operator >>(std::istream &tok, Matrica<T> &m);
  
  /// friend OPERATORS
  template <class T>
  friend Matrica<T> operator +(const Matrica<T> &m1, const Matrica<T> &m2);
  template <class T>
  friend Matrica<T> operator -(const Matrica<T> &m1, const Matrica<T> &m2);
  template <class T>
  friend Matrica<T> operator *(const Matrica<T> &m1, const Matrica<T> &m2);
  template <class T>
  friend Matrica<T> operator *(const Matrica<T> &m1, const double& p);
  template <class T>
  friend Matrica<T> operator *(const double& p, const Matrica<T> &m1);
  
  /// operators
  Matrica<TipEl> &operator +=(const Matrica<TipEl> &m);
  Matrica<TipEl> &operator -=(const Matrica<TipEl> &m);
  Matrica<TipEl> &operator *=(const Matrica<TipEl> &m);
  Matrica<TipEl> &operator *=(const double &p);
  
  operator std::string() const;
  
  /// controllers
  TipEl* operator [](const int& j);
  TipEl& operator ()(int i, int j);
  
  TipEl* operator [](const int& j) const;
  TipEl operator ()(int i, int j) const;
  
  
  template <class T>
  friend void TestDimension(const Matrica<T> &m1, const Matrica<T> &m2, char znak);
};

/// implementation
template <typename TipEl>
TipEl **Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
  TipEl **elementi(new TipEl *[br_redova] {});
  try {
    for (int i = 0; i < br_redova; i++)
      elementi[i] = new TipEl[br_kolona];
  } catch (...) {
    DealocirajMemoriju(elementi, br_redova);
    throw;
  }
  return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
  for (int i = 0; i < br_redova; i++)
    delete[] elementi[i];
  delete[] elementi;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime)
    : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
      elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
  for (int i = 0; i < br_redova; i++)
    for (int j = 0; j < br_kolona; j++)
      Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m)
    : br_redova(m.br_redova), br_kolona(m.br_kolona),
      ime_matrice(m.ime_matrice),
      elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
  KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m)
    : br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(m.elementi),
      ime_matrice(m.ime_matrice) {
  m.br_redova = 0;
  m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator=(const Matrica<TipEl> &m) {
  if (br_redova < m.br_redova || br_kolona < m.br_kolona) {
    TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
    DealocirajMemoriju(elementi, br_redova);
    elementi = novi_prostor;
  } else if (br_redova > m.br_redova)
    for (int i = m.br_redova; i < br_redova; i++)
      delete elementi[i];
  br_redova = m.br_redova;
  br_kolona = m.br_kolona;
  ime_matrice = m.ime_matrice;
  KopirajElemente(m.elementi);
  return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator=(Matrica<TipEl> &&m) {
  std::swap(br_redova, m.br_redova);
  std::swap(br_kolona, m.br_kolona);
  std::swap(ime_matrice, m.ime_matrice);
  std::swap(elementi, m.elementi);
  return *this;
}



/// IO control
template <class T>
std::istream &operator >>(std::istream &tok, Matrica<T> &m) {
  for (int i = 0; i < m.br_redova; i++)
    for (int j = 0; j < m.br_kolona; j++) {
      std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
      tok >> m.elementi[i][j];
    }
  return tok;
}

template <class T>
std::ostream &operator <<(std::ostream &tok, const Matrica<T> &m) {
  int _width(tok.width());
  for (int i = 0; i < m.br_redova; i++) {
    for (int j = 0; j < m.br_kolona; j++)
      tok << std::setw(_width) << m.elementi[i][j];
    tok << std::endl;
  }
  return tok;
}

/// check size function
template <class T>
void TestDimension(const Matrica<T> &m1, const Matrica<T> &m2, char znak) {
  if(znak == '+' || znak == '-') {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
      throw std::domain_error("Matrice nemaju jednake dimenzije!");
  }
  else if(znak == '*') {
    if (m1.br_kolona!=m2.br_redova) 
      throw std::domain_error("Matrice nisu saglasne za mnozenje");
  }
}

/// +, -, +=, -=, *, *=
template <class T>
Matrica<T> operator +(const Matrica<T> &m1, const Matrica<T> &m2) {
  TestDimension(m1, m2, '+');
  
  Matrica<T> m3(m1.br_redova, m1.br_kolona);
  for (int i = 0; i < m1.br_redova; i++)
    for (int j = 0; j < m1.br_kolona; j++)
      m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
  return m3;
}
template <class T>
Matrica<T> operator -(const Matrica<T> &m1, const Matrica<T> &m2) {
  TestDimension(m1, m2, '-');
    
  Matrica<T> m3(m1.br_redova, m1.br_kolona);
  for (int i = 0; i < m1.br_redova; i++)
    for (int j = 0; j < m1.br_kolona; j++)
      m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
  return m3;
}

template <class T>
Matrica<T>& Matrica<T>::operator +=(const Matrica<T> &m1) {
  TestDimension(*this, m1, '+');
  
  for (int i = 0; i < br_redova; i++)
    for (int j = 0; j < br_kolona; j++)
      elementi[i][j] += m1.elementi[i][j];
  return *this;
}
template <class T>
Matrica<T>& Matrica<T>::operator -=(const Matrica<T> &m1) {
  TestDimension(*this, m1, '-');
  
  for (int i = 0; i < br_redova; i++)
    for (int j = 0; j < br_kolona; j++)
      elementi[i][j] -= m1.elementi[i][j];
  return *this;
}


template <class T>
Matrica<T> operator *(const Matrica<T> &m1, const Matrica<T> &m2) {
  TestDimension(m1, m2, '*');
  
  Matrica<T> m3(m1.br_redova, m2.br_kolona);
  for (int i = 0; i < m3.br_redova; i++) {
    for (int j = 0; j < m3.br_kolona; j++) {
      T _sum(0);
      for (int k(0); k < m1.br_kolona; ++k)
        _sum += m1.elementi[i][k] * m2.elementi[k][j];
      m3.elementi[i][j] = _sum;
    }
  }
  return m3;
}

template <class T>
Matrica<T>& Matrica<T>::operator *=(const Matrica<T> &m1) {
  return *this = *this * m1;
}

template <class T>
Matrica<T> operator *(const Matrica<T> &m1, const double &p) {
  Matrica<T> m2(m1.br_redova, m1.br_kolona);
  for (int i = 0; i < m2.br_redova; i++) 
    for (int j = 0; j < m2.br_kolona; j++) 
      m2.elementi[i][j] = m1.elementi[i][j]*p;
      
  return m2;
}

template <class T>
Matrica<T> operator *(const double &p, const Matrica<T> &m) {
  return m * p;
}

template <class T>
Matrica<T>& Matrica<T>::operator *=(const double &p) {
  for (int i = 0; i < br_redova; i++) 
    for (int j = 0; j < br_kolona; j++) 
      elementi[i][j] *= p;
  return *this;
}



template <class T>
void Matrica<T>::checkIndex(const int& i, const int& j) const {
  if(i <= 0 || i > br_redova || j <= 0 || j > br_kolona) 
    throw std::range_error("Neispravan indeks");
}


template <class T>
T* Matrica<T>::operator [](const int& j) { return elementi[j]; }

template <class T>
T&  Matrica<T>::operator ()(int i, int j)  { this->checkIndex(i, j); return elementi[i-1][j-1]; }

template <class T>
T* Matrica<T>::operator [](const int& j) const  { return elementi[j]; }

template <class T>
T  Matrica<T>::operator ()(int i, int j) const { this->checkIndex(i, j); return elementi[i-1][j-1]; }


template <class T>
Matrica<T>::operator std::string() const {
  std::string output("{");
  for(int i(0); i < br_redova; ++i) {
    output += "{";
    for(int j(0); j < br_kolona; ++j) {
        output += std::to_string(int(this->elementi[i][j]));
        if(j < br_kolona - 1) output += ",";
    }
    output += "}";
    if(i < br_redova - 1) output += ",";
  }
  return output += "}";
}

int main() {
int m, n;
    std::cout << "Unesi broj redova i kolona za matrice:\n";
    std::cin >> m >> n;
    try {
        Matrica<double> a(m, n, 'A'), b(m, n, 'B');
        std::cout << "Unesi matricu A:\n";
        std::cin >> a;
        std::cout << "Unesi matricu B:\n";
        std::cin >> b;
        std::cout.width(10);
        std::cout << a;
        std::cout << b;
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch (std::domain_error e) {
        std::cout << e.what();
    }
    catch (std::range_error e) {
        std::cout << e.what();
    }
    catch (std::logic_error e) {
        std::cout << e.what();
    }
    std::cin.get();
    return 0;
  	return 0;
}
