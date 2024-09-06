#include "gtest/gtest.h"
#include <cmath>
#include <optional>
#include "../src/structs/rt_tuples.hpp"
#include "../src/structs/rt_ray.hpp"
#include "../src/structs/rt_body.hpp"
#include "rt_matrix.hpp"
#include "rt_transformations.hpp"

#define XSOPT std::optional<rt_body::intersections>

TEST(rayTests, creating_and_querying_ray) {
    rt_tuple ray_origin = rt_tuple::point(1, 2, 3);
    rt_tuple ray_direction = rt_tuple::vector(4, 5, 6);
    rt_ray ref = rt_ray(ray_origin, ray_direction);

    EXPECT_EQ(ref.origin, ray_origin);
    EXPECT_EQ(ref.direction, ray_direction);
}

TEST(rayTests, computing_a_point_from_distance) {
    rt_tuple ray_origin = rt_tuple::point(2, 3, 4);
    rt_tuple ray_direction = rt_tuple::vector(1, 0, 0);
    rt_ray ref = rt_ray(ray_origin, ray_direction);

    EXPECT_EQ(rt_ray::position(ref, 0), rt_tuple::point(2, 3, 4));
    EXPECT_EQ(rt_ray::position(ref, 1), rt_tuple::point(3, 3, 4));
    EXPECT_EQ(rt_ray::position(ref, -1), rt_tuple::point(1, 3, 4));
    EXPECT_EQ(rt_ray::position(ref, 2.5), rt_tuple::point(4.5, 3, 4));
}

TEST(raySphereTests, ray_intersects_sphere_two_points) {
    rt_ray ref_ray = rt_ray(rt_tuple::point(0, 0, -5), rt_tuple::vector(0, 0, 1));
    rt_sphere ref_sphere = rt_sphere(1);

    XSOPT xs_opt = rt_body::intersect(ref_sphere, ref_ray);
    EXPECT_TRUE(xs_opt.has_value());
    rt_body::intersections xs = xs_opt.value();
    EXPECT_EQ(xs.size(), 2);
    EXPECT_TRUE(equal(xs[0].t, 4.0));
    EXPECT_TRUE(equal(xs[1].t, 6.0));
}

TEST(raySphereTests, ray_intersects_sphere_tangent) {
    rt_ray ref_ray = rt_ray(rt_tuple::point(0, 1, -5), rt_tuple::vector(0, 0, 1));
    rt_sphere ref_sphere = rt_sphere(1);

    XSOPT xs_opt = rt_body::intersect(ref_sphere, ref_ray);
    EXPECT_TRUE(xs_opt.has_value());
    rt_body::intersections xs = xs_opt.value();
    EXPECT_EQ(xs.size(), 2);
    EXPECT_TRUE(equal(xs[0].t, 5.0));
    EXPECT_TRUE(equal(xs[1].t, 5.0));
}

TEST(raySphereTests, ray_misses_sphere) {
    rt_ray ref_ray = rt_ray(rt_tuple::point(0, 2, -5), rt_tuple::vector(0, 0, 1));
    rt_sphere ref_sphere = rt_sphere(1);

    XSOPT xs_opt = rt_body::intersect(ref_sphere, ref_ray);
    EXPECT_FALSE(xs_opt.has_value());
}

TEST(raySphereTests, ray_originates_inside_sphere) {
    rt_ray ref_ray = rt_ray(rt_tuple::point(0, 0, 0), rt_tuple::vector(0, 0, 1));
    rt_sphere ref_sphere = rt_sphere(1);

    XSOPT xs_opt = rt_body::intersect(ref_sphere, ref_ray);
    EXPECT_TRUE(xs_opt.has_value());
    rt_body::intersections xs = xs_opt.value();
    EXPECT_EQ(xs.size(), 2);
    EXPECT_TRUE(equal(xs[0].t, -1.0));
    EXPECT_TRUE(equal(xs[1].t, 1.0));
}

