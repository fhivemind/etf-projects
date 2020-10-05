#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

/* function to implement */
template <typename IterTip1>
auto SumaBloka(IterTip1 _v1Begin, IterTip1 _v1End) -> decltype(*_v1Begin + *_v1Begin) {
	if(_v1Begin == _v1End) throw std::range_error("Blok je prazan");
	
	decltype(*_v1Begin + *_v1Begin) suma {decltype(*_v1Begin + *_v1Begin)()};
	for(;_v1Begin != _v1End; suma += *_v1Begin++);
	return suma;
}

/* main function */
int main () {
	
	return 0;
}