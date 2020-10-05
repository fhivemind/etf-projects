#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
class Krug {
    public:
        // ctor
        explicit Krug(double r) { 
            Postavi(r);
        }
        
        void Postavi(double r) {
            if(r <= 0) throw std::domain_error("Neispravan poluprecnik");
            Krug::r = r; 
        }
        
        // mutators
        Krug &Skaliraj(const double& d) {
            if(d <= 0) throw std::domain_error("Neispravan faktor skaliranja");
            this->r *= d;
            return *this;
        }
        
        // inspectors
        double DajPoluprecnik() const { return this->r; }
        double DajObim() const { return this->r * 2 * this->PI; } 
        double DajPovrsinu() const { return this->r * this->r * this->PI; } 
        void Ispisi() const { std::cout<< std::setprecision(5) << std::fixed  << "R=" <<  this->DajPoluprecnik() << " O=" << this->DajObim() << " P=" << this->DajPovrsinu(); } 
        
    private:
        double r;
        constexpr static double PI = 4*std::atan(1);
};

class Valjak {
    public:
        // ctor
        Valjak(double baza, double h) : baza(Krug(baza)) {
            if(h <= 0) throw std::domain_error("Neispravna visina");
            visina = h;
        }
    
        // mutators
        Valjak& Postavi(double baza, double visina) {
            this->baza = Krug(baza);
            if(visina <= 0) throw std::domain_error("Neispravna visina");
            this->visina = visina;
            return *this;
        }
        
        Valjak &Skaliraj(const double& d) {
            this->baza.Skaliraj(d);
            this->visina *= d;
            return *this;
        }
        
        // inspectors
        Krug& DajBazu() { return this->baza; }
        double DajPoluprecnikBaze() const { return this->baza.DajPoluprecnik(); }
        double DajVisinu() const { return this->visina; }
        double DajPovrsinu() const { return 2 * this->baza.DajPovrsinu() + this->baza.DajObim() * this->DajVisinu(); }
        double DajZapreminu() const { return this->baza.DajPovrsinu() * this->DajVisinu(); }
        void Ispisi() const { std::cout << std::setprecision(5) << std::fixed << "R="  << this->DajPoluprecnikBaze() << " H=" << this->DajVisinu() << " P=" << this->DajPovrsinu() << " V=" << this->DajZapreminu(); } 
    
    
    private:
        double visina;
        Krug baza;
};


int main() {
    Krug k(5);
k.Ispisi(); std::cout << std::endl;
Valjak v1(1, 9);
v1.Ispisi(); std::cout << std::endl;
v1.DajBazu().Ispisi(); std::cout << std::endl;
Valjak v2(k.DajPoluprecnik(),8);
v2.DajBazu().Ispisi(); std::cout << std::endl;
}