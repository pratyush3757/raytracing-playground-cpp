#include "hit.hpp"
#include <cmath>

bool is_hitting_sphere(const point3 &center, double radius, const ray &r) {
    vec3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius*radius;
    double discriminant = half_b*half_b - a*c;
    return (discriminant > 0);
}

double hit_point(const point3 &center, double radius, const ray &r) {
    vec3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius*radius;
    double discriminant = half_b*half_b - a*c;
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-half_b - std::sqrt(discriminant) ) /  a;
    }
}
