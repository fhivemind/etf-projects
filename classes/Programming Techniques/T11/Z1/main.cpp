#include <iostream>

class NeobicnaKlasa {
    private:
        int value;
    public:
        explicit NeobicnaKlasa(const int &num) : value(num) { 
            std::cout << "Direktna inicijalizacija\n";
        }
        NeobicnaKlasa(const long &num) : value(num) { 
            std::cout << "Kopirajuca inicijalizacija\n";
        }
        
        NeobicnaKlasa() {}
        NeobicnaKlasa& operator=(const int& a) 
        {
            std::cout << "Kopirajuci operator";
            return *this;
        }
};


int main ()
{
    NeobicnaKlasa k1(5);
    NeobicnaKlasa k2 = 5;
	return 0;
}