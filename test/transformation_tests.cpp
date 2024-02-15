#include "gtest/gtest.h"
#include <cmath>
#include <numbers>
#include "../src/structs/rt_tuples.hpp"
#include "../src/structs/rt_matrix.hpp"
#include "../src/structs/rt_transformations.hpp"

double pi = std::numbers::pi;

TEST(transformationTests, multiplying_by_translation_matrix) {
    rt_matrix_4 transform = rt_transformations::translation(5, -3, 2);
    rt_tuple p = rt_tuple::point(-3, 4, 5);
    
    rt_tuple ref = rt_tuple::point(2, 1, 7);
    EXPECT_EQ(transform * p, ref);
}

TEST(transformationTests, multiplying_by_inverse_of_translation_matrix) {
    rt_matrix_4 transform = rt_transformations::translation(5, -3, 2);
    rt_matrix_4 inv = rt_matrix_4::inverse(transform);
    rt_tuple p = rt_tuple::point(-3, 4, 5);
    
    rt_tuple ref = rt_tuple::point(-8, 7, 3);
    EXPECT_EQ(inv * p, ref);
}

TEST(transformationTests, translation_does_not_affect_vector) {
    rt_matrix_4 transform = rt_transformations::translation(5, -3, 2);
    rt_tuple v = rt_tuple::vector(-3, 4, 5);
    
    EXPECT_EQ(transform * v, v);
}

TEST(transformationTests, scaling_point) {
    rt_matrix_4 transform = rt_transformations::scaling(2, 3, 4);
    rt_tuple p = rt_tuple::point(-4, 6, 8);
    
    rt_tuple ref = rt_tuple::point(-8, 18, 32);
    EXPECT_EQ(transform * p, ref);
}

TEST(transformationTests, scaling_vector) {
    rt_matrix_4 transform = rt_transformations::scaling(2, 3, 4);
    rt_tuple v = rt_tuple::vector(-4, 6, 8);
    
    rt_tuple ref = rt_tuple::vector(-8, 18, 32);
    EXPECT_EQ(transform * v, ref);
}

TEST(transformationTests, inverse_scaling_vector) {
    rt_matrix_4 transform = rt_transformations::scaling(2, 3, 4);
    rt_matrix_4 inv = rt_matrix_4::inverse(transform);
    rt_tuple v = rt_tuple::vector(-4, 6, 8);
    
    rt_tuple ref = rt_tuple::vector(-2, 2, 2);
    EXPECT_EQ(inv * v, ref);
}

TEST(transformationTests, reflection_is_scaling_by_negative_value) {
    rt_matrix_4 transform = rt_transformations::scaling(-1, 1, 1);
    rt_tuple p = rt_tuple::point(2, 3, 4);
    
    rt_tuple ref = rt_tuple::point(-2, 3, 4);
    EXPECT_EQ(transform * p, ref);
}

TEST(transformationTests, rotating_point_x_axis) {
    rt_tuple p = rt_tuple::point(0, 1, 0);
    rt_matrix_4 half_quarter = rt_transformations::rotation_x(pi/4);
    rt_matrix_4 full_quarter = rt_transformations::rotation_x(pi/2);

    rt_tuple ref_half = rt_tuple::point(0, sqrt(2)/2, sqrt(2)/2);
    rt_tuple ref_full = rt_tuple::point(0, 0, 1);
    EXPECT_EQ(half_quarter * p, ref_half);
    EXPECT_EQ(full_quarter * p, ref_full);
}

TEST(transformationTests, inverse_rotating_point_x_axis) {
    rt_tuple p = rt_tuple::point(0, 1, 0);
    rt_matrix_4 half_quarter = rt_transformations::rotation_x(pi/4);
    rt_matrix_4 inv = rt_matrix_4::inverse(half_quarter);

    rt_tuple ref_half = rt_tuple::point(0, sqrt(2)/2, -sqrt(2)/2);
    EXPECT_EQ(inv * p, ref_half);
}

TEST(transformationTests, rotating_point_y_axis) {
    rt_tuple p = rt_tuple::point(0, 0, 1);
    rt_matrix_4 half_quarter = rt_transformations::rotation_y(pi/4);
    rt_matrix_4 full_quarter = rt_transformations::rotation_y(pi/2);

    rt_tuple ref_half = rt_tuple::point(sqrt(2)/2, 0, sqrt(2)/2);
    rt_tuple ref_full = rt_tuple::point(1, 0, 0);
    EXPECT_EQ(half_quarter * p, ref_half);
    EXPECT_EQ(full_quarter * p, ref_full);
}

