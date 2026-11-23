#include <iostream>
#include <string>

#include "utils.hpp"

std::string encrypt_repeating_key(const std::string payload, const std::string& key) {
	size_t i;
	std::string c;
	for (i=0; i<payload.size(); i+=key.size()) {
		for (size_t j=0; (j<key.size()) && ((i + j) < payload.size()); j++) {
			c += payload[i + j] ^ key[j];
		}
	}
	return c;
}

std::string to_hex(const std::string& s) {
	std::string hex;
	for (const auto& c : s) {
		hex += HEX[(c >> 4)];
		hex += HEX[(c & 15)];
	}
	return hex;
}

int main() {
	std::string input, key;
	std::getline(std::cin, input);
	std::cin >> key;

	std::cout << to_hex(encrypt_repeating_key(input, key)) << std::endl;
}
