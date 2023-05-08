#ifndef SPHERE_H
#define SPHERE_H

#include "hit.hpp"
#include "vec3.hpp"
#include <cmath>

class sphere : public hittable {
    public:
        sphere() {}
        sphere(point3 cen, double r) : center(cen), radius(r) {};

        virtual bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec) const override;

    public:
        point3 center;
        double radius;
};

#endif
