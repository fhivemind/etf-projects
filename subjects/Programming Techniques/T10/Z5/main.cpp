#include <iostream>
#include <cmath>
#include <iomanip>

#define ERROR 	.00000001

class Ugao {
	private:
		int h, m, s;
		constexpr static double PI = 4 * atan(1);
		constexpr static double CIRCLE_DEG = 360;
		static double UStepene(double x) { return x * CIRCLE_DEG / (2 * PI); }
		static long USekunde(double x) { return static_cast<long>(x * 360 * 60 * 60 / (2 * PI)); }

		static void mod(int &_set, int num, int _mod, int &o) {
			o = 0;
			if(num < 0) {
				_set = _mod - (abs(num) % _mod);
				o = num/_mod - 1;
			}
			else _set = num % _mod;
		}
	public:
		Ugao(double radijani = 0)  { Postavi(radijani); }
		Ugao(int stepeni, int minute, int sekunde) { Postavi(stepeni, minute, sekunde); }
		
		void Postavi(double radijani) { 
			Postavi(DajStepeneIz(radijani), DajMinuteIz(radijani), DajSekundeIz(radijani));
		};
		void Postavi(int h, int m, int s) {
			int o;
			
			mod(Ugao::s, s, 60, o);
			mod(Ugao::m, (m + o + s/60), 60, o); 
			mod(Ugao::h, (h + o + (m + s/60)/60), 360, o); 
		};
		
		double DajRadijane() const { 
			return ((this->DajStepene() + this->DajMinute() /60. + this->DajSekunde() / 3600.) * PI/180.);
		};
		
		void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde) const { 
			stepeni = this->DajStepene(), minute = this->DajMinute(), sekunde = this->DajSekunde(); 
		};

		int DajStepene() const { return this->h; }
		int DajMinute() const { return this->m; }
		int DajSekunde() const { return this->s; }


		void Ispisi() const { std::cout<< std::fixed << std::setprecision(5) << this->DajRadijane(); };
		void IspisiKlasicno() const { 
			std::cout  << this->DajStepene() << "deg " << this->DajMinute() << "min " << this->DajSekunde() << "sec"; };
		
		Ugao &SaberiSa(const Ugao &u) { this->Postavi(this->DajRadijane() + u.DajRadijane()); return *this; };
		Ugao &PomnoziSa(double x) {this->Postavi(this->DajRadijane() * x); return *this; }
		
		friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
		friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
		
		
		const static int DajStepeneIz(double x)  { 
			return (USekunde(x) / 3600) % 360; 
		};
		const static int DajMinuteIz(double x) { 
			return (USekunde(x) / 60 % 60); 
		};
		const static int DajSekundeIz(double x) { 
			return USekunde(x + ERROR) % 60; 
		};
};

Ugao ZbirUglova(const Ugao &u1, const Ugao &u2) {
	return {u1.DajRadijane() + u2.DajRadijane()};
}
Ugao ProduktUglaSaBrojem(const Ugao &u, double x) {
	return {u.DajRadijane() * x};
}

// implementation
//Ugao::Ugao(double radijani = 0) { Postavi(radijani); } zasto ne mogu ovdje?


int main ()
{
	Ugao u(50, 25, 12), v(500, 300, 200), f(50, 30, 10);
	u.SaberiSa(f).SaberiSa(v);                    
	u.IspisiKlasicno(); std::cout << std::endl;
	u.SaberiSa(v).SaberiSa(f).Ispisi(); std::cout << std::endl;
	return 0;
}