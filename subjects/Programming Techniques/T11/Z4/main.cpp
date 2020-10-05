#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

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
	private:
		int broj_timova;
		const int max_br_timova;
		Tim** timovi;
		void timPostoji(const char ime_tima[], const char poruka[], bool postoji = true) {
			if(std::any_of(timovi, timovi + max_br_timova, [ime_tima](const Tim* tim) {
				return tim != nullptr && std::strcmp(tim->DajImeTima(), ime_tima) == 0;
			}) == postoji) 
				throw std::logic_error(poruka);
		}
		int DajPozicijuPrekoImena(const char ime[]) {
			for(int i(0); i < max_br_timova; ++i) 
				if(timovi[i] != nullptr && std::strcmp(ime, timovi[i]->DajImeTima()) == 0)
					return i;
			return max_br_timova;
		}
	public:
		explicit Liga(int velicina_lige);
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
Liga::Liga(int velicina_lige) : broj_timova(0), max_br_timova(velicina_lige), timovi(new Tim*[velicina_lige]{}) 
	{ }
Liga::Liga(std::initializer_list<Tim> lista_timova) : broj_timova(0), max_br_timova(lista_timova.size()),
	timovi(new Tim*[lista_timova.size()]{}) {
	try { 
		for(auto it(lista_timova.begin()); it != lista_timova.end(); ++broj_timova, ++it) 
			timovi[broj_timova] = new Tim(*it); 
	} catch (...) {
		for(int i(0); i < broj_timova; ++i) delete timovi[i], timovi[i] = nullptr;
		throw;
	}
}
Liga::~Liga() { 
	for(int i(0); i < max_br_timova; ++i) delete timovi[i];
	delete[] timovi;
}
Liga::Liga(const Liga &l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(new Tim*[l.max_br_timova]{})  {
	for(int i(0); i < broj_timova; ++i)
		timovi[i] = new Tim(*l.timovi[i]);
}
Liga::Liga(Liga &&l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(l.timovi) {
	l.timovi = nullptr; l.broj_timova = 0;
}
Liga& Liga::operator =(const Liga &l) {
	if(max_br_timova != l.max_br_timova)
		throw std::logic_error("Nesaglasni kapaciteti liga");
	/// start copying
	if(broj_timova < l.broj_timova) {
		for(int i(broj_timova); i < l.broj_timova; ++i)
			timovi[i] = new Tim(*l.timovi[i]);
	} else {
		for(int i(l.broj_timova); i < broj_timova; ++i)
			delete timovi[i], timovi[i] = nullptr;
	}
	int _upperBound(std::min(broj_timova, l.broj_timova));
	for(int i(0); i < _upperBound; ++i) 
		*timovi[i] = *l.timovi[i];
	broj_timova = l.broj_timova;
	return *this;
}
Liga& Liga::operator =(Liga &&l) {
	if(max_br_timova != l.max_br_timova)
		throw std::logic_error("Nesaglasni kapaciteti liga");
	std::swap(broj_timova, l.broj_timova);
	std::swap(timovi, l.timovi);
	return *this;
}
void Liga::DodajNoviTim(const char ime_tima[]) {
	Tim tim(ime_tima); /// brine se i o exceptionu
	
	if(broj_timova == max_br_timova) 
		throw std::range_error("Liga popunjena");
	
	/// check if exists
	this->timPostoji(ime_tima, "Tim vec postoji", true);
		
	// add team
	auto insertPos = std::find_if(timovi, timovi + max_br_timova, [](Tim* tim){return tim == nullptr; });
	*insertPos = new Tim(tim);
	broj_timova++;
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2) {
	this->timPostoji(tim1, "Tim nije nadjen", false);
	this->timPostoji(tim2, "Tim nije nadjen", false);
	timovi[this->DajPozicijuPrekoImena(tim1)]->ObradiUtakmicu(rezultat_1, rezultat_2);
	timovi[this->DajPozicijuPrekoImena(tim2)]->ObradiUtakmicu(rezultat_2, rezultat_1);
	
}

void Liga::IspisiTabelu() {
	/// prvo sortirat tabelu
	auto compFunction = [](const Tim* tim1, const Tim* tim2) -> bool {
		return (tim1 != nullptr && tim2 == nullptr) || (tim1 != nullptr && tim2 != nullptr && 
				(tim1->DajBrojPoena() > tim2->DajBrojPoena() ||
				(tim1->DajBrojPoena() == tim2->DajBrojPoena() && ((tim1->DajGolRazliku() > tim2->DajGolRazliku()) ||
				(tim1->DajGolRazliku() == tim2->DajGolRazliku() && std::strcmp(tim1->DajImeTima(), tim2->DajImeTima()) < 0)))));
	};
	std::sort(timovi, timovi + max_br_timova, compFunction);
	std::for_each(timovi, timovi + broj_timova, [](const Tim* tim) {
		if(tim != nullptr) tim->IspisiPodatke();
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