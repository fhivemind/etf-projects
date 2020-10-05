#include <iostream>
#include <cmath>

class Kompleksni {
  double re, im;

public:
  Kompleksni(double re = 0, double im = 0) : re(re), im(im) {}
  friend Kompleksni operator+(const Kompleksni &a) { return a; }
  friend Kompleksni operator-(const Kompleksni &a) { return {-a.re, -a.im}; }
  friend Kompleksni operator+(const Kompleksni &a, const Kompleksni &b) {
    return {a.re + b.re, a.im + b.im};
  }
  friend Kompleksni operator-(const Kompleksni &a, const Kompleksni &b) {
    return Kompleksni(a.re - b.re, a.im - b.im);
  }
  friend Kompleksni operator*(const Kompleksni &a, const Kompleksni &b) {
    return {a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
  }
  friend Kompleksni operator/(const Kompleksni &a, const Kompleksni &b) {
    double pomocna(b.re * b.re + b.im * b.im);
    return {(a.re * b.re + a.im * b.im) / pomocna,
            (a.im * b.re - a.re * b.im) / pomocna};
  }
  friend bool operator==(const Kompleksni &a, const Kompleksni &b) {
    return a.re == b.re && a.im == b.im;
  }
  friend bool operator!=(const Kompleksni &a, const Kompleksni &b) {
    return !(a == b);
  }
  friend Kompleksni &operator+=(Kompleksni &a, const Kompleksni &b) {
    a.re += b.re;
    a.im += b.im;
    return a;
  }
  friend Kompleksni &operator-=(Kompleksni &a, const Kompleksni &b) {
    a.re -= b.re;
    a.im -= b.im;
    return a;
  }
  friend Kompleksni &operator*=(Kompleksni &a, const Kompleksni &b) {
    double pomocna(a.re * b.im + a.im * b.re);
    a.re = a.re * b.re - a.im * b.im;
    a.im = pomocna;
    return a;
  }

  friend Kompleksni &operator/=(Kompleksni &a, const Kompleksni &b) {
    double pom1(a.im * b.re - a.re * b.im), pom2(b.re * b.re + b.im * b.im);
    a.re = (a.re * b.re + a.im * b.im) / pom2;
    a.im = pom1 / pom2;
    return a;
  }
  friend std::ostream &operator<<(std::ostream &tok, const Kompleksni &a) {
  	if(a.re == 0 && a.im == 0) return tok << 0;
  	if (a.re != 0) tok << a.re;
	  if (a.im == 0) return tok;
	  
  	if(a.im > 0 && a.re != 0) tok << "+";
  	else if(a.im < 0) tok << "-";
  	if(::fabs(a.im) != 1) tok << ::fabs(a.im);
  	return tok << "i"; 
  }
  friend std::istream &operator>>(std::istream &tok, Kompleksni &a);
  friend double real(const Kompleksni &a) { return a.re; }
  friend double imag(const Kompleksni &a) { return a.im; }
  friend double abs(const Kompleksni &a) {
    return std::sqrt(a.re * a.re + a.im * a.im);
  }
  friend double arg(const Kompleksni &a) { return std::atan2(a.im, a.re); }
  friend Kompleksni conj(const Kompleksni &a) { return {a.re, -a.im}; }
  friend Kompleksni sqrt(const Kompleksni &a) {
    double rho(std::sqrt(abs(a))), phi(arg(a) / 2);
    return {rho * cos(phi), rho * sin(phi)};
  }
};
std::istream &operator>>(std::istream &tok, Kompleksni &a) {
  char znak;
  tok >> std::ws; // "Progutaj" razmake...
  if (tok.peek() != '(') {
    tok >> a.re;
    a.im = 0;
  } else {
    tok >> znak >> a.re >> znak;
    if (znak != ',')
      tok.setstate(std::ios::failbit);
    tok >> a.im >> znak;
    if (znak != ')')
      tok.setstate(std::ios::failbit);
  }
  return tok;
}

int main() { 
//AT1 testiranje raznih varijanti ispisa
 std::cout << Kompleksni(0) << " " << Kompleksni(1) << " " << Kompleksni(5) << " "
    << Kompleksni(-1) << " " << Kompleksni(-5) << " " << Kompleksni(0, 1) << " "
    << Kompleksni(0, -1) << " " << Kompleksni(0, 5) << " " << Kompleksni(0, -5) << std::endl;
	return 0; }