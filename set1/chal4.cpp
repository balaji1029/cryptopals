#include "chal3.hpp"

#include <iostream>
#include <cassert>
#include <iterator>
#include <string>
#include <vector>

std::string get_string(const std::vector<std::string>& strs) {
	std::string matched_str;
	float max_score = -1.0f;
	for (std::string str : strs) {
		auto [new_str, score] = find_best_match(str);
		if (score > max_score) {
			max_score = score;
			matched_str = new_str;
		}
	}
	return matched_str;
}

int main() {
	std::vector<std::string> strs;
	for (size_t i=0; i<327; i++) {
		std::string curr;
		std::cin >> curr;
		strs.push_back(curr);
	}
	std::cout << get_string(strs) << std::endl;
}