TEST(transformationTests, rotating_point_z_axis) {
    rt_tuple p = rt_tuple::point(0, 1, 0);
    rt_matrix_4 half_quarter = rt_transformations::rotation_z(pi/4);
    rt_matrix_4 full_quarter = rt_transformations::rotation_z(pi/2);

    rt_tuple ref_half = rt_tuple::point(-sqrt(2)/2, sqrt(2)/2, 0);
    rt_tuple ref_full = rt_tuple::point(-1, 0, 0);
    EXPECT_EQ(half_quarter * p, ref_half);
    EXPECT_EQ(full_quarter * p, ref_full);
}

TEST(transformationTests, shearing_moves_x_in_proportion_to_y) {
    rt_matrix_4 transform = rt_transformations::shearing(1, 0, 0, 0, 0, 0);
    rt_tuple p = rt_tuple::point(2, 3, 4);

    rt_tuple ref = rt_tuple::point(5, 3, 4);
    EXPECT_EQ(transform * p, ref);
}

TEST(transformationTests, shearing_moves_x_in_proportion_to_z) {
    rt_matrix_4 transform = rt_transformations::shearing(0, 1, 0, 0, 0, 0);
    rt_tuple p = rt_tuple::point(2, 3, 4);

    rt_tuple ref = rt_tuple::point(6, 3, 4);
    EXPECT_EQ(transform * p, ref);
}

TEST(transformationTests, shearing_moves_y_in_proportion_to_x) {
    rt_matrix_4 transform = rt_transformations::shearing(0, 0, 1, 0, 0, 0);
    rt_tuple p = rt_tuple::point(2, 3, 4);

    rt_tuple ref = rt_tuple::point(2, 5, 4);
    EXPECT_EQ(transform * p, ref);
}

TEST(transformationTests, shearing_moves_y_in_proportion_to_z) {
    rt_matrix_4 transform = rt_transformations::shearing(0, 0, 0, 1, 0, 0);
    rt_tuple p = rt_tuple::point(2, 3, 4);

    rt_tuple ref = rt_tuple::point(2, 7, 4);
    EXPECT_EQ(transform * p, ref);
}

TEST(transformationTests, shearing_moves_z_in_proportion_to_x) {
    rt_matrix_4 transform = rt_transformations::shearing(0, 0, 0, 0, 1, 0);
    rt_tuple p = rt_tuple::point(2, 3, 4);

    rt_tuple ref = rt_tuple::point(2, 3, 6);
    EXPECT_EQ(transform * p, ref);
}

TEST(transformationTests, shearing_moves_z_in_proportion_to_y) {
    rt_matrix_4 transform = rt_transformations::shearing(0, 0, 0, 0, 0, 1);
    rt_tuple p = rt_tuple::point(2, 3, 4);

    rt_tuple ref = rt_tuple::point(2, 3, 7);
    EXPECT_EQ(transform * p, ref);
}

TEST(transformationTests, individual_transformations_are_applied_in_sequence) {
    rt_tuple p = rt_tuple::point(1, 0, 1);
    rt_matrix_4 A = rt_transformations::rotation_x(pi/2);
    rt_matrix_4 B = rt_transformations::scaling(5, 5, 5);
    rt_matrix_4 C = rt_transformations::translation(10, 5, 7);

    rt_tuple p2 = A * p;
    rt_tuple ref_p2 = rt_tuple::point(1, -1, 0);
    EXPECT_EQ(p2, ref_p2);

    rt_tuple p3 = B * p2;
    rt_tuple ref_p3 = rt_tuple::point(5, -5, 0);
    EXPECT_EQ(p3, ref_p3);

    rt_tuple p4 = C * p3;
    rt_tuple ref_p4 = rt_tuple::point(15, 0, 7);
    EXPECT_EQ(p4, ref_p4);
}

TEST(transformationTests, chained_transformations_must_be_applied_in_reverse_order) {
    rt_tuple p = rt_tuple::point(1, 0, 1);
    rt_matrix_4 A = rt_transformations::rotation_x(pi/2);
    rt_matrix_4 B = rt_transformations::scaling(5, 5, 5);
    rt_matrix_4 C = rt_transformations::translation(10, 5, 7);

    rt_matrix_4 T = C * B * A;
    rt_tuple ref = rt_tuple::point(15, 0, 7);
    EXPECT_EQ(T * p, ref);
}

TEST(transformationTests, chained_transformations_as_matrix_functions) {
    rt_tuple p = rt_tuple::point(1, 0, 1);
    rt_matrix_4 T = rt_matrix_4::id_matrix().rotation_x(pi/2).scaling(5, 5, 5).translation(10, 5, 7);

    rt_tuple ref = rt_tuple::point(15, 0, 7);
    EXPECT_EQ(T * p, ref);
}
