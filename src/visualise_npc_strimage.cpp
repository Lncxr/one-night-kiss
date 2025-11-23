#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../incl/stb_image_write.h"
#include "../incl/visualise_npc_strimage.h"

void visualise_npc_strimage(const std::vector<uint8_t> &bytes,
                            const std::string &output_path) {
  /* TODO: Update for actual GDLG-STRIMAGE iteration */
  size_t data_start = (bytes.size() > ps2_gs::EXPECTED_SIZE)
                          ? bytes.size() - ps2_gs::EXPECTED_SIZE
                          : 0;

  size_t size = bytes.size() - data_start;
  uint32_t columns = size / ps2_gs::COLUMN_HEIGHT;

  /* rhs → lhs for some reason */
  std::vector<uint8_t> source(columns * ps2_gs::COLUMN_HEIGHT, 0);
  for (uint32_t column = 0; column < columns; column++) {
    int col = columns - 1 - column;

    for (int row = 0; row < ps2_gs::COLUMN_HEIGHT; row++) {
      size_t byte_idx = data_start + column * ps2_gs::COLUMN_HEIGHT + row;

      if (byte_idx < bytes.size()) {
        source[row * columns + col] = bytes[byte_idx];
      }
    }
  }

  std::vector<uint8_t> rgba(ps2_gs::RENDER_SIZE * ps2_gs::RENDER_SIZE * 4);

  for (int y = 0; y < ps2_gs::RENDER_SIZE; y++) {
    for (int x = 0; x < ps2_gs::RENDER_SIZE; x++) {
      int src_x = (x * columns) / ps2_gs::RENDER_SIZE;
      int src_y = (y * ps2_gs::COLUMN_HEIGHT) / ps2_gs::RENDER_SIZE;

      uint8_t alpha = (src_x < columns && src_y < ps2_gs::COLUMN_HEIGHT)
                          ? source[src_y * columns + src_x]
                          : 0;
      uint8_t intensity = 255 - alpha;

      size_t index = (y * ps2_gs::RENDER_SIZE + x) * 4;
      rgba[index] = rgba[index + 1] = rgba[index + 2] = intensity;
      rgba[index + 3] = 255;
    }
  }

  stbi_write_png(output_path.c_str(), ps2_gs::RENDER_SIZE, ps2_gs::RENDER_SIZE,
                 4, rgba.data(), ps2_gs::RENDER_SIZE * 4);
}