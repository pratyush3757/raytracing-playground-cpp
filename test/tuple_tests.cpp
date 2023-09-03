#include "gtest/gtest.h"
#include "../src/structs/rt_tuples.hpp"

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
