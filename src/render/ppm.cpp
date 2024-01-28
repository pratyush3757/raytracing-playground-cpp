#include "ppm.hpp"
// #include "rt_canvas.hpp"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

inline void write_color_plain(std::ostream &out, double r, double g, double b);
inline void write_color_bytes(std::ostream &out, double r, double g, double b);
// void render_ppm(bool ascii, const rt_canvas &canvas) {
//     if (ascii) {
//         std::cout << "P3\n" << canvas.width << ' ' << canvas.height << "\n255\n";
//     } else {
//         std::cout << "P6\n" << canvas.width << ' ' << canvas.height << "\n255\n";
//     }
// 
//     size_t width, height;
//     width = canvas.width;
//     height = canvas.height;
//     for (auto const& row : canvas.canvas) {
//         height--;
//         std::cerr << "\rScanlines remaining: " << height << ' ' << std::flush;
//         std::stringstream out_buf;
//         for (auto const& pixel: row) {
//             if (ascii) {
//                 ppm::write_color_plain(out_buf, pixel);
//             } else {
//                 ppm::write_color_bytes(out_buf, pixel);
//             }
//         }
//         
//         std::string row_string = out_buf.str();
//         if (row_string.length() > 70) {
//             size_t idx = row_string.find(' ', 70);
//             row_string.replace(idx, 1, 1, '\n');
//         }
//         
//         std::cout << row_string;
//     }
// 
//     std::cerr << "\nDone.\n";
// 
// }

void ppm::render_plain(const rt_canvas &canvas) {
    // render_ppm(true, canvas);
    std::cout << "P3\n" << canvas.width << ' ' << canvas.height << "\n255\n";
    size_t width, height;
    width = canvas.width;
    height = canvas.height;
    for (auto const& row : canvas.canvas) {
        height--;
        std::cerr << "\rScanlines remaining: " << height << ' ' << std::flush;
        std::stringstream out_buf;
        for (auto const& pixel: row) {
            double r,g,b;
            r = pixel.r();
            g = pixel.g();
            b = pixel.b();
            write_color_plain(out_buf, r, g, b);
        }
        
        std::basic_string row_string = out_buf.str();
        size_t len = row_string.length();
        if (len > 70) {
            size_t idx = row_string.find(' ', 65);
            row_string.replace(idx, 1, 1, '\n');
        }
        
        std::cout << row_string << '\n';
    }

    std::cerr << "\nDone.\n";
}


void ppm::render_bytes(const rt_canvas &canvas) {
    std::cout << "P6\n" << canvas.width << ' ' << canvas.height << "\n255\n";
    
    size_t width, height;
    width = canvas.width;
    height = canvas.height;
    double r,g,b;
    for (auto const& row : canvas.canvas) {
        height--;
        std::cerr << "\rScanlines remaining: " << height << ' ' << std::flush;
        for (auto const& pixel: row) {
            r = pixel.r();
            g = pixel.g();
            b = pixel.b();
            write_color_bytes(std::cout, r, g, b);
        }
    }

    std::cerr << "\nDone.\n";

}

inline void write_color_plain(std::ostream &out, double r, double g, double b) {
    r = r > 1 ? 1: r; r = r < 0 ? 0: r;
    g = g > 1 ? 1: g; g = g < 0 ? 0: g;
    b = b > 1 ? 1: b; b = b < 0 ? 0: b;
    
    // uint32_t instead of uint8_t as ostream treats uint8_t as unsigned char
    // and prints its byte value instead of the number as ascii
    out << static_cast<uint32_t>(255.999 * r) << ' '
        << static_cast<uint32_t>(255.999 * g) << ' '
        << static_cast<uint32_t>(255.999 * b) << ' ';
}

inline void write_color_bytes(std::ostream &out, double r, double g, double b) {
    r = r > 1 ? 1: r; r = r < 0 ? 0: r;
    g = g > 1 ? 1: g; g = g < 0 ? 0: g;
    b = b > 1 ? 1: b; b = b < 0 ? 0: b;
    
    // passing uint8_t to ostream makes it print the number's byte value
    out << static_cast<uint8_t>(255.999 * r)
        << static_cast<uint8_t>(255.999 * g)
        << static_cast<uint8_t>(255.999 * b);
}
