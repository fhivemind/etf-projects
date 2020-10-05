#include <iostream>
#include <set>
#include <algorithm>

template <class T>
std::set<T> Unija(const std::set<T>& S1, const std::set<T>& S2) {
	std::set<T> output;
	std::copy(S1.begin(), S1.end(), std::inserter(output, output.begin()));
	std::copy(S2.begin(), S2.end(), std::inserter(output, output.begin()));
	return output;
}

template <class T>
std::set<T> Presjek(const std::set<T>& S1, const std::set<T>& S2) {
	std::set<T> output;
	for(auto it = S1.begin(); it != S1.end(); ++it)
		if(S2.find(*it) != S2.end())
			output.insert(*it);
	return output;
}


int main () {
	return 0;
}