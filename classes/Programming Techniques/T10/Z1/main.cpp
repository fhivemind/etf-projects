#include <iostream>
#include <stdexcept>
#include <cmath>
 

class StedniRacun {
	public:
		StedniRacun(double vr = 0) {
			if(vr < 0) throw std::logic_error("Nedozvoljeno pocetno stanje");
			val = vr;
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
		
	private:
		double val;
};


int main () {

	return 0;
}