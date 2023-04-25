#include "render.hpp"
#include "../structs/color.hpp"
#include "../structs/vec3.hpp"
#include "../structs/ray.hpp"
#include "../structs/hit.hpp"
#include "../camera/image_camera.hpp"

#include <cstdint>
#include <iostream>

color ray_color(const ray& r) {
    double t = hit_point(point3(0, 0, -1), 0.5, r);
    if (t> 0.0) {
        vec3 N  = unit_vector(r.at(t) - vec3(0, 0, -1));
        return 0.5*color(N.x()+1, N.y()+1, N.z()+1);
    }
    vec3 unit_direction = unit_vector(r.direction());
    t = 0.5*(unit_direction.y()  + 1.0);
    return (1.0-t) * color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

void render(bool ascii) {
    if (ascii) {
        std::cout << "P3\n" << image::image_width << ' ' << image::image_height << "\n255\n";
    } else {
        std::cout << "P6\n" << image::image_width << ' ' << image::image_height << "\n255\n";
    }

    // int32_t instead of uint32_t as j goes till -1
    for (int32_t j = image::image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int32_t i = 0; i < image::image_width; ++i) {
            double u = double(i) / (image::image_width-1);
            double v = double(j) / (image::image_height-1);

            ray r(camera::origin, camera::lower_left_corner + u*camera::horizontal + v*camera::vertical - camera::origin);
            color pixel_color = ray_color(r);

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

