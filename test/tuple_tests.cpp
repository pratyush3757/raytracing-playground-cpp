#include "gtest/gtest.h"
#include <cmath>
#include "../src/structs/rt_tuples.hpp"

TEST(tupleTests, check_is_point_is_vector) {
    rt_tuple point = rt_tuple(4.3l, -4.2l, 3.1l, 1.0l);
    EXPECT_TRUE(point.is_point());
    EXPECT_FALSE(point.is_vector());

    rt_tuple vector = rt_tuple(4.3l, -4.2l, 3.1l, 0.0l);
    EXPECT_TRUE(vector.is_vector());
    EXPECT_FALSE(vector.is_point());
}

TEST(tupleTests, check_values) {
    rt_tuple tup = rt_tuple(4.3l, -4.2l, 3.1l, 0.0l);
    EXPECT_EQ(tup.x(), 4.3);
    EXPECT_EQ(tup.y(), -4.2);
    EXPECT_EQ(tup.z(), 3.1);
}

TEST(tupleTests, check_point_vector_constructors) {
    rt_tuple point = rt_tuple::point(4, -4, 3);
    EXPECT_TRUE(point.is_point());

    rt_tuple vector = rt_tuple::vector(4, -4, 3);
    EXPECT_TRUE(vector.is_vector());
}

TEST(tupleTests, adding_tuples) {
    rt_tuple tuple_1 = rt_tuple(3, -2, 5, 1);
    rt_tuple tuple_2 = rt_tuple(-2, 3, 1, 0);
    rt_tuple added = tuple_1 + tuple_2;

    rt_tuple ref_pos = rt_tuple(1, 1, 6, 0);
    EXPECT_TRUE(added == ref_pos);
}

TEST(tupleTests, subtracting_point_from_point) {
    rt_tuple point_1 = rt_tuple::point(3, 2, 1);
    rt_tuple point_2 = rt_tuple::point(5, 6, 7);

    rt_tuple subtracted = point_1 - point_2;
    EXPECT_TRUE(subtracted.is_vector());

    rt_tuple ref = rt_tuple::vector(-2, -4, -6);
    EXPECT_TRUE(subtracted == ref);
}

TEST(tupleTests, subtracting_vector_from_point) {
    rt_tuple point = rt_tuple::point(3, 2, 1);
    rt_tuple vector = rt_tuple::vector(5, 6, 7);

    rt_tuple subtracted = point - vector;
    EXPECT_TRUE(subtracted.is_point());

    rt_tuple ref = rt_tuple::point(-2, -4, -6);
    EXPECT_TRUE(subtracted == ref);
}

TEST(tupleTests, subtracting_vector_from_vector) {
    rt_tuple vector_1 = rt_tuple::vector(3, 2, 1);
    rt_tuple vector_2 = rt_tuple::vector(5, 6, 7);

    rt_tuple subtracted = vector_1 - vector_2;
    EXPECT_TRUE(subtracted.is_vector());

    rt_tuple ref = rt_tuple::vector(-2, -4, -6);
    EXPECT_TRUE(subtracted == ref);
}

TEST(tupleTests, subtracting_vector_from_zero_vector) {
    rt_tuple vector_1 = rt_tuple::vector(0, 0, 0);
    rt_tuple vector_2 = rt_tuple::vector(1, -2, 3);

    rt_tuple subtracted = vector_1 - vector_2;
    EXPECT_TRUE(subtracted.is_vector());

    rt_tuple ref = rt_tuple::vector(-1, 2, -3);
    EXPECT_TRUE(subtracted == ref);
}

TEST(tupleTests, negating_tuple) {
    rt_tuple tuple_1 = rt_tuple(1, -2, 3, -4);

    rt_tuple negated = -tuple_1;

    rt_tuple ref = rt_tuple(-1, 2, -3, 4);
    EXPECT_TRUE(negated == ref);
}

TEST(tupleTests, multiplying_tuple_by_scalar) {
    rt_tuple tuple_1 = rt_tuple(1, -2, 3, -4);

    rt_tuple multiplied = tuple_1 * 3.5;

    rt_tuple ref = rt_tuple(3.5, -7, 10.5, -14);
    EXPECT_TRUE(multiplied == ref);
}

TEST(tupleTests, multiplying_tuple_by_fraction) {
    rt_tuple tuple_1 = rt_tuple(1, -2, 3, -4);

    rt_tuple multiplied = tuple_1 * 0.5;

    rt_tuple ref = rt_tuple(0.5, -1, 1.5, -2);
    EXPECT_TRUE(multiplied == ref);
}

TEST(tupleTests, dividing_tuple_by_scalar) {
    rt_tuple tuple_1 = rt_tuple(1, -2, 3, -4);

    rt_tuple multiplied = tuple_1 / 2;

    rt_tuple ref = rt_tuple(0.5, -1, 1.5, -2);
    EXPECT_TRUE(multiplied == ref);
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
    EXPECT_TRUE(normalized.is_vector());

    rt_tuple ref = rt_tuple::vector(1, 0, 0);
    EXPECT_TRUE(normalized == ref);
}

TEST(tupleTests, normalize_vector_2) {
    rt_tuple vector_1 = rt_tuple::vector(1, 2, 3);

    rt_tuple normalized = rt_tuple::normalize(vector_1);
    EXPECT_TRUE(normalized.is_vector());

    rt_tuple ref = rt_tuple::vector(0.26726, 0.53452, 0.80178);
    EXPECT_TRUE(normalized == ref);
}

TEST(tupleTests, normalize_vector_magnitude) {
    rt_tuple vector_1 = rt_tuple::vector(1, 2, 3);

    rt_tuple normalized = rt_tuple::normalize(vector_1);
    EXPECT_TRUE(normalized.is_vector());

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
    EXPECT_TRUE(cross_product_1_2.is_vector());

    rt_tuple ref = rt_tuple::vector(-1, 2, -1);
    EXPECT_TRUE(cross_product_1_2 == ref);
    
    rt_tuple cross_product_2_1 = rt_tuple::cross(vector_2, vector_1);
    EXPECT_TRUE(cross_product_2_1.is_vector());

    rt_tuple ref_2 = rt_tuple::vector(1, -2, 1);
    EXPECT_TRUE(cross_product_2_1 == ref_2);
}
