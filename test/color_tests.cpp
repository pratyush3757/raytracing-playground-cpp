#include "gtest/gtest.h"
#include <cmath>
#include "../src/structs/rt_tuples.hpp"
#include "../src/structs/rt_colors.hpp"

TEST(colorTests, colors_are_rgb_tuples) {
    rt_color color_1 = rt_color(-0.5, 0.4, 1.7);
    EXPECT_EQ(color_1.r(), -0.5);
    EXPECT_EQ(color_1.g(), 0.4);
    EXPECT_EQ(color_1.b(), 1.7);
}

TEST(colorTests, adding_colors) {
    rt_color color_1 = rt_color(0.9, 0.6, 0.75);
    rt_color color_2 = rt_color(0.7, 0.1, 0.25);
    
    rt_color added = color_1 + color_2;

    rt_color ref = rt_color(1.6, 0.7, 1.0);

    EXPECT_TRUE(ref == added);
}

TEST(colorTests, subtracting_colors) {
    rt_color color_1 = rt_color(0.9, 0.6, 0.75);
    rt_color color_2 = rt_color(0.7, 0.1, 0.25);
    
    rt_color subtracted = color_1 - color_2;

    rt_color ref = rt_color(0.2, 0.5, 0.5);

    EXPECT_TRUE(ref == subtracted);
}

TEST(colorTests, multiplying_color_by_scalar) {
    rt_color color_1 = rt_color(0.2, 0.3, 0.4);
    
    rt_color multiplied = color_1 * 2;

    rt_color ref = rt_color(0.4, 0.6, 0.8);

    EXPECT_TRUE(ref == multiplied);
}

TEST(colorTests, multiplying_colors) {
    rt_color color_1 = rt_color(1, 0.2, 0.4);
    rt_color color_2 = rt_color(0.9, 1, 0.1);
    
    rt_color multiplied = color_1 * color_2;

    rt_color ref = rt_color(0.9, 0.2, 0.04);

    EXPECT_TRUE(ref == multiplied);
}
