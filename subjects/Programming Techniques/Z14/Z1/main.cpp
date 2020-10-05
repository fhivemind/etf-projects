//TP 2017/2018: Tutorijal 14, Zadatak 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <stdexcept>
#include <iomanip>

class Datum {
private: 
    int dan, mjesec, godina;
    std::string naslov;
    double prosjek;
    std::vector<double> podaci;
    bool postavljen_datum;
public:
    explicit Datum() : prosjek(0), postavljen_datum(false) {}
    void Postavi(int d, int m, int g) {
        dan = d, mjesec = m, godina = g;
    }
    void PostaviNaslov(std::string novi) { naslov = novi; }
    std::vector<double>& DajPodatke() { return podaci; }
    std::vector<double> DajPodatke() const { return podaci; }
    void DodajPodatak(double info) { podaci.push_back(info); }
    
    double DajMax() const {
        if(podaci.empty()) throw std::range_error("Problemi pri citanju datoteke TEMPERATURE.TXT");
        return *max_element(podaci.begin(), podaci.end());
    }
    double DajMin() const {
        if(podaci.empty()) throw std::range_error("Problemi pri citanju datoteke TEMPERATURE.TXT");
        return *min_element(podaci.begin(), podaci.end());
    }
    double DajProsjek() const {
        return prosjek;
    }
    std::string DajNaslov() const {
        return naslov;
    }
    
    double IzracunajProsjek() {
        if(podaci.empty()) throw std::range_error("Problemi pri citanju datoteke TEMPERATURE.TXT");
        prosjek = 0;
        for(auto clan : podaci) 
            prosjek += clan;
        postavljen_datum = true;
        return (prosjek /= podaci.size());
    }
    std::string& DajNaslov() { 
        return naslov; 
    }
    
    friend bool operator==(const Datum&, const Datum&);
    friend bool operator<(const Datum&, const Datum&);
    friend bool operator>(const Datum&, const Datum&);
    friend std::istream& operator >>(std::istream &tok, Datum& datum);
    friend std::ostream& operator <<(std::ostream &tok, const Datum& datum);
};

bool operator<(const Datum& d1, const Datum& d2) {
    return (d1.godina < d2.godina) || (d1.godina == d2.godina && d1.mjesec < d2.mjesec) || 
            (d1.godina == d2.godina && d1.mjesec == d2.mjesec && d1.dan < d2.dan) ||
            (d1.godina == d2.godina && d1.mjesec == d2.mjesec && d1.dan == d2.dan && d1.DajProsjek() < d2.DajProsjek());
}
bool operator>(const Datum& d1, const Datum& d2) { return d2 < d1; }
bool operator==(const Datum& d1, const Datum& d2) { return d1.dan == d2.dan && d1.mjesec == d2.mjesec && d1.godina == d2.godina; }
 
std::ostream& operator <<(std::ostream &tok, const Datum& datum) {
    tok << datum.DajNaslov() << std::endl << std::string(datum.DajNaslov().length(), '-') << std::endl;
    tok << "Datum mjerenja: " << std::resetiosflags(std::ios::fixed) << datum.dan << '/' << datum.mjesec << '/' << datum.godina << std::endl;
    tok << "Minimalna temperatura: " << datum.DajMin() << std::endl;
    tok << "Maksimalna temperatura: " << datum.DajMax() << std::endl;
    tok << "Prosjecna temperatura: " << std::fixed << std::setprecision(2) << datum.DajProsjek();
    return tok;
} 
std::istream &operator >>(std::istream &tok, Datum& datum) {
    char znak;
    int d, m, y;
    
    tok >> std::ws;
    if(!::isdigit(tok.peek())) tok.setstate(std::ios::failbit);
    else tok >> d >> znak;
    if(znak != '/') tok.setstate(std::ios::failbit);

    if(!::isdigit(tok.peek())) tok.setstate(std::ios::failbit);
    else tok >> m >> znak;
    if(znak != '/') tok.setstate(std::ios::failbit);
    
    if(!::isdigit(tok.peek())) tok.setstate(std::ios::failbit);
    else tok >> y;
    
    datum.Postavi(d, m, y);
    return tok;
    
}

int main () {
    std::ifstream ulazni_tok ("TEMPERATURE.TXT", std::ios::in);
    if(!ulazni_tok) {
        std::cout << "Datoteka TEMPERATURE.TXT ne postoji!\n";
        return -1;
    }
    std::ofstream izlazni_tok ("IZVJESTAJ.TXT", std::ios::out);
    
    /// start reading
    std::multiset<Datum> podaci;
    double num;
    char delim;
    
    for(;;) {
        Datum d;

        ulazni_tok >> d; ulazni_tok.get(); // read \n

        if(!ulazni_tok) {
            std::cout << "Problemi pri citanju datoteke TEMPERATURE.TXT\n";
            return -1;
        }
        std::getline(ulazni_tok, d.DajNaslov());
        
        if(ulazni_tok.bad()) {
            std::cout << "Problemi pri citanju datoteke TEMPERATURE.TXT\n";
            return -1;
        }
        
        /// procitaj sada podatke u vektor
        for(;ulazni_tok >> num && (delim = ulazni_tok.get());) {
            if(!ulazni_tok.eof()) {
                if(!ulazni_tok || (delim != ',' && delim != '\n')) {
                    std::cout << "Problemi pri citanju datoteke TEMPERATURE.TXT\n";
                    return -1;
                }
            }
            d.DodajPodatak(num);
            if(delim == '\n' || ulazni_tok.eof()) break;
        }
        
        try {
            d.IzracunajProsjek();
            if(!d.DajPodatke().empty())
                podaci.insert(d);
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            return -1;
        }
        
        if(ulazni_tok.eof()) break;
    }
    
    /// SVE PROCITAO, SADA PISI
    int pos(0);
    for(auto info : podaci) {
        izlazni_tok << info;
        if(pos++ != podaci.size() - 1) izlazni_tok << std::endl << std::endl;
    }
	return 0;
}