TEST(raySphereTests, sphere_behind_ray) {
    rt_ray ref_ray = rt_ray(rt_tuple::point(0, 0, 5), rt_tuple::vector(0, 0, 1));
    rt_sphere ref_sphere = rt_sphere(1);

    XSOPT xs_opt = rt_body::intersect(ref_sphere, ref_ray);
    EXPECT_TRUE(xs_opt.has_value());
    rt_body::intersections xs = xs_opt.value();
    EXPECT_EQ(xs.size(), 2);
    EXPECT_TRUE(equal(xs[0].t, -6.0));
    EXPECT_TRUE(equal(xs[1].t, -4.0));
}

TEST(raySphereTests, intersection_sets_the_object) {
    rt_ray ref_ray = rt_ray(rt_tuple::point(0, 0, -5), rt_tuple::vector(0, 0, 1));
    rt_sphere ref_sphere = rt_sphere(1);

    XSOPT xs_opt = rt_body::intersect(ref_sphere, ref_ray);
    EXPECT_TRUE(xs_opt.has_value());
    rt_body::intersections xs = xs_opt.value();
    EXPECT_EQ(xs.size(), 2);
    EXPECT_EQ(xs[0].obj->id, ref_sphere.id);
}

TEST(rayTests, translating_a_ray) {
    rt_ray ref_ray = rt_ray(rt_tuple::point(1, 2, 3), rt_tuple::vector(0, 1, 0));
    rt_matrix_4 trans = rt_transformations::translation(3, 4, 5);
    rt_ray ray2 = rt_ray::transform(ref_ray, trans);

    EXPECT_EQ(ray2.origin, rt_tuple::point(4, 6, 8));
    EXPECT_EQ(ray2.direction, rt_tuple::vector(0, 1, 0));
}

TEST(rayTests, scaling_a_ray) {
    rt_ray ref_ray = rt_ray(rt_tuple::point(1, 2, 3), rt_tuple::vector(0, 1, 0));
    rt_matrix_4 trans = rt_transformations::scaling(2, 3, 4);
    rt_ray ray2 = rt_ray::transform(ref_ray, trans);

    EXPECT_EQ(ray2.origin, rt_tuple::point(2, 6, 12));
    EXPECT_EQ(ray2.direction, rt_tuple::vector(0, 3, 0));
}

TEST(sphereTests, sphere_default_transformation) {
    rt_sphere ref_sphere = rt_sphere(1);

    EXPECT_EQ(ref_sphere.transform, rt_matrix_4::id_matrix());
}

TEST(sphereTests, sphere_changing_transformation) {
    rt_sphere ref_sphere = rt_sphere(1);
    rt_matrix_4 ref_trans = rt_transformations::translation(2, 3, 4);
    ref_sphere = rt_body::set_transform(ref_sphere, ref_trans);

    EXPECT_TRUE(ref_sphere.transform == ref_trans);
}

TEST(sphereTests, intersecting_scaled_sphere_ray) {
    rt_ray ref_ray = rt_ray(rt_tuple::point(0, 0, -5), rt_tuple::vector(0, 0, 1));
    rt_sphere ref_sphere = rt_sphere(1);
    ref_sphere = rt_body::set_transform(ref_sphere, rt_transformations::scaling(2, 2, 2));

    XSOPT xs_opt = rt_body::intersect(ref_sphere, ref_ray);
    EXPECT_TRUE(xs_opt.has_value());
    rt_body::intersections xs = xs_opt.value();
    EXPECT_EQ(xs.size(), 2);
    EXPECT_TRUE(equal(xs[0].t, 3.0));
    EXPECT_TRUE(equal(xs[1].t, 7.0));
}

TEST(sphereTests, intersecting_translated_sphere_ray) {
    rt_ray ref_ray = rt_ray(rt_tuple::point(0, 0, -5), rt_tuple::vector(0, 0, 1));
    rt_sphere ref_sphere = rt_sphere(1);
    ref_sphere = rt_body::set_transform(ref_sphere, rt_transformations::translation(5, 0, 0));

    XSOPT xs_opt = rt_body::intersect(ref_sphere, ref_ray);
    EXPECT_FALSE(xs_opt.has_value());
}
