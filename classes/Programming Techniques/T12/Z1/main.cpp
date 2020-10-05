#include <iostream>
#include <stdexcept>
#include <ctime>

class Sat {
	public:
		Sat() : h(0), m(0), s(0) {}
		Sat(int h, int m, int s) { PostaviNormalizirano(h, m, s); }
		
		// inspectors
		int DajSate() const { return h; }
		int DajMinute() const { return m; }
		int DajSekunde() const { return s; }
		
		// mutators
		void Postavi(const int& h, const int& m, const int& s);
		
		/// operator overload
		Sat &operator ++();
		Sat operator ++(int);
		Sat &operator --();
		Sat operator --(int);
		Sat &operator +=(int seconds);
		Sat &operator -=(int seconds);
		
		/// friend functions
		friend int operator -(const Sat &t1, const Sat &t2);
		friend Sat operator +(const Sat &t1, int seconds);
		friend Sat operator -(const Sat &t1, int seconds);
		friend std::ostream &operator <<(std::ostream &tok,const Sat &time);
		
		friend int BrojSekundiIzmedju(const Sat& t1, const Sat& t2);
	
	private:
		int h, m, s;
		
		void PostaviNormalizirano(int h, int m, int s) { 
    		struct tm _time = {0};
    		
			_time.tm_sec += s;
			_time.tm_min += m; 
			_time.tm_hour += h;
			
			std::mktime( &_time); 
	
			Sat::h = _time.tm_hour; Sat::m = _time.tm_min; Sat::s = _time.tm_sec; 
		}
		
		// help functions
		static int Razmak(const Sat& t1, const Sat& t2) {
			return toSeconds(t1) - toSeconds(t2);
		}
		static int toSeconds(const Sat& t) { return (t.h * 60 * 60 + t.m * 60 + t.s); }
		static bool isValidH(const int &h) { return (h >= 0 && h <= 23); }
		static bool isValidMS(const int &t) { return (t >= 0 && t <= 60); }
};
/// friend function
int BrojSekundiIzmedju(const Sat& t1, const Sat& t2) {
	return Sat::toSeconds(t1) - Sat::toSeconds(t2);
}
void Sat::Postavi(const int& h, const int& m, const int& s) { 
	Sat::h = h; Sat::m = m; Sat::s = s;
}
/// operator implementation
Sat& Sat::operator +=(int seconds) {
	this->PostaviNormalizirano(this->DajSate(), this->DajMinute(), this->DajSekunde() + seconds);
	return *this;
}
Sat& Sat::operator -=(int seconds) {
	return *this += -seconds;
}
Sat& Sat::operator ++() {
	return *this += 1;
}
Sat Sat::operator ++(int) {
	Sat _ret(*this); *this += 1;
	return _ret;
}
Sat& Sat::operator --() {
	return *this += -1;
}
Sat Sat::operator --(int) {
	Sat _ret(*this); *this += -1;
	return _ret;
}
int operator -(const Sat &t1, const Sat &t2) {
	return Sat::Razmak(t1, t2);
}
Sat operator +(const Sat &t1, int seconds) {
	return Sat(t1.h, t1.m, t1.s + seconds);
}
Sat operator -(const Sat &t1, int seconds) {
	return Sat(t1.h, t1.m, t1.s - seconds);
}
std::ostream &operator <<(std::ostream &tok, const Sat &_time) {
	tok << 	((_time.DajSate() < 10) ? "0":"") << _time.DajSate() << ":" << 
			((_time.DajMinute() < 10) ? "0":"") << _time.DajMinute() << ":" << 
			((_time.DajSekunde() < 10) ? "0":"") << _time.DajSekunde();
	return tok;
}


int main () {

		return 0;
}