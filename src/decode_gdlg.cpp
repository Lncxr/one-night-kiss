#include "../incl/decode_gdlg.h"

std::vector<uint8_t> decode_gdlg(const std::vector<uint8_t> &bytes) {
    std::vector<uint8_t> decoded;
    decoded.reserve(bytes.size());

    for (const uint8_t byte : bytes) {
        decoded.push_back(byte ^ 0x8D);
    }

    return decoded;
}