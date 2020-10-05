#include <iostream>
#include <cmath>
#include <iomanip>

class Ugao {
	private:
		double radijani;
		constexpr static double PI = 4 * atan(1);
		constexpr static double CIRCLE_DEG = 360;
		static double UStepene(double x) { return x * CIRCLE_DEG / (2 * PI); }
		void ResetRadijan() { for(bool _up; (_up = radijani > 2*PI) || radijani < 0; radijani += (_up ? -1:1) * 2*PI); }
		static long USekunde(double x) { return (x * 360 * 60 * 60 / (2 * PI)); }
	
	public:
		Ugao(double radijani = 0)  { Postavi(radijani); }
		Ugao(int stepeni, int minute, int sekunde) { Postavi(stepeni, minute, sekunde); }
		
		void Postavi(double radijani) { Ugao::radijani = radijani, this->ResetRadijan(); };
		void Postavi(int stepeni, int minute, int sekunde) {
			Ugao::radijani = (stepeni + minute/60. + sekunde/3600.) * 2 * PI/CIRCLE_DEG;
			this->ResetRadijan();
		}
		
		double DajRadijane() const { return this->radijani; };
		void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde) const { 
			stepeni = this->DajStepene(), minute = this->DajMinute(), sekunde = this->DajSekunde(); 
		};
		int DajStepene() const { 
			return (USekunde(this->DajRadijane()) / 3600) % 360; 
		};
		int DajMinute() const { 
			return USekunde(this->DajRadijane()) / 60 % 60; 
		};
		int DajSekunde() const { 
			return USekunde(this->DajRadijane()) % 60; 
		};
		void Ispisi() const { std::cout<< std::fixed << std::setprecision(5) << this->DajRadijane(); };
		void IspisiKlasicno() const { 
			std::cout  << this->DajStepene() << "deg " << this->DajMinute() << "min " << this->DajSekunde() << "sec"; };
		
		Ugao &SaberiSa(const Ugao &u) { this->Postavi(this->DajRadijane() + u.DajRadijane()); return *this; };
		Ugao &PomnoziSa(double x) {this->Postavi(this->DajRadijane() * x); return *this; }
		
		friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
		friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
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
	return 0;
}