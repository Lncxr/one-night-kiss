#pragma once

#include <cstdint>
#include <vector>

namespace ps2_gs {
constexpr uint32_t TME_WIDTH = 40;
constexpr uint8_t TRANSPARENT = 0x88;
}

void visualise_tme_strimage(const std::vector<uint8_t> &bytes,
                            const char *output_path);