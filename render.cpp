#include "render.hpp"
#include "color.hpp"
#include "vec3.hpp"

#include <cstdint>
#include <iostream>

void render(bool ascii) {
    if (ascii) {
        std::cout << "P3\n" << ppm::image_width << ' ' << ppm::image_height << "\n255\n";
    } else {
        std::cout << "P6\n" << ppm::image_width << ' ' << ppm::image_height << "\n255\n";
    }

    // int32_t instead of uint32_t as j goes till -1
    for (int32_t j = ppm::image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int32_t i = 0; i < ppm::image_width; ++i) {
            color pixel_color(double(i)/(ppm::image_width-1),
                              double(j)/(ppm::image_height-1),
                              0.25);

            if (ascii) {
                write_color_plain(std::cout, pixel_color);
            } else {
                write_color_bytes(std::cout, pixel_color);
            }
        }
    }

    std::cerr << "\nDone.\n";

}

void ppm::render_plain() {
    render(true);
}


void ppm::render_bytes() {
    render(false);
}

