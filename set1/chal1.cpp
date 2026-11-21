#include <cassert>
#include <ios>
#include <iostream>
#include <string>

#include "utils.hpp"

std::string hex_to_base64(const std::string &input) {
  std::string output;
  std::size_t index = 0;
  std::size_t size = input.size();
  while (size >= index + 3) {
    char a = hex_to_char(input[index]), b = hex_to_char(input[index + 1]),
         c = hex_to_char(input[index + 2]);
    output += BASE64[(a << 2) | ((b & 12) >> 2)];
    output += BASE64[((b & 3) << 4) | c];
    index += 3;
  }
  if (size == index + 2) {
    char a = hex_to_char(input[index]), b = hex_to_char(input[index + 1]);
    output += BASE64[(a << 2) | ((b & 12) >> 2)];
    output += BASE64[(b & 3) << 4];
    output += "==";
    index += 2;
  }
  if (size == index + 1) {
    char a = hex_to_char(input[index]);
    output += BASE64[a << 2];
    output += '=';
    index++;
  }
  assert(size == index);
  return output;
}

int main() {
  std::string input;
  std::cin >> input;
  std::cout << hex_to_base64(input) << std::endl;
}
