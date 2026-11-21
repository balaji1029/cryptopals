#include <cassert>
#include <climits>
#include <iostream>
#include <string>

#include "utils.hpp"

std::string hex_to_str(const std::string &input) {
  std::string output;
  for (std::size_t index = 0; index < input.size(); index += 2) {
    if (index + 1 == input.size())
      output += (hex_to_char(input[index]) << 4);
    else
      output +=
          ((hex_to_char(input[index]) << 4) | (hex_to_char(input[index + 1])));
  }
  return output;
}

float dot_product(std::vector<float> v1, std::vector<float> v2) {
  assert(v1.size() == v2.size());
  float dot_product = 0.0;

  for (std::size_t i = 0; i < v1.size(); i++) {
    dot_product += v1[i] * v2[i];
  }
  return dot_product;
}

float get_alphabet_score(const std::string &input) {
  float score = 0.0f;
  std::vector<float> scores(27);

  for (char c : input) {
    if (c >= 'A' && c <= 'Z')
      c += 'a' - 'A';
    if (c >= 'a' && c <= 'z')
      scores[c - 'a']++;
    else if (c == ' ')
      scores[26]++;
  }

  return dot_product(scores, FREQUENCIES);
}

std::string get_xor(const std::string &input, char x) {
  std::string output;
  for (const char &c : input) {
    output += (c ^ x);
  }
  return output;
}

std::pair<std::string, float> find_best_match(const std::string &input) {
  std::string encoded = hex_to_str(input);
  std::string matched_string;
  float max_score = -1.0f;
  for (int c = 0; c <= UCHAR_MAX; c++) {
    std::string decoded = get_xor(encoded, c);
    float score = get_alphabet_score(decoded);
    if (score > max_score) {
      matched_string = decoded;
      max_score = score;
    }
    // std::cout <<  << std::endl;
  }
  return {matched_string, max_score};
}
