#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <memory>

/// TEAM CLASS
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
/// LEAGUE CLASS
class Liga {
	using PokNaTim = std::unique_ptr<Tim>;
	private:
		std::vector<PokNaTim> timovi;
		void timPostoji(const char ime_tima[], const char poruka[], bool postoji = true) {
			if(std::any_of(timovi.begin(), timovi.end(), [ime_tima](const PokNaTim& tim) {
				return tim.get() != nullptr && std::strcmp(tim->DajImeTima(), ime_tima) == 0;
			}) == postoji) 
				throw std::logic_error(poruka);
		}
		int DajPozicijuPrekoImena(const char ime[]) {
			for(int i(0); i < timovi.size(); ++i) 
				if(timovi[i].get() != nullptr && std::strcmp(ime, timovi[i]->DajImeTima()) == 0)
					return i;
			return timovi.size();
		}
	public:
		explicit Liga();
		explicit Liga(std::initializer_list<Tim> lista_timova);
		~Liga();
		Liga(const Liga &l);
		Liga(Liga &&l);
		Liga &operator =(const Liga &l);
		Liga &operator =(Liga &&l);
		void DodajNoviTim(const char ime_tima[]);
		void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2);
		
		void IspisiTabelu();
};

// implementation of LEAGUE class public interface
Liga::Liga() { }
Liga::Liga(std::initializer_list<Tim> lista_timova){
	for(auto it(lista_timova.begin()); it != lista_timova.end(); ++it) 
		timovi.push_back(PokNaTim(new Tim(*it))); 
}
Liga::~Liga() { }
Liga::Liga(const Liga &l)  {
	for(int i(0); i < l.timovi.size(); ++i)
		timovi.push_back(PokNaTim(new Tim(*l.timovi[i])));
}
Liga::Liga(Liga &&l) { std::swap(timovi, l.timovi); }
Liga& Liga::operator =(const Liga &l) {
	/// start copying
	if(timovi.size() < l.timovi.size())
		for(int i(timovi.size()); i < l.timovi.size(); ++i)
			timovi.push_back(PokNaTim(new Tim(*l.timovi[i])));
	else 
		timovi.resize(l.timovi.size());
	
	int _upperBound(std::min(timovi.size(), l.timovi.size()));
	for(int i(0); i < _upperBound; ++i) 
		*timovi[i] = *l.timovi[i];
	return *this;
}
Liga& Liga::operator =(Liga &&l) {
	std::swap(timovi, l.timovi);
	l.timovi.clear();
	return *this;
}
void Liga::DodajNoviTim(const char ime_tima[]) {
	Tim tim(ime_tima); /// brine se i o exceptionu
	
	/// check if exists
	this->timPostoji(ime_tima, "Tim vec postoji", true);

	timovi.push_back(PokNaTim(new Tim(tim)));
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2) {
	this->timPostoji(tim1, "Tim nije nadjen", false);
	this->timPostoji(tim2, "Tim nije nadjen", false);
	timovi[this->DajPozicijuPrekoImena(tim1)]->ObradiUtakmicu(rezultat_1, rezultat_2);
	timovi[this->DajPozicijuPrekoImena(tim2)]->ObradiUtakmicu(rezultat_2, rezultat_1);
}

void Liga::IspisiTabelu() {
	/// prvo sortirat tabelu
	auto compFunction = [](const PokNaTim& tim1, const PokNaTim& tim2) -> bool {
		return (tim1.get() != nullptr && tim2.get() == nullptr) || (tim1.get() != nullptr && tim2.get() != nullptr && 
				(tim1->DajBrojPoena() > tim2->DajBrojPoena() ||
				(tim1->DajBrojPoena() == tim2->DajBrojPoena() && ((tim1->DajGolRazliku() > tim2->DajGolRazliku()) ||
				(tim1->DajGolRazliku() == tim2->DajGolRazliku() && std::strcmp(tim1->DajImeTima(), tim2->DajImeTima()) < 0)))));
	};
	std::sort(timovi.begin(), timovi.end(), compFunction);
	std::for_each(timovi.begin(), timovi.end(), [](const PokNaTim& tim) {
		if(tim.get() != nullptr) tim->IspisiPodatke();
	});
}
/// implementation of TEAM class public interface
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

/// IMPLEMENTATION OF MAIN LOGIC
int main () {

 	return 0;
}