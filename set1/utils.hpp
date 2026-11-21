#include <string>
#include <vector>

const std::string BASE64 =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

const std::string HEX = "0123456789abcdef";

const std::vector<float> FREQUENCIES = {
    8.2f,  1.5f,  2.8f, 4.3f,  12.7f, 2.2f,  2.0f, 6.1f,  7.0f,
    0.16f, 0.77f, 4.0f, 2.4f,  6.7f,  7.5f,  1.9f, 0.12f, 6.0f,
    6.3f,  9.1f,  2.8f, 0.98f, 2.4f,  0.15f, 2.0f, 0.074f, 13.0f};

inline char hex_to_char(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  return 10 + c - 'a';
}
