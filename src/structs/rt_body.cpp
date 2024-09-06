#include "rt_body.hpp"
#include <cmath>
#include <utility>

using rt_body::intersection;
using rt_body::intersections;
using std::vector;

std::optional<intersections> rt_body::intersect(const rt_sphere sph, const rt_ray ray) {
    rt_ray ray2 = rt_ray::transform(ray, rt_matrix_4::inverse(sph.transform));
    rt_tuple sphere_to_ray = ray2.origin - rt_tuple::point(0, 0, 0);
    double a = rt_tuple::dot(ray2.direction, ray2.direction);
    double b = 2 * rt_tuple::dot(ray2.direction, sphere_to_ray);
    double c = rt_tuple::dot(sphere_to_ray, sphere_to_ray) - 1;

    double discriminant = (b * b) - (4 * a * c);
    if(discriminant < 0) {
        return {};
    }

    double t1 = (-b - sqrt(discriminant)) / (2 * a);
    double t2 = (-b + sqrt(discriminant)) / (2 * a);

    if (t2 < t1) {
        std::swap(t1,t2);
    }
    return intersections{intersection{t1, &sph}, intersection{t2, &sph}};
}

std::optional<intersection> rt_body::hit(const intersections xs) {
    intersection const *res = &xs[0];
    for(const intersection &i:xs) {
        if(res->t < 0) {
            res = &i;
        }
        else [[likely]] if(i.t > 0 && i.t < res->t) {
            res = &i;
        }
    }
    if(res->t > 0) {
        return *res;
    } else {
        return {};
    }
}

rt_sphere rt_body::set_transform(const rt_sphere sph, const rt_matrix_4 trans_mat) {
    return rt_sphere{sph, trans_mat};
}
