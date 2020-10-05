//TP 2017/2018: Tutorijal 14, Zadatak 4
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

/// function to implement
void BaciIzuzetak(std::string tekst = "Datoteka ne postoji") { throw std::logic_error(tekst); }
void IzvrniDatoteku(std::string datoteka) {
    std::fstream tok(datoteka, std::ios::in | std::ios::out | std::ios::binary); // for read and write!
    if(!tok) BaciIzuzetak();
    
    tok.seekg(0, std::ios::end);
    double firstNum, lastNum;
    int typeSize (sizeof(double));
    for(int firstPos(0), lastPos(int(tok.tellg()) - typeSize); firstPos < lastPos; firstPos += typeSize, lastPos -= typeSize) {
        tok.seekg(firstPos, std::ios::beg);
        tok.read(reinterpret_cast<char*>(&firstNum), typeSize);
        tok.seekg(lastPos, std::ios::beg);
        tok.read(reinterpret_cast<char*>(&lastNum), typeSize);
        if(tok.bad()) BaciIzuzetak("Problemi pri citanju datoteke");
        
        tok.seekp(firstPos, std::ios::beg);
        tok.write(reinterpret_cast<char*>(&lastNum), typeSize);
        tok.seekp(lastPos, std::ios::beg);
        tok.write(reinterpret_cast<char*>(&firstNum), typeSize);
        //if(tok.bad()) BaciIzuzetak("Problemi pri pisanju u datoteku");
    }
}

int main () {
    
    
    
	return 0;
}
