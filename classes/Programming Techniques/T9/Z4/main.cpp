#include <iostream>
#include <stdexcept>

class Sat {
	public:
		// static functions
		static bool DaLiJeIspravno(const int& h, const int& m, const int& s) {
			return (isValidH(h) && isValidMS(m) && isValidMS(s));
		}
		static int Razmak(const Sat& t1, const Sat& t2) {
			return toSeconds(t1) - toSeconds(t2);
		}
		// inspectors
		void Ispisi() const {
			std::cout << 	((DajSate() < 10) ? "0":"") << DajSate() << ":" << 
						((DajMinute() < 10) ? "0":"") << DajMinute() << ":" << 
						((DajSekunde() < 10) ? "0":"") << DajSekunde();
		}
		int DajSate() const { return h; }
		int DajMinute() const { return m; }
		int DajSekunde() const { return s; }
		
		// mutators
		void Postavi(const int& h, const int& m, const int& s) { 
			if(!DaLiJeIspravno(h, m, s)) throw std::domain_error("Neispravno vrijeme");
			Sat::h = h; Sat::m = m; Sat::s = s;
		}
		void PostaviNormalizirano(int h, int m, int s) { 
			this->Postavi(0, 0, 0);
			int o;
			mod(Sat::s, s, 60, o);
			mod(Sat::m, (m + o + s/60), 60, o); 
			mod(Sat::h, (h + o + (m + s/60)/60), 24, o); 
		}
		
		Sat &Sljedeci() 		{ this->PostaviNormalizirano(Sat::h, Sat::m, Sat::s + 1); return *this; }
		Sat &Prethodni() 		{ this->PostaviNormalizirano(Sat::h, Sat::m, Sat::s - 1); return *this; }
		Sat &PomjeriZa(int s) 	{ this->PostaviNormalizirano(Sat::h, Sat::m, Sat::s + s); return *this; }
		
		friend int BrojSekundiIzmedju(const Sat& t1, const Sat& t2);
	
	private:
		int h, m, s;
		
		// help functions
		static int toSeconds(const Sat& t) { return (t.h * 60 * 60 + t.m * 60 + t.s); }
		static bool isValidH(const int &h) { return (h >= 0 && h <= 23); }
		static bool isValidMS(const int &t) { return (t >= 0 && t <= 60); }
		static void mod(int &_set, int num, int _mod, int &o) {
			o = 0;
			if(num < 0) {
				_set = _mod - (abs(num) % _mod);
				o = num/_mod - 1;
			}
			else _set = num % _mod;
		}
};

/// friend function
int BrojSekundiIzmedju(const Sat& t1, const Sat& t2) {
	return Sat::toSeconds(t1) - Sat::toSeconds(t2);
}


int main () {
	return 0;
}