#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../incl/stb_image_write.h"
#include "../incl/visualise_tme_strimage.h"

void visualise_tme_strimage(const std::vector<uint8_t> &bytes,
                            const char *output_path) {
  size_t total_pixels = bytes.size() * 2;
  uint32_t height = total_pixels / ps2_gs::TME_WIDTH;

  std::vector<uint8_t> rgba(total_pixels * 4);

  for (size_t i = 0; i < bytes.size(); i++) {
    for (int shift : {0, 4}) { /* lhs → rhs, low → high */
      uint8_t pixel = (bytes[i] >> shift) & 0x0F;
      size_t index = (i * 2 + shift / 4) * 4;
      uint8_t intensity = pixel * 17;

      rgba[index] = rgba[index + 1] = rgba[index + 2] = intensity;
      rgba[index + 3] = (pixel == ps2_gs::TRANSPARENT) ? 0 : 255;
    }
  }

  stbi_write_png(output_path, ps2_gs::TME_WIDTH, height, 4, rgba.data(),
                 ps2_gs::TME_WIDTH * 4);
}