#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.hpp"

struct hit_record {
    point3 p;
    vec3 normal;
    double t;
};

class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

// bool is_hitting_sphere(const point3& center, double radius, const ray& r);

// double hit_point(const point3& center, double radius, const ray& r);

#endif // !HITTABLE_H
