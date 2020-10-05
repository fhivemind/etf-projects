#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

class Lik {
public:
	void static BaciIzuzetak() {
		throw std::domain_error("Neispravni parametri");
	}
	virtual ~Lik() {};
	virtual void IspisiSpecificnosti() const = 0;
	virtual double DajObim() const = 0;
	virtual double DajPovrsinu() const = 0;
	void Ispisi() const {
		IspisiSpecificnosti();
		std::cout << "Obim: " << DajObim();
		std::cout << " Povrsina: " << DajPovrsinu() << std::endl;
	}
};

class Krug : public Lik {
private:
	double r;
	static double constexpr PI = 4 * atan(1.0);
public:
	Krug(double r) : r(r) {
		if(r <= 0) Lik::BaciIzuzetak();
	}
	
	void IspisiSpecificnosti() const {
		std::cout << "Krug poluprecnika " << r << std::endl;
	}
	double DajObim() const { return 2 * r * PI; }
	double DajPovrsinu() const { return r*r*PI; };
};

class Pravougaonik : public Lik {
private:
	double a, b;
public:
	Pravougaonik(double a, double b) : a(a), b(b) {
		if(a <= 0 || b <= 0) Lik::BaciIzuzetak();
	}
	
	void IspisiSpecificnosti() const { 
		std::cout << "Pravougaonik sa stranicama duzine " << a <<" i "<< b << std::endl;
	}
	double DajObim() const { return 2*(a+b); }
	double DajPovrsinu() const { return a*b; };
};

class Trougao : public Lik {
private:
	double a, b, c;
	bool static _valid(double x, double y, double z) {
		return x < y + z;
	}
public:
	Trougao(double a, double b, double c) : a(a), b(b), c(c) {
		if(a <= 0 || b <= 0 || c<= 0 || !_valid(a, b, c) || !_valid(b, a, c) || !_valid(c, a, b)) Lik::BaciIzuzetak();
	}
	
	void IspisiSpecificnosti() const {
		std::cout << "Trougao sa stranicama duzine " << a <<", "<< b << " i " << c << std::endl;
	}
	double DajObim() const { return a+b+c; }
	double DajPovrsinu() const { 
		double s(this->DajObim()/2);
		return  std::sqrt(s*(s-a)*(s-b)*(s-c));
	};
};

int main () {
	std::cout<<"Koliko zelite likova: ";
	int broj, i(1);
	std::cin>>broj;
	std::vector<std::shared_ptr<Lik>> vektor;
	
	for(;;) {
        try {
            std::cout<<"Lik "<<i<<": ";
            char znak;
            std::cin>>znak;
            if(znak=='P')
            {
                double a,b;
                std::cin >> a >> znak >> b;
                if(!std::cin || std::cin.peek()!='\n')
                {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                    continue;
                }
                auto p(std::shared_ptr<Lik>(new Pravougaonik(a,b)));
                vektor.push_back(p);
            } else if(znak=='K')
            {
                double r;
                std::cin >> r;
                if(!std::cin || std::cin.peek()!='\n')
                {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                    continue;
                }
                auto p(std::shared_ptr<Lik>(new Krug(r)));
                vektor.push_back(p);
            }
			else if(znak=='T')
            {
                double a,b,c;
                std::cin>> a >> znak >> b >> znak >> c;
                if(!std::cin || std::cin.peek()!='\n')
                {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                    continue;
                }
                auto p(std::shared_ptr<Lik>(new Trougao(a,b,c)));
                vektor.push_back(p);
            } else
            {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                continue;
            }
            if(i==broj) break;
            i++;
        }
        catch(...)
        {
            std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
        }
	}
    std::cout<<std::endl;
    std::for_each(vektor.begin(),vektor.end(),[](std::shared_ptr<Lik> p) { p->Ispisi();});
	return 0;
}