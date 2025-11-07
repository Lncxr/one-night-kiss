#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

std::vector<uint8_t> hex_str_to_bytes(std::string_view hex_str) {
  std::vector<uint8_t> bytes;
  bytes.reserve(hex_str.length() / 2);

  for (size_t i = 0; i < hex_str.length(); i += 2) {
    bytes.push_back(static_cast<uint8_t>(
        std::stoi(std::string(hex_str.substr(i, 2)), nullptr, 16)));
  }
  return bytes;
}