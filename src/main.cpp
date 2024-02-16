#include "rt_canvas.hpp"
#include "rt_matrix.hpp"
#include "rt_tuples.hpp"
#include "rt_transformations.hpp"
#include "ppm.hpp"
#include <cstddef>
#include <iostream>
#include <numbers>

int main(int argc, char **argv) {
    size_t width, height;
    width = 800;
    height = 800;
    rt_canvas canvas = rt_canvas(width, height);
    rt_color pixel = rt_color(1, 1, 1);

    rt_tuple point = rt_tuple::point(0, 0, 0);
    rt_matrix_4 translate = rt_transformations::translation(300, 0, 0);
    point = translate * point;

    rt_matrix_4 rotate_anti_clock = rt_transformations::rotation_z(std::numbers::pi/6);

    double x, y;

    for(size_t i = 0; i < 12; i++) {
        point = rotate_anti_clock * point;
        x = point.x();
        y = point.y();
        canvas.write_pixel(x+400, y+400, pixel);
    }
    
    ppm::render_plain(canvas);
    return 0;
}
