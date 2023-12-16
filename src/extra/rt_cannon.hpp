#ifndef RT_CANNON
#define RT_CANNON

#include <cassert>
#include <cmath>
#include <tuple>
#include "rt_tuples.hpp"

namespace rt_cannon {

class projectile {
public:
    projectile() : position(rt_tuple::point(0, 0, 0)), velocity(rt_tuple::vector(0, 0, 0)) {}
    projectile(const rt_tuple &position, const rt_tuple &velocity) : position(position), velocity(velocity) {
        assert(position.is_point());
        assert(velocity.is_vector());
    }

    rt_tuple get_position() const {
        return position;
    }
    rt_tuple get_velocity() const {
        return velocity;
    }

private:
    rt_tuple position, velocity;
};

class environment {
public:
    environment() : gravity(rt_tuple::vector(0, 0, 0)), wind(rt_tuple::vector(0, 0, 0)) {}
    environment(const rt_tuple &gravity, const rt_tuple &wind) : gravity(gravity), wind(wind) {
        assert(gravity.is_vector());
        assert(wind.is_vector());
    }

    rt_tuple get_gravity() const {
        return gravity;
    }
    rt_tuple get_wind() const {
        return wind;
    }

private:
    rt_tuple gravity, wind;
};

projectile tick(environment env, projectile proj);

}

#endif // !RT_CANNON
