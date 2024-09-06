#ifndef RT_RAY
#define RT_RAY

#include "rt_matrix.hpp"
#include "rt_tuples.hpp"
#include <cassert>

class rt_ray {
public:
  rt_tuple origin;
  rt_tuple direction;

  rt_ray() 
    : origin{rt_tuple::point(0,0,0)}, 
    direction{rt_tuple::vector(0,0,0)} {}

  rt_ray(rt_tuple point, rt_tuple direction)
    : origin{point},
    direction{direction} {
    assert(origin.is_point());
    assert(direction.is_vector());
  }

  static rt_tuple position(rt_ray ray, double t) {
    return ray.origin + ray.direction * t;
  }

  static rt_ray transform(rt_ray ray, rt_matrix_4 transform_mat) {
    return rt_ray{transform_mat * ray.origin, transform_mat * ray.direction};
  }
};

#endif //!RT_RAY
