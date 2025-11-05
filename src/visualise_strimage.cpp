#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../incl/stb_image_write.h"
#include "../incl/visualise_strimage.h"

namespace ps2_gs {
/* 0x211f60 */
constexpr uint32_t FORMAT = 0x14;
/* Alignment seems to be constant, TODO: names */
constexpr uint32_t STRIDE = 16;
constexpr uint32_t HEIGHT = 24;
}

/* https://www.copetti.org/writings/consoles/playstation-2 */
void visualise_strimage(const std::vector<uint8_t> &bytes,
                        const std::string &output_path) {
  std::vector<uint8_t> rgba(ps2_gs::STRIDE * ps2_gs::HEIGHT * 4);

  /* PlayStation 2 graphics synthesiser (GS) rasterisation process */
  for (int y = 0; y < ps2_gs::HEIGHT; y++) {
    for (int x = 0; x < ps2_gs::STRIDE; x++) {
      uint8_t alpha = bytes[y * ps2_gs::STRIDE + x];
      size_t pixel = (y * ps2_gs::STRIDE + x) * 4;

      /* Assume full intensity */
      rgba[pixel + 0] = 255;
      rgba[pixel + 1] = 255;
      rgba[pixel + 2] = 255;
      rgba[pixel + 3] = alpha;
    }
  }

  stbi_write_png(output_path.c_str(), ps2_gs::STRIDE, ps2_gs::HEIGHT, 4,
                 rgba.data(), ps2_gs::STRIDE * 4);
}