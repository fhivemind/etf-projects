#include <iostream>
#include <stdexcept>

class Sat {
	public:
		// static functions
		static bool DaLiJeIspravno(const int& h, const int& m, const int& s) {
			return (isValidH(h) && isValidMS(m) && isValidMS(s));
		}
		static int Razmak(const Sat& t1, const Sat& t2) {
			return t1.sekunde - t2.sekunde;
		}
		// inspectors
		void Ispisi() const {
			// mali performance overkill
			std::cout << 	((DajSate() < 10) ? "0":"") << DajSate() << ":" << 
						((DajMinute() < 10) ? "0":"") << DajMinute() << ":" << 
						((DajSekunde() < 10) ? "0":"") << DajSekunde();
		}
		int DajSate() const { return (sekunde / 3600) % 24; }
		int DajMinute() const { return (sekunde / 60 - DajSate() * 60) % 60; }
		int DajSekunde() const { return (sekunde - DajMinute() * 60 - DajSate() * 3600); }
		
		// mutators
		void Postavi(const int& h, const int& m, const int& s) { 
			if(!DaLiJeIspravno(h, m, s)) throw std::domain_error("Neispravno vrijeme");
			sekunde = h * 3600 + m * 60 + s;
		}
		void PostaviNormalizirano(int h, int m, int s) { 
			int n_s, n_m, n_h, o;
			mod(n_s, s, 60, o);
			mod(n_m, (m + o + s/60), 60, o); 
			mod(n_h, (h + o + (m + s/60)/60), 24, o); 
			this->Postavi(n_h, n_m, n_s);
		}
		
		Sat &Sljedeci() 		{ this->PostaviNormalizirano(DajSate(), DajMinute(), DajSekunde() + 1); return *this; }
		Sat &Prethodni() 		{ this->PostaviNormalizirano(DajSate(), DajMinute(), DajSekunde() - 1); return *this; }
		Sat &PomjeriZa(int s) 	{ this->PostaviNormalizirano(DajSate(), DajMinute(), DajSekunde() + s); return *this; }
		
		friend int BrojSekundiIzmedju(const Sat& t1, const Sat& t2);
	
	private:
		int sekunde;
		
		// help functions
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
	return t1.sekunde - t2.sekunde;
}


int main () {
	
	return 0;
}