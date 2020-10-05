#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

std::string IzvrniBezRazmaka(std::string input) {
     std::string output;
     std::remove_copy(input.rbegin(), input.rend(), std::back_inserter(output), ' ');
     return output;
}

int main () {
     
	return 0;
}