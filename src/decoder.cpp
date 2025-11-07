#include "../incl/decode_gdlg.h"
#include "../incl/hex_str_to_bytes.h"
#include <fstream>
#include <iostream>

constexpr const char *str = "";

int main() {
    std::vector<uint8_t> bytes = hex_str_to_bytes(str);
    std::vector<uint8_t> decoded = decode_gdlg(bytes);
    
    std::ofstream outfile("script.bin", std::ios::binary);

    outfile.write(reinterpret_cast<const char*>(decoded.data()), decoded.size());
    outfile.close();
    
    return 0;
}