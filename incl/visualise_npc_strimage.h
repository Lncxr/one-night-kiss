#pragma once

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

namespace ps2_gs {
constexpr uint32_t COLUMN_HEIGHT = 24; // Constant?
constexpr uint32_t RENDER_SIZE = 0x2C; // Per SJIS character
constexpr uint32_t EXPECTED_SIZE =
    0x5E0; // Defined just before texture descriptor
}

void visualise_npc_strimage(const std::vector<uint8_t> &bytes,
                            const std::string &output_path);