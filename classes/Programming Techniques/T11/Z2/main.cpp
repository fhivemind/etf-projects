#include <iostream>
#include <stdexcept>
#include <cmath>
 

class StedniRacun {
	public:
		StedniRacun(double vr = 0) {
			if(vr < 0) throw std::logic_error("Nedozvoljeno pocetno stanje");
			val = vr;
			brojKreiranih++; brojZivih++;
		}
		StedniRacun(const StedniRacun& vr) {
			val = vr.DajStanje();
			brojKreiranih++; brojZivih++;
		}
		~StedniRacun() {
			brojZivih--;
		}
		/// functions
		StedniRacun& Ulozi(double val) { 
			if(val < 0 && std::fabs(val) > this->val) throw std::logic_error("Transakcija odbijena");
			this->val += val; 
			return *this; 
		}
		StedniRacun& Podigni(double val) {
			if(val > this->val) throw std::logic_error("Transakcija odbijena");
			this->val -= val;
			return *this;
		}
		
		double DajStanje() const { return this->val; }
		
		double ObracunajKamatu(double proc) {
			if(proc < 0) throw std::logic_error("Nedozvoljena kamatna stopa");
			return this->val += this->val * proc/100;
		}
		static int DajBrojKreiranih() { return brojKreiranih; }
		static int DajBrojAktivnih() { return brojZivih; }
		
	private:
		double val;
		static int brojKreiranih, brojZivih;
};

/// initialise 
int StedniRacun::brojKreiranih (0);
int StedniRacun::brojZivih (0);

int main () {

	return 0;
}