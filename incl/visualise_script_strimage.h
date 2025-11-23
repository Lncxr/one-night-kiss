#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace ps2_gs {
/* TODO: STRIMAGE header handling */
constexpr uint32_t FORMAT = 0x14;
constexpr uint32_t STRIDE = 16;
constexpr uint32_t HEIGHT = 24;
}

void visualise_script_strimage(const std::vector<uint8_t> &bytes,
                               const std::string &output_path);