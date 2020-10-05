#include <iostream>
#include <string>
#include <vector>
#include <deque>

/* function to implement */
template <typename IterTip1, typename IterTip2>
IterTip2 RazmijeniBlokove(IterTip1 _v1Begin, IterTip1 _v1End, IterTip2 _fromBegin) {
	for(;_v1Begin != _v1End;) {
		auto temp = *_v1Begin;
		*_v1Begin = *_fromBegin;
		*_fromBegin = temp;
		++_v1Begin; ++_fromBegin;
	}
	return _fromBegin;
}

/* main function */
int main () {

	return 0;
}