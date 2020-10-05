#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>

class Tim {
	private:
		char ime_tima[20];
		int broj_odigranih, broj_pobjeda, broj_nerijesenih, broj_poraza;
		int broj_datih, broj_primljenih, broj_poena;
	public:
		Tim(const char ime[]);
		void ObradiUtakmicu(int broj_datih, int broj_primljenih);
		
		const char *DajImeTima() const { return ime_tima; }
		int DajBrojPoena() const { return broj_pobjeda*3 + broj_nerijesenih; }
		int DajGolRazliku() const { return broj_datih - broj_primljenih; }
		void IspisiPodatke() const;
};
/// implementation of public interface
Tim::Tim(const char ime[]) : 
		broj_odigranih(0), broj_pobjeda(0), broj_nerijesenih(0), broj_poraza(0),
		broj_datih(0), broj_primljenih(0), broj_poena(0) {
	if(std::strlen(ime) > 20) 
		throw std::range_error("Predugacko ime tima");
	std::strcpy(ime_tima, ime);
}

void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih) {
	if(broj_datih < 0 || broj_primljenih < 0)
		throw std::range_error("Neispravan broj golova");
		
 	++Tim::broj_odigranih;
	Tim::broj_datih += broj_datih; Tim::broj_primljenih += broj_primljenih;
	if(broj_datih > broj_primljenih) Tim::broj_poena += 3, Tim::broj_pobjeda++;
	else if(broj_datih == broj_primljenih) Tim::broj_poena += 1, Tim::broj_nerijesenih++;
	else Tim::broj_poraza++;
}
void Tim::IspisiPodatke() const {
	std::cout << std::left << std::setw(20) << this->DajImeTima();
	std::cout << std::right << std::setw(4) << broj_odigranih << std::setw(4) << broj_pobjeda << std::setw(4) << broj_nerijesenih << std::setw(4) << broj_poraza;
	std::cout << std::right << std::setw(4) << broj_datih << std::setw(4) << broj_primljenih << std::setw(4) << broj_poena << std::endl;
}

int main () {
	
 	return 0;
}