#include "gtest/gtest.h"
#include <cmath>
#include "../src/structs/rt_tuples.hpp"
#include "../src/structs/rt_colors.hpp"

TEST(tupleTests, check_is_point_is_vector) {
    rt_tuple point = rt_tuple(4.3l, -4.2l, 3.1l, 1.0l);
    EXPECT_EQ(point.is_point(), true);
    EXPECT_NE(point.is_vector(), true);

    rt_tuple vector = rt_tuple(4.3l, -4.2l, 3.1l, 0.0l);
    EXPECT_EQ(vector.is_vector(), true);
    EXPECT_NE(vector.is_point(), true);
}

TEST(tupleTests, check_values) {
    rt_tuple tup = rt_tuple(4.3l, -4.2l, 3.1l, 0.0l);
    EXPECT_EQ(tup.x(), 4.3);
    EXPECT_EQ(tup.y(), -4.2);
    EXPECT_EQ(tup.z(), 3.1);
}

TEST(tupleTests, check_point_vector_constructors) {
    rt_tuple point = rt_tuple::point(4, -4, 3);
    EXPECT_EQ(point.is_point(), true);

    rt_tuple vector = rt_tuple::vector(4, -4, 3);
    EXPECT_EQ(vector.is_vector(), true);
}

TEST(tupleTests, adding_tuples) {
    rt_tuple tuple_1 = rt_tuple(3, -2, 5, 1);
    rt_tuple tuple_2 = rt_tuple(-2, 3, 1, 0);
    rt_tuple added = tuple_1 + tuple_2;

    rt_tuple ref_pos = rt_tuple(1, 1, 6, 0);
    EXPECT_EQ(added == ref_pos, true);
}

TEST(tupleTests, subtracting_point_from_point) {
    rt_tuple point_1 = rt_tuple::point(3, 2, 1);
    rt_tuple point_2 = rt_tuple::point(5, 6, 7);

    rt_tuple subtracted = point_1 - point_2;
    EXPECT_EQ(subtracted.is_vector(), true);

    rt_tuple ref = rt_tuple::vector(-2, -4, -6);
    EXPECT_EQ(subtracted == ref, true);
}

TEST(tupleTests, subtracting_vector_from_point) {
    rt_tuple point = rt_tuple::point(3, 2, 1);
    rt_tuple vector = rt_tuple::vector(5, 6, 7);

    rt_tuple subtracted = point - vector;
    EXPECT_EQ(subtracted.is_point(), true);

    rt_tuple ref = rt_tuple::point(-2, -4, -6);
    EXPECT_EQ(subtracted == ref, true);
}

TEST(tupleTests, subtracting_vector_from_vector) {
    rt_tuple vector_1 = rt_tuple::vector(3, 2, 1);
    rt_tuple vector_2 = rt_tuple::vector(5, 6, 7);

    rt_tuple subtracted = vector_1 - vector_2;
    EXPECT_EQ(subtracted.is_vector(), true);

    rt_tuple ref = rt_tuple::vector(-2, -4, -6);
    EXPECT_EQ(subtracted == ref, true);
}

TEST(tupleTests, subtracting_vector_from_zero_vector) {
    rt_tuple vector_1 = rt_tuple::vector(0, 0, 0);
    rt_tuple vector_2 = rt_tuple::vector(1, -2, 3);

    rt_tuple subtracted = vector_1 - vector_2;
    EXPECT_EQ(subtracted.is_vector(), true);

    rt_tuple ref = rt_tuple::vector(-1, 2, -3);
    EXPECT_EQ(subtracted == ref, true);
}

TEST(tupleTests, negating_tuple) {
    rt_tuple tuple_1 = rt_tuple(1, -2, 3, -4);

    rt_tuple negated = -tuple_1;

    rt_tuple ref = rt_tuple(-1, 2, -3, 4);
    EXPECT_EQ(negated == ref, true);
}

TEST(tupleTests, multiplying_tuple_by_scalar) {
    rt_tuple tuple_1 = rt_tuple(1, -2, 3, -4);

    rt_tuple multiplied = tuple_1 * 3.5;

    rt_tuple ref = rt_tuple(3.5, -7, 10.5, -14);
    EXPECT_EQ(multiplied == ref, true);
}

TEST(tupleTests, multiplying_tuple_by_fraction) {
    rt_tuple tuple_1 = rt_tuple(1, -2, 3, -4);

    rt_tuple multiplied = tuple_1 * 0.5;

    rt_tuple ref = rt_tuple(0.5, -1, 1.5, -2);
    EXPECT_EQ(multiplied == ref, true);
}

TEST(tupleTests, dividing_tuple_by_scalar) {
    rt_tuple tuple_1 = rt_tuple(1, -2, 3, -4);

    rt_tuple multiplied = tuple_1 / 2;

    rt_tuple ref = rt_tuple(0.5, -1, 1.5, -2);
    EXPECT_EQ(multiplied == ref, true);
}

