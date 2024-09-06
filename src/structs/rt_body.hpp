#ifndef RT_BODY_H
#define RT_BODY_H

#include "rt_matrix.hpp"
#include "rt_ray.hpp"
#include <optional>
#include <vector>

class rt_sphere {
public:
  rt_tuple origin;
  double radius;
  int id;
  rt_matrix_4 transform;

  rt_sphere(int id)
    : origin{rt_tuple::point(0, 0, 0)},
    radius{1.0},
    id{id},
    transform{rt_matrix_4::id_matrix()} 
  {}
  rt_sphere(rt_sphere sph, rt_matrix_4 trans)
    : origin{sph.origin},
    radius{sph.radius},
    id{sph.id},
    transform{trans} 
  {}
};

namespace rt_body {
// Will have a variant to dispatch the intersection when more body types are added
struct intersection {
  double t;
  const rt_sphere* obj;
};

typedef std::vector<intersection> intersections;

std::optional<intersections> intersect(const rt_sphere sph, const rt_ray ray);
std::optional<intersection> hit(const intersections xs);
rt_sphere set_transform(const rt_sphere sph, const rt_matrix_4 trans_mat);
}
#endif //!RT_BODY_H
