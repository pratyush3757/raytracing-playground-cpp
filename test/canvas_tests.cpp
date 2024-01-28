#include "gtest/gtest.h"
#include <cmath>
#include <cstddef>
#include "../src/structs/rt_tuples.hpp"
#include "../src/structs/rt_colors.hpp"
#include "../src/structs/rt_canvas.hpp"

TEST(canvasTests, creating_canvas) {
    rt_canvas full_canvas = rt_canvas(10, 20);
    rt_color ref = rt_color(0,0,0);
    for (auto const& row : full_canvas.canvas) {
        for (auto const& pixel : row) {
            EXPECT_EQ(ref == pixel, true);
        }
    }
    EXPECT_EQ(full_canvas.width, 10);
    EXPECT_EQ(full_canvas.height, 20);
}

TEST(canvasTests, writing_pixel_to_canvas) {
    rt_canvas full_canvas = rt_canvas(10, 20);
    rt_color ref = rt_color(1, 0, 0);
    full_canvas.write_pixel(2, 3, ref);

    EXPECT_EQ(full_canvas.width, 10);
    EXPECT_EQ(full_canvas.height, 20);
    EXPECT_EQ(full_canvas.canvas[3][2], ref);
}
