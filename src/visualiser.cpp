#include "../incl/hex_str_to_bytes.h"
#include "../incl/visualise_strimage.h"

/* 0x70(*address) */
constexpr const char *str = "";

int main() {
  std::vector<uint8_t> bytes = hex_str_to_bytes(str);
  
  visualise_strimage(bytes, "glyph.png");
  return 0;
}