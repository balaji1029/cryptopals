#include <iostream>
#include <cassert>
#include <string>

#include "utils.hpp"

std::string fixed_xor(const std::string& s1, const std::string& s2) {
	assert(s1.size() == s2.size());
	std::string output;
	output.reserve(s1.size());
	for (std::size_t i=0; i<s1.size(); i++) {
		output += HEX[hex_to_char(s1[i]) ^ hex_to_char(s2[i])];
	}
	return output;
}

int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;
	std::cout << fixed_xor(s1, s2) << std::endl;
}
