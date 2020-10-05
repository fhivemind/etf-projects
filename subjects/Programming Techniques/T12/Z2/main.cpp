#include <iostream>
#include <set>
#include <algorithm>

template <class T>
std::set<T> operator+(const std::set<T>& S1, const std::set<T>& S2) {
	std::set<T> output(S1);
	std::copy(S2.begin(), S2.end(), std::inserter(output, output.begin()));
	return output;
}

template <class T>
std::set<T> operator+=(std::set<T>& S1, const std::set<T>& S2) {
	std::copy(S2.begin(), S2.end(), std::inserter(S1, S1.begin()));
	return S1;
}

template <class T>
std::set<T> operator*(const std::set<T>& S1, const std::set<T>& S2) {
	std::set<T> output;
	for(auto it = S1.begin(); it != S1.end(); ++it)
		if(S2.find(*it) != S2.end())
			output.insert(*it);
	return output;
}

template <class T>
std::set<T> operator*=(std::set<T>& S1, const std::set<T>& S2) {
	auto it(S1.begin());
	for (;it != S1.end();) {
		if(S2.find(*it) == S2.end()) {
			it=S1.erase(it); 
			continue; 
		}
		it++;
	}
	return S1;
}

template <class T1, class T2>
auto operator%(const std::set<T1>& S1, const std::set<T2>& S2) -> std::set<std::pair<T1, T2>> {
    std::set<std::pair<T1, T2>> output;
    for(auto it = S1.begin(); it != S1.end(); ++it)
        for(auto it2 = S2.begin(); it2 != S2.end(); ++it2)
            output.insert(std::make_pair(*it, *it2));
    return output;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream &_stream, const std::pair<T1, T2>& _pair) {
	_stream << "(" << _pair.first << "," << _pair.second << ")";
	return _stream;
}

template <class T>
std::ostream& operator<<(std::ostream &_stream, const std::set<T>& _set) {
    std::cout << "{" ;
    int _pos(1), _size(_set.size());
    std::for_each(_set.begin(), _set.end(), [&_pos, &_size](const T& _value){ std::cout << _value; if(_pos++ < _size) std::cout << ","; });
    std::cout << "}";
	return _stream;
}

int main () {


	return 0;
}