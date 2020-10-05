//TP 2017/2018: Tutorijal 14, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <vector>
#include <fstream>
#include <functional>
#include <string>

class Spremnik {
protected:
    const char *naziv, *ime_stvari;
    double tezina;
public:
    Spremnik(const char naziv[], const char ime_stvari[], const double& tezina) : 
        naziv(naziv), ime_stvari(ime_stvari), tezina(tezina) {}
    virtual ~Spremnik() {}
    
    double DajTezinu() const { return tezina; };
    
    virtual void Ispisi() const;
    virtual double DajUkupnuTezinu() const = 0;
    virtual Spremnik* DajKopiju() const = 0;
};

void Spremnik::Ispisi() const {
    std::cout << "Vrsta spremnika: " << naziv << std::endl;
    std::cout << "Sadrzaj :" << ime_stvari << std::endl;
    std::cout << "Vlastita tezina: " << this->DajTezinu() << " kg" << std::endl;
    std::cout << "Ukupna tezina: " << this->DajUkupnuTezinu() << " kg" << std::endl;
}

class Sanduk : public Spremnik {
private:
    int broj_stvari;
    double tezina_predmeta;
public:
    Sanduk(const double& tezina, const char ime_stvari[], int broj_stvari, const double& tezina_predmeta) :
        Spremnik("Sanduk", ime_stvari, tezina), tezina_predmeta(tezina_predmeta) {}
    
    double DajUkupnuTezinu() const override { return broj_stvari * tezina_predmeta + DajTezinu(); }
    
    Spremnik* DajKopiju() const override { return new Sanduk(*this); }
};

class Bure : public Spremnik {
private:
    double tezina_tecnosti;
public:
    Bure(const double& tezina, const char ime_tecnosti[], const double& tezina_tecnosti) : 
        Spremnik("Bure", ime_tecnosti, tezina), tezina_tecnosti(tezina_tecnosti) {}
        
    double DajUkupnuTezinu() const override { return tezina_tecnosti + DajTezinu(); }
    
    Spremnik* DajKopiju() const override { return new Bure(*this); }
};


/// SKLADISTE CLASS
class Skladiste {
private:
    int max_broj_objekata, broj_reg;
    Spremnik** objekti;
public:
    explicit Skladiste(int max_value) : max_broj_objekata(max_value), broj_reg(0), objekti(new Spremnik*[max_value]{}) {}
    ~Skladiste();
    
    Skladiste(const Skladiste& s);
    Skladiste(Skladiste&& s);
    Skladiste& operator=(const Skladiste& s);
    Skladiste& operator=(Skladiste&& s);
    
    void DodajSpremnik(Spremnik* spremnik) {
        if(broj_reg >= max_broj_objekata) {
            delete spremnik; 
            throw std::domain_error("Popunjeno skladiste");
        }
        objekti[broj_reg++] = spremnik;
    }
    Skladiste& DodajSanduk(const double& tezina, const char ime_stvari[], int broj_stvari, const double& tezina_predmeta) {
        DodajSpremnik(new Sanduk(tezina, ime_stvari, broj_stvari, tezina_predmeta));
        return *this;
    }
    Skladiste& DodajBure(const double& tezina, const char ime_tecnosti[], const double& tezina_tecnosti) {
        DodajSpremnik(new Bure(tezina, ime_tecnosti, tezina_tecnosti));
        return *this;
    }
    
    Spremnik& DajNajlaksi();
    Spremnik& DajNajtezi();
    int BrojPreteskih(const double& val) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(const char datoteka[]);
};

