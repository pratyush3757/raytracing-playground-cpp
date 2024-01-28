#ifndef PPM_H
#define PPM_H

#include "rt_canvas.hpp"
// #include "rt_colors.hpp"
#include <cstdint>

namespace ppm {

void render_plain(const rt_canvas &canvas);
void render_bytes(const rt_canvas &canvas);

}

#endif
