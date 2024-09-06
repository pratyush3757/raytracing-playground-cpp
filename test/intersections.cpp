#include "gtest/gtest.h"
#include "rt_body.hpp"

TEST(interesctionTests, hit_all_intersections_have_positive_t) {
    rt_sphere sph = rt_sphere(1);
    rt_body::intersection i1 = {1, &sph};
    rt_body::intersection i2 = {2, &sph};
    rt_body::intersections xs = {i2, i1};

    std::optional<rt_body::intersection> i = rt_body::hit(xs);

    EXPECT_TRUE(i.has_value());
    EXPECT_EQ(i.value().t, i1.t);
}

TEST(interesctionTests, hit_some_intersections_have_negative_t) {
    rt_sphere sph = rt_sphere(1);
    rt_body::intersection i1 = {-1, &sph};
    rt_body::intersection i2 = {1, &sph};
    rt_body::intersections xs = {i2, i1};

    std::optional<rt_body::intersection> i = rt_body::hit(xs);

    EXPECT_TRUE(i.has_value());
    EXPECT_EQ(i.value().t, i2.t);
}

TEST(interesctionTests, hit_all_intersections_have_negative_t) {
    rt_sphere sph = rt_sphere(1);
    rt_body::intersection i1 = {-2, &sph};
    rt_body::intersection i2 = {-1, &sph};
    rt_body::intersections xs = {i2, i1};

    std::optional<rt_body::intersection> i = rt_body::hit(xs);

    EXPECT_FALSE(i.has_value());
}

TEST(interesctionTests, hit_smallest_nonnegative_intersection) {
    rt_sphere sph = rt_sphere(1);
    rt_body::intersection i1 = {5, &sph};
    rt_body::intersection i2 = {7, &sph};
    rt_body::intersection i3 = {-3, &sph};
    rt_body::intersection i4 = {2, &sph};
    rt_body::intersections xs = {i1, i2, i3, i4};

    std::optional<rt_body::intersection> i = rt_body::hit(xs);

    EXPECT_TRUE(i.has_value());
    EXPECT_EQ(i.value().t, i4.t);
}
