#include <iostream>
#include <string>
#include <stdexcept>


class ApstraktniStudent {
protected:
	std::string ime, prezime;
	int br_indeksa, polozenih;
	double prosjek;
	
public:
	virtual ~ApstraktniStudent() {};
	ApstraktniStudent(const std::string& ime, const std::string& prezime, int br_indeksa) :
		ime(ime), prezime(prezime), br_indeksa(br_indeksa), polozenih(0), prosjek(5) { }
		
	std::string DajIme() const { return ime; }
	std::string DajPrezime() const { return prezime; }
	int DajBrojIndeksa() const { return br_indeksa; }
	int DajBrojPolozenih() const { return polozenih; }
	double DajProsjek() const { return prosjek; }
	
	ApstraktniStudent& RegistrirajIspit(int ocjena) {
		if(ocjena < 5 || ocjena > 10)
			throw std::domain_error("Neispravna ocjena");
		if(ocjena > 5) {
			prosjek = ((prosjek*polozenih) + ocjena)/(polozenih + 1);
			++polozenih;
		}
	}
	void PonistiOcjene() { polozenih = 0, prosjek = 5; }
	virtual void IspisiPodatke() const = 0;
	virtual ApstraktniStudent* DajKopiju() const = 0;
};

class StudentBachelor : public ApstraktniStudent {
public: 
	StudentBachelor(const std::string& ime, const std::string& prezime, int br_indeksa) :
		ApstraktniStudent(ime, prezime, br_indeksa) { }
		
	StudentBachelor* DajKopiju() const override {
		return new StudentBachelor(*this);
	}
	void IspisiPodatke() const {
		std::cout << "Student bachelor studija " << this->DajIme() << " " << this->DajPrezime() << ", ";
		std::cout << "sa brojem indeksa " << this->DajBrojIndeksa() << ",\nima prosjek " << this->DajProsjek() << ".\n";
	};
};

class StudentMaster : public ApstraktniStudent {
private: 
	int zavrsio_godine;
public: 
	StudentMaster(const std::string& ime, const std::string& prezime, int br_indeksa, int zavrsio_godine) :
		ApstraktniStudent(ime, prezime, br_indeksa), zavrsio_godine(zavrsio_godine) { }
		
	StudentMaster* DajKopiju() const override {
		return new StudentMaster(*this);
	}
	void IspisiPodatke() const {
		std::cout << "Student master studija " << this->DajIme() << " " << this->DajPrezime() << ", ";
		std::cout << "sa brojem indeksa " << this->DajBrojIndeksa() << ",\nzavrsio bachelor studij godine " << zavrsio_godine;
		std::cout << ",ima prosjek " << this->DajProsjek() << ".\n";
	};
};


int main ()
{
	return 0;
}