TEST(tupleTests, magnitude_1) {
    rt_tuple vector_1 = rt_tuple::vector(1, 0, 0);

    double mag = rt_tuple::magnitude(vector_1);

    EXPECT_EQ(mag, 1);
}

TEST(tupleTests, magnitude_2) {
    rt_tuple vector_1 = rt_tuple::vector(0, 1, 0);

    double mag = rt_tuple::magnitude(vector_1);

    EXPECT_EQ(mag, 1);
}

TEST(tupleTests, magnitude_3) {
    rt_tuple vector_1 = rt_tuple::vector(0, 0, 1);

    double mag = rt_tuple::magnitude(vector_1);

    EXPECT_EQ(mag, 1);
}

TEST(tupleTests, magnitude_4) {
    rt_tuple vector_1 = rt_tuple::vector(1, 2, 3);

    double mag = rt_tuple::magnitude(vector_1);

    EXPECT_EQ(mag, std::sqrt(14));
}

TEST(tupleTests, magnitude_5) {
    rt_tuple vector_1 = rt_tuple::vector(-1, -2, -3);

    double mag = rt_tuple::magnitude(vector_1);

    EXPECT_EQ(mag, std::sqrt(14));
}

TEST(tupleTests, normalize_vector_1) {
    rt_tuple vector_1 = rt_tuple::vector(4, 0, 0);

    rt_tuple normalized = rt_tuple::normalize(vector_1);
    EXPECT_EQ(normalized.is_vector(), true);

    rt_tuple ref = rt_tuple::vector(1, 0, 0);
    EXPECT_EQ(normalized == ref, true);
}

TEST(tupleTests, normalize_vector_2) {
    rt_tuple vector_1 = rt_tuple::vector(1, 2, 3);

    rt_tuple normalized = rt_tuple::normalize(vector_1);
    EXPECT_EQ(normalized.is_vector(), true);

    rt_tuple ref = rt_tuple::vector(0.26726, 0.53452, 0.80178);
    EXPECT_EQ(normalized == ref, true);
}

TEST(tupleTests, normalize_vector_magnitude) {
    rt_tuple vector_1 = rt_tuple::vector(1, 2, 3);

    rt_tuple normalized = rt_tuple::normalize(vector_1);
    EXPECT_EQ(normalized.is_vector(), true);

    double mag = rt_tuple::magnitude(normalized);
    EXPECT_EQ(mag, 1);
}

TEST(tupleTests, dot_product_of_two_vectors) {
    rt_tuple vector_1 = rt_tuple::vector(1, 2, 3);
    rt_tuple vector_2 = rt_tuple::vector(2, 3, 4);

    double dot_product = rt_tuple::dot(vector_1, vector_2);

    EXPECT_EQ(dot_product, 20);
}

TEST(tupleTests, cross_product_of_two_vectors) {
    rt_tuple vector_1 = rt_tuple::vector(1, 2, 3);
    rt_tuple vector_2 = rt_tuple::vector(2, 3, 4);

    rt_tuple cross_product_1_2 = rt_tuple::cross(vector_1, vector_2);
    EXPECT_EQ(cross_product_1_2.is_vector(), true);

    rt_tuple ref = rt_tuple::vector(-1, 2, -1);
    EXPECT_EQ(cross_product_1_2 == ref, true);
    
    rt_tuple cross_product_2_1 = rt_tuple::cross(vector_2, vector_1);
    EXPECT_EQ(cross_product_2_1.is_vector(), true);

    rt_tuple ref_2 = rt_tuple::vector(1, -2, 1);
    EXPECT_EQ(cross_product_2_1 == ref_2, true);
}

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

    EXPECT_EQ(ref == added, true);
}

TEST(colorTests, subtracting_colors) {
    rt_color color_1 = rt_color(0.9, 0.6, 0.75);
    rt_color color_2 = rt_color(0.7, 0.1, 0.25);
    
    rt_color subtracted = color_1 - color_2;

    rt_color ref = rt_color(0.2, 0.5, 0.5);

    EXPECT_EQ(ref == subtracted, true);
}

TEST(colorTests, multiplying_color_by_scalar) {
    rt_color color_1 = rt_color(0.2, 0.3, 0.4);
    
    rt_color multiplied = color_1 * 2;

    rt_color ref = rt_color(0.4, 0.6, 0.8);

    EXPECT_EQ(ref == multiplied, true);
}

TEST(colorTests, multiplying_colors) {
    rt_color color_1 = rt_color(1, 0.2, 0.4);
    rt_color color_2 = rt_color(0.9, 1, 0.1);
    
    rt_color multiplied = color_1 * color_2;

    rt_color ref = rt_color(0.9, 0.2, 0.04);

    EXPECT_EQ(ref == multiplied, true);
}
