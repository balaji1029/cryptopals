#include <iostream>

#include "chal3.hpp"

int main() {
  std::string input;
  std::cin >> input;
  std::cout << find_best_match(input).first << std::endl;
}
