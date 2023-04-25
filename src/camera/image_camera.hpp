#include "../structs/vec3.hpp"
#include <cstdint>

namespace image {
    const double aspect_ratio = 16.0 / 9.0;
    const uint32_t image_width = 400;
    const uint32_t image_height = static_cast<uint32_t>(image_width / aspect_ratio);
}

namespace camera
{
    double viewport_height = 2.0;
    double viewport_width = image::aspect_ratio * viewport_height;
    double focal_length = 1.0;

    point3 origin = point3(0, 0, 0);
    vec3 horizontal = vec3(viewport_width, 0, 0);
    vec3 vertical = vec3(0, viewport_height, 0);
    point3 lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
}
