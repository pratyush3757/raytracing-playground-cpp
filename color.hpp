#ifndef COLOR_H
#define COLOR_H

#include "vec3.hpp"

#include <cstdint>
#include <iostream>

void write_color_plain(std::ostream &out, color pixel_color) {
    // uint32_t instead of uint8_t as ostream treats uint8_t as unsigned char
    // and prints its byte value instead of the number as ascii
    out << static_cast<uint32_t>(255.999 * pixel_color.x()) << ' '
        << static_cast<uint32_t>(255.999 * pixel_color.y()) << ' '
        << static_cast<uint32_t>(255.999 * pixel_color.z()) << '\n';
}

void write_color_bytes(std::ostream &out, color pixel_color) {
    // passing uint8_t to ostream makes it print the number's byte value
    out << static_cast<uint8_t>(255.999 * pixel_color.x())
        << static_cast<uint8_t>(255.999 * pixel_color.y())
        << static_cast<uint8_t>(255.999 * pixel_color.z());
}

#endif
