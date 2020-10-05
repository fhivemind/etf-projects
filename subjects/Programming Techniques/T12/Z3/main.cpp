#include <iostream>
#include <vector>
#include <string>
enum Dani {Ponedjeljak,Utorak,Srijeda,Cetvrtak,Petak,Subota,Nedjelja};
static const char days[7][20] = {"Ponedjeljak","Utorak","Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};


Dani &operator ++(Dani &day) {
	return day = Dani((static_cast<int>(day) + 1) % 7);
}
Dani operator ++(Dani &day, int) {
	Dani _ret(day);
	++day;
	return _ret;
}
Dani operator +(Dani &day, int n) {
	return Dani((static_cast<int>(day) + n) % 7);
}
std::ostream &operator <<(std::ostream &_stream, const Dani &day){
	return _stream << days[int(day)];;
}

int main () {
	return 0;
}