/// Implementation of Skladiste interface
Skladiste::~Skladiste() {
    for(int i(0); i < broj_reg; ++i) delete objekti[i];
    delete [] objekti;
    broj_reg = 0;
}
Skladiste::Skladiste(const Skladiste& s) : 
    max_broj_objekata(s.max_broj_objekata), broj_reg(s.broj_reg), objekti(new Spremnik*[max_broj_objekata]{}) {
    for(int i(0); i < broj_reg; ++i)
        objekti[i] = s.objekti[i]->DajKopiju();
}
Skladiste::Skladiste(Skladiste&& s) : max_broj_objekata(s.max_broj_objekata), broj_reg(0), objekti(nullptr) {
    std::swap(broj_reg, s.broj_reg);
    std::swap(objekti, s.objekti);
}
Skladiste& Skladiste::operator=(const Skladiste &s) {
    if(&s == this) return *this;
    
    for(int i(0); i < broj_reg; ++i) 
        delete objekti[i], objekti[i] = nullptr;
    delete [] objekti;
    
    max_broj_objekata = s.max_broj_objekata;
    broj_reg = s.broj_reg;
    
    for(int i(0); i < broj_reg; ++i)
        objekti[i] = s.objekti[i]->DajKopiju();
    return *this;
}
Skladiste& Skladiste::operator=(Skladiste&& s) {
    for(int i(0); i < broj_reg; ++i) 
        delete objekti[i], objekti[i] = nullptr;
    delete [] objekti, objekti = nullptr;
    broj_reg = max_broj_objekata = 0;
    
    std::swap(broj_reg, s.broj_reg); std::swap(max_broj_objekata, s.max_broj_objekata);
    std::swap(objekti, s.objekti);
    return *this;
}
/// implementation of additional functions of interface
Spremnik& Skladiste::DajNajlaksi() {
    if(broj_reg == 0) throw std::range_error("Skladiste je prazno");
    
    return **std::min_element(objekti + 0, objekti + broj_reg, [](Spremnik* lhs, Spremnik* rhs) {
        return lhs->DajTezinu() < rhs->DajTezinu();
    });
}
Spremnik& Skladiste::DajNajtezi() {
    if(broj_reg == 0) throw std::range_error("Skladiste je prazno");

    return **std::max_element(objekti + 0, objekti + broj_reg, [](Spremnik* lhs, Spremnik* rhs) {
        return lhs->DajTezinu() < rhs->DajTezinu();
    });
}
int Skladiste::BrojPreteskih(const double& val) const {
    return std::count_if(objekti, objekti + broj_reg, [&val](Spremnik* s) { return s->DajUkupnuTezinu() > val; });
}
void Skladiste::IzlistajSkladiste() const {
    std::for_each(objekti, objekti + broj_reg, [](Spremnik* s) { s->Ispisi(); });
}
void Skladiste::UcitajIzDatoteke(const char datoteka[]) {
    /// POKUSAJ PRVO OTVORITI
    std::vector<Spremnik*> spremnici;
    std::ifstream ulazni_tok(datoteka, std::ios::in);
    if(!ulazni_tok) 
        throw std::logic_error("Trazena datote ne postoji");
    
    std::string naziv_predmeta;
    char tip;
    for(;;) {
        tip = ulazni_tok.get();
        std::cout << "TIP: " << tip;
        std::getline(ulazni_tok, naziv_predmeta);
        std::cout << naziv_predmeta << "\n";
        if(tip == 'B') {
            double tez_bureta, tez_tecnosti;
            
            ulazni_tok >> tez_bureta >> tez_tecnosti;
            
            if(!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            spremnici.push_back(new Bure(tez_bureta, naziv_predmeta.c_str(), tez_tecnosti));
        }
        else if(tip == 'S') {
            int broj;
            double tez_sanduka, ukupna_tezina(0), trenutni;
            
            ulazni_tok >> tez_sanduka >> broj;
            for(int i(0); i < broj; ++i) {
                ulazni_tok >> trenutni;
                ukupna_tezina += trenutni;
            }
            std::cout << tez_sanduka << " " << broj << " " << ukupna_tezina << "\n";
            
            if(ulazni_tok.bad()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            spremnici.push_back(new Sanduk(tez_sanduka, naziv_predmeta.c_str(), 1, ukupna_tezina));
        }
        else if(!ulazni_tok.eof())
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        
        if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
        if(ulazni_tok.eof()) break;
    }
    
    /// AKO JE SVE U REDU, PISI
    /// isprazni prvo
    for(int i(0); i < broj_reg; ++i) 
        delete objekti[i], objekti[i] = nullptr;
    broj_reg = max_broj_objekata;
    
    for(int i(0); i < spremnici.size(); ++i)
        this->DodajSpremnik(spremnici.at(i));
}


int main ()
{//AT1
    std::ofstream f ("ABC.TXT");
    f << "S Tepsije" << std::endl
      << "10 5 3" << std::endl
      << "S Nesto" << std::endl
      << "1000 2 400.5" << std::endl
      << "B Ulje neko" << std::endl
      << "60.1 50";
    f.close();
    Skladiste s (10);
    s.UcitajIzDatoteke("ABC.TXT");
    const Skladiste &cs = s;
    cs.IzlistajSkladiste(); //cs je const
}
