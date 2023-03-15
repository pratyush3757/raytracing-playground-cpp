#include "render.hpp"
#include <cstdint>
#include <iostream>

void ppm::render_plain() {
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // int32_t instead of uint32_t as j goes till -1
    for (int32_t j = image_height - 1; j >= 0; --j) {
        for (int32_t i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            // uint32_t instead of uint8_t as ostream treats uint8_t as unsigned char
            uint32_t ir = static_cast<uint32_t>(255.999 * r);
            uint32_t ig = static_cast<uint32_t>(255.999 * g);
            uint32_t ib = static_cast<uint32_t>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}


void ppm::render_binary() {
    std::cout << "P6\n" << image_width << ' ' << image_height << "\n255\n";

    // int32_t instead of uint32_t as j goes till -1
    for (int32_t j = image_height - 1; j >= 0; --j) {
        for (int32_t i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            uint8_t ir = static_cast<uint8_t>(255.999 * r);
            uint8_t ig = static_cast<uint8_t>(255.999 * g);
            uint8_t ib = static_cast<uint8_t>(255.999 * b);
            std::cout << ir << ig << ib;
        }
    }
}
